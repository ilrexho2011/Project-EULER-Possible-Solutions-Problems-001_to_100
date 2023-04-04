/*  Diophantine equation

Problem 66 Consider quadratic Diophantine equations of the form:

x^2 – Dy^2 = 1

For example, when D=13, the minimal solution in x is 6492 – 13×1802 = 1.

It can be assumed that there are no solutions in positive integers when D is square.

By finding minimal solutions in x for D = {2, 3, 5, 6, 7}, we obtain the following:

3^2 – 2×2^2 = 1 2^2 – 3×1^2 = 1 9^2 – 5×4^2 = 1 5^2 – 6×2^2 = 1 8^2 – 7×3^2 = 1

Hence, by considering minimal solutions in x for D ≤ 7, the largest x is obtained when D=5.

Find the value of D ≤ 1000 in minimal solutions of x for which the largest value of x is obtained.

Pergjigja: 661  */

#include <iostream>
#include <vector>
#include <cmath>
#include "gmpxx.h"

using namespace std;

vector< int > cfe( unsigned long d )
{
  long double d2 = sqrtl( d );
  vector< int > e;
  unsigned long a = d2, p = 0, q = 1;
  do {
    e.push_back( a );
    p = a * q - p;
    q = ( d - p * p ) / q;
    a = ( p + d2 ) /q;
  } while ( q != 1 );
  e.push_back( a );
  return e;
}

mpz_class solve_pell( vector< int >& c )
{
  int l = c.size() - 1;
  int per = l % 2 == 0 ? l - 1 :  2 * l - 1;
  mpz_class a = c[ 0 ], a1 = 1, b = 1, b1 = 0, t;
  a = c[ 0 ];
  b = c[ 0 ] * b + b1;
  for ( int i = 1; i <= per; i++ ) {
    t = a;
    a = c[ ( i - 1 ) % l + 1 ] * a + a1;
    a1 = t;
    t = b;
    b = c[ ( i - 1 ) % l + 1 ] * b + b1;
    b1 = t;
  }
  return a;
}

int main()
{
  mpz_class x, maxx = 0;
  int maxd = 0;
  for ( int d = 2; d <= 1000; d++ ) {
    int d2 = sqrt( d );
    if ( d2 * d2 != d ) {
      vector< int > c = cfe( d );
      x = solve_pell( c );
      if ( x > maxx ) {
        maxx = x;
        maxd = d;
      }
    }
  }
  cout << "D = " << maxd << endl;
return 0;
}