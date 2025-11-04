#ifndef MLIR_CONVERSION_CHRISTOARITH_CHRISTOARITH_H
#define MLIR_CONVERSION_CHRISTOARITH_CHRISTOARITH_H

#include <memory>

namespace mlir {

class DialectRegistry;
class LLVMTypeConverter;
class RewritePatternSet;
class Pass;

#define GEN_PASS_DECL_CHRISTOARITHCONVERSIONPASS
#include "mlir/Conversion/Passes.h.inc"

namespace chris {
//void populateChrisToArithConversionPatterns(const LLVMTypeConverter &converter,
//                                           RewritePatternSet &patterns);
//
//void registerConvertChrisToArithInterface(DialectRegistry &registry);
} // namespace arith
} // namespace mlir

#endif // MLIR_CONVERSION_CHRISTOARITH_CHRISTOARITH_
