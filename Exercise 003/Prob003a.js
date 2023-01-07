function  getLargestPrimeFactor (n) {
        var largestPrimeFactor,
            factor = 2;

        while (n > 1) {
            if (n % factor === 0) {
                largestPrimeFactor = factor;
                n = n / factor;
                while (n % factor === 0) {
                    n = n / factor;
                }
            }

            factor += (factor === 2) ? 1 : 2;
        }

        return largestPrimeFactor;
    }

getLargestPrimeFactor(600851475143);
