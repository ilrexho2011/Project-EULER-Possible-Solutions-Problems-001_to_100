function largestPrimeFactOf(n, fac = 2) {
    while (n % fac !== 0 && fac < Math.sqrt(n))
        fac++;
        // in this case it's actually a lot faster to increment by +1, instead of make checks with modulo.
    return fac <= Math.sqrt(n) 
        ? largestPrimeFactOf(n/fac, fac) : n; 
}
largestPrimeFactOf(Number.MAX_VALUE);
