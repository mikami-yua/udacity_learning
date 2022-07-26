/*
Formatting the Printed Board
0   ⛰️   0   0   0   0
0   ⛰️   0   0   0   0
0   ⛰️   0   0   0   0
0   ⛰️   0   0   0   0
0   0    0   0  ⛰️   0

随着程序的复杂化，电路板最终会有两个以上的状态。
而且随着板子状态数量的增加，最好能给板子的打印输出添加格式化，以确保可读性。
为了适应更多的电路板状态并方便打印格式化，我们提供了状态枚举器的值kEmpty和kObstacle
在这个练习中。
你将编写一个CellString函数，将每个状态转换为一个适当的字符串。
在下一个练习中，我们将更新程序以使用枚举值和CellString函数。
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State {kEmpty, kObstacle};

vector<int> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<int> row;
    while (sline >> n >> c && c == ',') {
      row.push_back(n);
    }
    return row;
}

//从带有逗号的文件中获得vector矩阵
vector<vector<int>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<int>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<int> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}

// TODO: Create the CellString function here,
// using the following return strings:
// "⛰️   "
// "0   "

string CellString(State cell){

    switch(cell){
        case State::kEmpty:
                return "0   ";
        case State::kObstacle:
                return "⛰️   ";
        default:
            return " ";
    }

}

vector<vector<string>> ResetBoard(const vector<vector<int>> board){
    vector<vector<string>> ans;
    for (int i = 0; i < board.size(); i++)
    {
        vector<string> line;
        for (int j = 0; j < board[i].size(); j++)
        {           
            string cell;
            if (board[i][j]==0)
            {
                cell=CellString(State::kEmpty);
            }else{
                cell=CellString(State::kObstacle);
            }
            line.push_back(cell);
        }
        ans.push_back(line);
    }
    return ans;
}


void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

void PrintBoard(const vector<vector<string>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

int main() {
  auto board = ReadBoardFile("1.board");
  PrintBoard(board);
  cout<<"你好世界"<<"\n";
  //得到了board
  auto string_board=ResetBoard(board);
  PrintBoard(string_board);
}
