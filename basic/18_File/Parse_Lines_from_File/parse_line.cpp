#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::string;
using std::vector;

//for String stream to INT
#include <sstream>
using std::istringstream;

//Add the ParseLine function here.
vector<int> ParseLine(const string line){
    vector<int> rst;
    istringstream myreader(line);
    char c;
    int n;
    while (myreader>>n>>c)
    {
        rst.push_back(n);
    }
    return rst;
}

//Read file function here
vector<vector<int>> ReadBoardFile(string path){
    ifstream myfile(path);
    vector<vector<int>> ans;
    if (myfile)
    {
        string line;
        while (getline(myfile, line))
        {
            vector<int> sub_ans=ParseLine(line);
            ans.push_back(sub_ans);
            cout<<line<<"\n";
        }
        return ans;   
    }else{
        return ans;
    }    
}

//Print board function here
void PrintBoard(const vector<vector<int>> board){
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    
}




#include "test.cpp"

int main() {
    vector<vector<int>> board;
    board=ReadBoardFile("1.board");
  //TestParseLine(); // For testing.
  // Leave commented out.
    PrintBoard(board);

  //PrintBoard(board);
}