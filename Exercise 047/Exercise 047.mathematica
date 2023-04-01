(* 
 * Solution to Project Euler problem 47
 *)


Has4PrimeFactors[n_] := Length[FactorInteger[n]] == 4
i = 2;
While[!(Has4PrimeFactors[i] && Has4PrimeFactors[i+1] && Has4PrimeFactors[i+2] && Has4PrimeFactors[i+3]), i++]
i
