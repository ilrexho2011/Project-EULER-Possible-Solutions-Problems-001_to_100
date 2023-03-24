#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
int main(int argc, const char * argv[]) {
	int min = 2;
	int max = 100;
	std::vector<double> numbers;
	for(int a = min; a <= max; a++){
		for(int b = min; b <= max; b++){
			numbers.push_back(pow(a, b));
		}
	}
	std::sort(numbers.begin(), numbers.end());
	numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
	std::cout<<numbers.size()<<" distinct terms."<<std::endl;
	return 0;
}
