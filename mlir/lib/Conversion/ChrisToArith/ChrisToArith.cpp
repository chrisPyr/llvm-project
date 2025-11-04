#include "mlir/Conversion/ChrisToArith/ChrisToArith.h"

#include "mlir/Conversion/ArithCommon/AttrToLLVMConverter.h"
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


//===----------------------------------------------------------------------===//
// Pass Definition
//===----------------------------------------------------------------------===//

namespace {
struct ChrisToArithConversionPass
    : public impl::ChrisToArithConversionPassBase<ChrisToArithConversionPass> {
  using Base::Base;

  void runOnOperation() override {
    getOperation()->print(llvm::errs());
  }
};
} // namespace

