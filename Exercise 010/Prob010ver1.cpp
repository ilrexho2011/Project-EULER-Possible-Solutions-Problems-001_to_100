/*----------------------------------------------------------
	Shuma e numrave Prim poshte 10 eshte 2 + 3 + 5 + 7 = 17.
	Gjeni shumen e numrave Prim poshte vleres 2 milion.
	Pergjigja e sakte eshte 142913828922
	--------------------------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
	// Ne kete vektor ruhen vlera logjike ne varesi te vetise Prim.
    vector <bool> shenja_prim(2000000,true);
shenja_prim[1] = false;
    for(int i = 2; i*i < shenja_prim.size(); ++i){
        if(shenja_prim[i]==true){
            for(int j = 0; i*i+j*i < shenja_prim.size(); ++j){
                    shenja_prim[i*i+j*i] = false;
            }
        }
    }
	// Ne kete pjese mblidhen vetem numrat me index true
    long long shuma = 0;
    for(int k = 1; k < shenja_prim.size(); k++){
        if(shenja_prim[k] == true)
            shuma +=k;
    }
    cout << "Shuma = " << shuma;
return 0;
}
