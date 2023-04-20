/*   Right triangles with integer coordinates
 
Problem 91
The points P (x1, y1) and Q (x2, y2) are plotted at integer co-ordinates and are joined to the origin, O(0,0), to form ΔOPQ.


There are exactly fourteen triangles containing a right angle that can be formed when each co-ordinate lies between 0 and 2 inclusive; that is,
0 ≤ x1, y1, x2, y2 ≤ 2.


Given that 0 ≤ x1, y1, x2, y2 ≤ 50, how many right triangles can be formed?


Answer:  14234   */

#include <set>
#include <iostream>

using namespace std;

set<set<int> > result;

int main()
{
    int x1,y1,x2,y2;

    int n = 50;

    for (x1=0; x1 <= n; ++x1)
    {
        for (y1=0; y1 <= n; ++y1)
        {
            for (x2=0; x2 <= n; ++x2)
            {
                for (y2=0; y2 <= n; ++y2)
                {
                    int dist01 = x1*x1 + y1*y1;
                    int dist02 = x2*x2 + y2*y2;
                    int dist12 = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
                    if (dist01==0 || dist02==0 || dist12==0) continue;

                    if ((dist12 > dist02 && dist12 > dist01 && dist12 == dist02 + dist01) ||
                        (dist01 > dist02 && dist01 > dist12 && dist01 == dist02 + dist12) ||
                        (dist02 > dist01 && dist02 > dist01 && dist02 == dist12 + dist01))
                    {
                        set<int> aSet;
                        aSet.insert(x1*(n+1) + y1);
                        aSet.insert(x2*(n+1) + y2);
                        result.insert(aSet);
                    }
                }
            }
        }
    }
    cout << "result : " << result.size() << endl;
}