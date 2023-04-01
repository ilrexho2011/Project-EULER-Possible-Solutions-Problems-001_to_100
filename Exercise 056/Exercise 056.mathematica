(* 
 * Solution to Project Euler problem 56
 *)


Max[Flatten[Table[Total[IntegerDigits[a^b]], {a, 100}, {b, 100}]]]
