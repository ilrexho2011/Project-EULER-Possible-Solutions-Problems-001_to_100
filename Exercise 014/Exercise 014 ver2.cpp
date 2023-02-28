#include <iostream>

using namespace std;

int main()
{
    long long starting_num = 0; //Answer variable;
    long long chain_length_p = 0; //Previous chain length
    long long chain_length_c = 1; //Current chain length <-- increases in the loop
    long long current_term = 0; //Current term
    
    for(int i = 14; i<1000000; i++)
    {
        current_term = i; //Set the current term to i;
        while(current_term > 1) //Continue looping and finding terms until its 1
        {
            if(current_term%2 == 0) 
            {
                current_term = current_term/2; //Use the this formula if current term is even
                chain_length_c++; //Increase chain length
            }
            else 
            {
                current_term = (3*current_term)+1; //Use this formula if current term is odd
                chain_length_c++; //Increase chain length
            }
        }
        if(chain_length_c > chain_length_p) //If current chain length is greater then the older one
        {
            chain_length_p = chain_length_c; //Set the older chain length to the newer
            starting_num = i; //Set the starting num to i
        }
        
        chain_length_c = 1; //Set current chain length to 1
    }
    
    cout << starting_num << " as starting num produces a chain of length: " << chain_length_p << endl; //Display result
    
    return 0;
}
