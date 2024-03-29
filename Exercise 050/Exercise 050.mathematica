(* 
 * Solution to Project Euler problem 50
 *)


lim = 10^6;

bestLen = 0;
bestSum = 0;
For[i = 1, Prime[i] < lim, i++,
  For[s = 0; j = i, (s += Prime[j]) < lim, j++,
    If[PrimeQ[s] && j - i + 1 > bestLen,
      bestLen = j - i + 1;
      bestSum = s]]]
bestSum
