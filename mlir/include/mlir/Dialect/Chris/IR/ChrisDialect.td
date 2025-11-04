#ifndef CHRIS_DIALECT
#define CHRIS_DIALECT

include "mlir/Interfaces/DataLayoutInterfaces.td"
include "mlir/IR/AttrTypeBase.td"
include "mlir/IR/BuiltinTypeInterfaces.td"
include "mlir/IR/OpBase.td"


def ChrisDialect : Dialect {
  let name = "chris";
  let summary = "chris dialect";
  let description = [{
    toy
  }];
  let cppNamespace = "::mlir::chris";
}

#endif
