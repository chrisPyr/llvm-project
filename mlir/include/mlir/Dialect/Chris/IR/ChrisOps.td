include "mlir/IR/OpBase.td"
include "mlir/Dialect/Chris/IR/ChrisDialect.td"
include "mlir/Interfaces/SideEffectInterfaces.td"

class ChrisOp<string mnemonic, list<Trait> traits = []>: //menemonic = operation name
 Op<ChrisDialect, mnemonic, traits>;

 def AddOp : ChrisOp<"ChrisAdd", [Pure]>{ // Pure trait can be applied with cse dse
   let summary = "add";
   let arguments = (ins AnyInteger:$lhs, AnyInteger:$rhs);
   let results = (outs AnyInteger:$result);
   let hasVerifier = true;
//   let assemblyFormat = "$lhs attr-dict`,` $rhs `:` type($lhs)`,` type($rhs) `->` type($result)";
   }

 def RetOp : ChrisOp<"ChrisReturn", [Terminator]>{ // Terminator trait prohibit some optimizations e.g. code motion
   let summary = "return";
   let arguments = (ins Optional<AnyInteger>:$data);
   }
