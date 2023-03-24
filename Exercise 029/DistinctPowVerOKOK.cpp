#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <set>

typedef boost::multiprecision::cpp_int bigint;

int main()
{
	std::set<bigint> combos;
	for (auto a = 2u; a <= 100; ++a)
	{
		bigint result = a;
		for (auto b = 2u; b <= 100; ++b)
		{
			result *= a;	
			combos.insert(result);
		}
	}
	std::cout << combos.size() << std::endl;	
}
