add_mlir_dialect_library(MLIRChrisDialect
  Chris.cpp

  ADDITIONAL_HEADER_DIRS
  ${MLIR_MAIN_INCLUDE_DIR}/mlir/Dialect/Chris

  LINK_LIBS PUBLIC
  MLIRCallInterfaces
  MLIRControlFlowInterfaces
  MLIRFunctionInterfaces
  MLIRDialect
  MLIRInferTypeOpInterface
  MLIRIR
  )
