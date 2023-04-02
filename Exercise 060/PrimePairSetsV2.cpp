//	Prime pair sets
/*	The primes 3, 7, 109, and 673, are quite remarkable. 
By taking any two primes and concatenating them in any order 
the result will always be prime. For example, taking 7 and 109, 
both 7109 and 1097 are prime. The sum of these four primes, 792, 
represents the lowest sum for a set of four primes with this property.

Find the lowest sum for a set of five primes for which any two primes 
concatenate to produce another prime. 
My solutions a bit slow. ~7s on my core i7 haswell, 17s on my celeron haswell.

There are 2 groups of primes. One is prime%3==1(G1), the other is prime%3==2(G2).
5 primes of this answer may be all G1 or all G2 (or "3" + 4 G1 / G2 ), because of (G1 concat G2)%3==0.
I tried out the (NOT smart) program for each.
I built a list of lists of valid answers, top level was all primes singularly, 
with a sub-list of primes that paired with those, each of those with a sub-list of primes that paired with BOTH, etc. 

As an added bonus I made it keep going which allowed me to answer a question asked earlier in the thread, 
do we KNOW it's the lowest. Well the results until the new prime being checked exceeds the value 
of the solution and therefore there can't be any more 'lower' values are:

RESULT: 8389, 6733, 5701, 5197, 13: SUM 26033
RESULT: 18433, 12409, 2341, 1237, 7: SUM 34427
RESULT: 25253, 19793, 2099, 941, 467: SUM 48553
RESULT: 31231, 29587, 10357, 5323, 3: SUM 76501

So I think it's safe to say the answer is 'correct'.

Also for added masochism I upped the depth value by 1 to see if I could find a 6-prime set.....
Got bored after about 10 minutes of no result.

(is_prime and next_prime are common functions which do the expected)

Pergjigja e sakte eshte: 26033	*/

#include <iostream>
#include <vector>
#include <map>

struct Set {
    std::vector<int> members;
    Set(int m) {
        members.push_back(m);
    }
};

bool is_concat_prime(int a, int b)
{
    static std::map<std::pair<int,int>, bool> mem;
    if( b < a)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    std::pair<int, int> p = std::make_pair(a,b);
    std::map<std::pair<int,int>, bool>::iterator it = mem.find(p);
    if(it != mem.end())
        return it->second;
    bool result = false;
    if(is_prime(concatenate(a, b)) && is_prime(concatenate(b, a)))
        result = true;
    mem[std::make_pair(a, b)] = result;
    return result;
}

int main(int argc, char** argv)
{
    std::vector<Set> sets;
    sets.push_back(Set(3));

    if(argc < 2)
    {
        std::cout << "Argument required" << std::endl;
        return 1;
    }
    const int target = std::stoi(argv[1]);
    int p = 3;
    bool valid;
    bool running = true;
    Set result(0);
    while(running)
    {
        p = next_prime(p);
        for(int i = 0; i < sets.size(); i++)
        {
            Set &s = sets[i];
            valid = true;
            for(int j = 0; j < s.members.size(); j++)
            {
                if(!is_concat_prime(p, s.members[j]))
                {
                    valid = false;
                    break;
                }
            }
            if(valid)
            {
                Set c = s;
                c.members.push_back(p);
                sets.push_back(c);
                if(c.members.size() == target)
                {
                    result = c;
                    running = false;
                    break;
                }
            }
        }
        sets.push_back(Set(p));
    }
    int sum = 0;
    for(int i : result.members)
    {
        std::cout << i << " ";
        sum += i;
    }
    std::cout << std::endl;
    std::cout << sum << std::endl;
}
