//  Factori me i madh Prim i nje numri
//  Cdo numer natyror mund te perftohet si produkt i faktoreve
//  te cilet jane te gjithe numra Prim
//  Faktoret Prim te numrit 13195 jane 5, 7, 13 dhe 29.
//  Cili eshte faktori me i madh prim per numrin 600851475143 ?

#include <iostream>
using namespace std;

inline bool prim(const __int64 nr)
{
	static __int64 i;
	if(!(nr % 2))
		return false;
	for(i = 3; i*i <= nr; i += 2)
		if(!(nr % i))
			return false;
	return true;
}

int main()
{
	const __int64 nr = 600851475143;
	__int64 max = 0;
	for(__int64 i = 3; i*i <= nr; i += 2)
	{
		if(!(nr % i))
			if(prim(i))
				max = i;
	}
	cout << max;
	return 0;
}
