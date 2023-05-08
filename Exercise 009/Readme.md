
Problem 9. Find the only Pythagorean triplet
(a, b, c), for which a + b + c = 1000.

Or, equivalently, find all Pythagorean triplets (a, b, c)  with  a + b + c =  1000. The value 1000 is of course arbitrary, so we discuss the more general problem of finding all Pythagorean triplets with a + b + c = s for some   s.
It can easily be seen that for every Pythagorean triplet a ?: 3 and a + b + c is
even, you might want to prove that  yourself.

9.1	The  straightforward approach

The most straightforward approach is to simply loop over a and b and then check whether a2 + b2  = (s − a − b)2.  From the condition a < b < c, we conclude that
a � (s − 3)I	(s − a)I
That approach would lead to code along the lines of

This algorithm is sufficiently fast for small enough s, but it doesn’t scale well.  If you multiply the value of s by a factor k, the span of each of the two loops   is multiplied by the same factor and since the loops are nested, the number of cases to check is multiplied by k2. So if s is doubled, the programme takes approximately four times as long and increasing the perimeter s by a factor of 10 increases the run time by a factor of approximately  100.
With a little work, you can find better bounds for the loops, thus considerably speeding the algorithm up, but it will still have the same scaling behaviour.  This
algorithm is definitely unsuitable for perimeters s   ?: 1 000 000.

9.2	Using a parametrisation of Pythagorean triplets

A Pythagorean triplet (a, b, c) is by definition primitive if gcd(a, b, c) = 1. Since for Pythagorean triplets one has gcd(a, b) = gcd(b, c) = gcd(c, a), such a triplet

is primitive if and only if gcd(a, b) = 1. As was already known to the ancient Greeks, all primitive Pythagorean triplets can be represented  as
(9.1)	a = m2 − n2,   b = 2 · m · n,   c = m2 + n2,
with m > n > 0, perhaps exchanging a and b to have a < b. These formulae always produce a Pythagorean triplet, but it will be primitive if and only if exactly one of m, n is even and gcd(m, n) = 1.
From any Pythagorean triplet you get a primitive one by dividing out the greatest common divisor, so every Pythagorean triplet has a unique representation
(9.2)	a = (m2 − n2) · d,   b = 2 · m · n · d,   c = (m2 + n2) · d,
with m > n > 0, gcd(m, n) = 1 and exactly one of m, n even – d is the greatest common divisor of a, b and c.
Using that parametrisation we  see
(9.3)	a + b + c = 2 · m · (m + n) · d.
So to find a Pythagorean triplet (a, b, c) with a + b + c = s, we have to find a
 
divisor m (> 1) of sI
 
and an odd divisor k (= m + n) of sI
 
with m < k < 2m
 
2	I	2m
and gcd(m, k) = 1. Then set n = k − m, d = s 2mk and plug these into (9.2).
A fairly simple implementation of that algorithm might look like


where is the ceiling function, i.e. x is the smallest integer i ?: x. This implementation is rather fast and scales well, s � 1010 are processed in fractions of a second.  However, at the expense of more complicated code, it can still   be
improved a bit by making use of the primefactorisation of sI .

9.3	The parametrisation of Pythagorean triplets

9.3.1	Verification of the conditions for primitive triplets

Let us repeat the conditions:
The Pythagorean triplet (a, b, c) = (m2 − n2, 2mn, m2 + n2), m > n > 0 is primitive if and only if gcd(m, n) = 1 and exactly one of m and n is even.
If gcd(m, n) = d > 1, then obviously d2  is a common divisor of a, b and c, and   if
m and n are both odd, a, b and c are all even, so the conditions are necessary.
On the other hand, if exactly one of m and n is even and the triplet is  not primitive, let p be a prime dividing a, b and c.  Since a and c are odd, so is p.    Any odd prime dividing b must divide at least one of m and n, say p divides m. Then p also divides m2. But as p also divides c = m2 + n2, p divides n2 (and n), too.  From  that follows gcd(m, n) > 1 and thus the sufficiency of the    conditions.

9.3.2	Derivation of the parametrisation
Let T  = (a, b, c) be a Pythagorean triplet and x = aI , y = bI .  Then (x, y) is a
c	c
point on the unit circle with rational coordinates and all triplets obtained from
T   by  multiplying  a,  b  and  c  with  the  same  rational  number—and  only  these—
 
will lead to the same point.  Conversely, if x = pI , y = rI
 
are positive rational
 
q	q
numbers with x2 + y2 = 1, then (p, r, q) is a Pythagorean triplet (not necessarily
with a < b). Now consider a straight line with positive slope s passing through (0, −1). A parametrisation of that line is given by (t, s · t− 1), t ∈ R. The second point of intersection of that line and the unit circle is obtained by solving the equation
(9.4)	t2 + (s · t − 1)2 = 1.
Rearranging  this  equation  leads  to  (s2  + 1) · t2   =  2st.   The  nonzero solution
 
is  thus  t1  =  (2s)I  2
2
 
+ 1)
 
and the intersection then has coordinates x = t1     and
 
y = s · t1 − 1 = (s
 
1)I
(s2
 
+ 1)
 
.  It can be seen that both coordinates are rational
 
and positive if and only if s is rational and greater than 1.  So if s = mI
 
with
 
m > n > 0 then x = (2mn)I	2
 
2  ,  y = (m2 − n2)I	2
 
2   and we  obtain
 
(m  + n )	(m  + n )
the Pythagorean triplet (a, b, c) = (2mn, m2 − n2, m2 + n2).
 


If we start with a primitive triplet (a, b, c), the slope of the line passing through
 
(0, −1) and  aI , bI ) is (b + c)I
 
= mI , where the second is the reduced form, i.e.
 
c	c	a	n
gcd(m, n) = 1.  Then T = (2mn, m2 − n2, m2 + n2) is a multiple of (a, b, c).
If m and n have  different parity,  we’re done, because then T  is also primitive as  we saw above, therefore it follows that T =  (a, b, c).
If m and n are both odd, let u = (m + n)I , v = (m − n)I .  Since m and   n
2	2
are odd and m = u + v, n = u − v, one of u and v is even, the other odd, and
gcd(u, v) = 1. Further
2mn = 2(u + v)(u − v) = 2(u2 − v2)
⇒ mn = u2 − v2,
m2 − n2 = (u2 + 2uv + v2) − (u2 − 2uv + v2) = 4uv
 
(9.5)
 
m2	n2
= 2uv,
2
 
m2 + n2 = (u2 + 2uv + v2) + (u2 − 2uv + v2) = 2(u2 + v2)
 
m2 + n2
= u2
2
 
+ v2,
 
so T1  = (u2 − v2, 2uv, u2 + v2) is a primitive triplet which is also a multiple of   (a, b, c), hence T1 = (a, b, c).
