#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

//function by jesyspa
std::vector<int> split(std::string line){
    std::stringstream ss (line);
    std::vector<int> result;
    std::string num;
    while(std::getline(ss, num, ','))
        result.push_back(std::stoi(num));
    return result;
}
int main(){

    std::vector<std::vector<int>> grid;

    //inputing triangle fule
    std::ifstream nums;
    nums.open("triangle.txt");
    std::string row;
    //Calling function, and pushing back into the vector
    while(std::getline(nums, row, '\n')){
        grid.push_back(split(row));
    }
    //term is one shorter then grid
    int term = grid.back().size() - 1;

    //This loop add's the larger of two bottom numbers, with the number above the first of the two.
    for(int a = term; a >= 1; a--){
        for(int b = 0; b <= a; b++){
            if(grid[a][b] > grid[a][b+1]){
                grid[a-1][b] += grid[a][b];
            }
            else{
                grid[a-1][b] += grid[a][b+1];
            }
        }
    }
    //Our answer
    std::cout << grid[0][0];
}
