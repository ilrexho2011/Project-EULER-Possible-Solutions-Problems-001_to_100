#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int sum = 0;
    vector<string> names;
    char name[50], junk[5];
    string str;
    ifstream inFile;
    inFile.open("names.txt");

    while(!inFile.eof()) {
        inFile.getline(junk, 50, '/"');
        inFile.getline(name, 50, '/"');
        stringstream sstr;
        sstr << name;
        sstr >> str;
        names.push_back(str);
    }

    sort(names.begin(), names.end());

    for(int i=0; i<names.size(); i++) {
        int namesum = 0;
        for(int j=0; j<names[i].size(); j++)
            namesum += (names[i][j] - 64);
        sum += (namesum*i);
    }

    cout << "Sum: " << sum << endl;
    return 0;
}
