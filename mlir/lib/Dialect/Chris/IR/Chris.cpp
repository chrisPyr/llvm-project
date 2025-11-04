#include "mlir/Dialect/Chris/IR/ChrisDialect.h"
#include "mlir/Dialect/Chris/IR/ChrisOps.h"

#include "mlir/IR/DialectImplementation.h"
#include "mlir/Interfaces/FunctionImplementation.h"
#include "llvm/ADT/TypeSwitch.h"

using namespace mlir;
using namespace mlir::chris;

#include "mlir/Dialect/Chris/IR/ChrisDialect.cpp.inc"
#define GET_OP_CLASSES
#include "mlir/Dialect/Chris/IR/Chris.cpp.inc"

void ChrisDialect::initialize() {
  addOperations<
  #define GET_OP_LIST
  #include "mlir/Dialect/Chris/IR/Chris.cpp.inc"
    >();
}

LogicalResult  AddOp::verify(){
  if (getLhs().getType() != getRhs().getType()){
    return this->emitError() << "Type not match";
  }
  return success();
}
