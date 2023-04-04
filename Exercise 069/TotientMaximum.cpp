/*  Totient maximum
Answer:  510510  */

#define _LARGEFILE_SOURCE
#define _LARGEFILE64_SOURCE
#define _FILE_OFFSET_BITS 64
#define _STDC_LIMIT_MACROS
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <utility>
#include <unistd.h>
#include <fcntl.h>
#include <omp.h>
#include <iostream>
#include <iomanip>
#include <tr1/cstdint>
#include <sys/mman.h>

void factor (std::deque<std::pair<uint64_t, uint64_t> > &factors, uint64_t number, uint64_t *primes, const size_t numprimes)
{
    size_t i = 0;
    factors.clear ();
    while (i < numprimes && primes [i] <= number && number > 1)
    {
	if (number % primes [i]) ++ i;
	else
	{
	    size_t j = 0;
	    while (!(number % primes [i]))
	    {
		number /= primes [i];
		++j;
	    }
	    factors.push_back (std::pair<uint64_t, uint64_t> (primes [i], j));
	}
    }
}

int main ()
{
    const size_t size = 1 << 30;
    int fd = open ("primes.bin", O_RDONLY | O_LARGEFILE);
    uint64_t *primes = reinterpret_cast<uint64_t *> (mmap (NULL, size * sizeof (*primes), PROT_READ, MAP_SHARED, fd, 0));

    if (primes == MAP_FAILED)
    {
	perror ("mmap");
	exit (1);
    }

    int n_cand = 0;
    double max_n_over_phi = 0.0;

    #pragma omp parallel for schedule (dynamic, 10000)
    for (int num = 2; num <= 1000000; ++num)
    {
	std::deque<std::pair<uint64_t, uint64_t> > factors;
	factor (factors, num, primes, size);
	double n_over_phi = 1.0;
	for (std::deque<std::pair<uint64_t, uint64_t> >::iterator i = factors.begin ();
	     i != factors.end (); ++i)
	    n_over_phi *= i->first / static_cast<double>(i->first - 1);
	if (n_over_phi > max_n_over_phi)
	{
	    #pragma omp critical (max)
	    {
		max_n_over_phi = n_over_phi;
		n_cand = num;
	    }
	}
    };

    std::cout << "Answer: " << n_cand << std::endl;
    
    munmap (primes, size * sizeof (*primes));
    close (fd);
    
    return 0;
}