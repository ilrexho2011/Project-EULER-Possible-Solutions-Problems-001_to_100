(* 
 * Solution to Project Euler problem 64
 *)


Length[Select[Range[10000], Function[x, !IntegerQ[Sqrt[x]] && OddQ[Length[Last[ContinuedFraction[Sqrt[x]]]]]]]]
