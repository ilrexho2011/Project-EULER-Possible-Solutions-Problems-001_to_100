(* 
 * Solution to Project Euler problem 57
 *)


CountDigits[n_] := Length[IntegerDigits[n]]
ContFrac[n_] := FromContinuedFraction[ContinuedFraction[Sqrt[2], n]]
NumExceedDenomQ[n_] := CountDigits[Numerator[ContFrac[n]]] > CountDigits[Denominator[ContFrac[n]]]
Length[Select[Range[2, 1001], NumExceedDenomQ]]
