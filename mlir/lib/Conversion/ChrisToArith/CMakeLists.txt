add_mlir_conversion_library(MLIRChrisToArith
  ChrisToArith.cpp

  ADDITIONAL_HEADER_DIRS
  ${MLIR_MAIN_INCLUDE_DIR}/mlir/Conversion/ChrisToArith

  DEPENDS
  MLIRConversionPassIncGen

  LINK_COMPONENTS
  Core

  LINK_LIBS PUBLIC
  MLIRArithDialect
  MLIRArithTransforms
  MLIRLLVMCommonConversion
  MLIRLLVMDialect
  )
