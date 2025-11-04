#include "mlir/Conversion/ChrisToArith/ChrisToArith.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Chris/IR/ChrisOps.h"
#include "mlir/IR/PatternMatch.h"

#include "mlir/Conversion/ConvertToLLVM/ToLLVMInterface.h"
#include "mlir/Conversion/LLVMCommon/ConversionTarget.h"
#include "mlir/Conversion/LLVMCommon/VectorPattern.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Arith/Transforms/Passes.h"
#include "mlir/Dialect/LLVMIR/LLVMAttrs.h"
#include "mlir/Dialect/LLVMIR/LLVMDialect.h"
#include "mlir/IR/TypeUtilities.h"
#include <type_traits>

namespace mlir {
#define GEN_PASS_DEF_CHRISTOARITHCONVERSIONPASS
#include "mlir/Conversion/Passes.h.inc"
} // namespace mlir

using namespace mlir;
using namespace mlir::chris;

struct AddOpPat: OpRewritePattern<AddOp> {
  using OpRewritePattern<AddOp>::OpRewritePattern;
  LogicalResult matchAndRewrite(AddOp op, PatternRewriter & rewriter) const {
    auto inputs = llvm::to_vector(op.getOperands());
    auto result = inputs[0];
    for(size_t i = 1; i< inputs.size(); i++) {
      //result = rewriter.create<arith::AddIOp>(op->getLoc(), result, inputs[i]);
      result = arith::AddIOp::create(rewriter,op->getLoc(), result, inputs[i]);
    }
    rewriter.replaceOp(op, ValueRange(result));
    return success();
  }
};

//===----------------------------------------------------------------------===//
// Pass Definition
//===----------------------------------------------------------------------===//

namespace {
struct ChrisToArithConversionPass
    : public impl::ChrisToArithConversionPassBase<ChrisToArithConversionPass> {
  using Base::Base;

  void runOnOperation() override {
    //getOperation()->print(llvm::errs());
    ConversionTarget target(getContext());
    target.addLegalDialect<arith::ArithDialect>();
    RewritePatternSet patterns(&getContext());
    patterns.add<AddOpPat>(&getContext());
    if(failed(applyPartialConversion(getOperation(), target, std::move(patterns))))
        signalPassFailure();
  }
};
} // namespace

