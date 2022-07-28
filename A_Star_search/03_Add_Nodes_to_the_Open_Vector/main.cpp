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
using std::abs;

enum class State {kEmpty, kObstacle, kClosed};

vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',') {
      if (n == 0) {
        row.push_back(State::kEmpty);
      } else {
        row.push_back(State::kObstacle);
      }
    }
    return row;
}


vector<vector<State>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<State>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  cout<< "board.size() or i:"<<board.size()<<", board[0].size() or j:"<<board[0].size() << "\n";
  return board;
}


string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    case State::kClosed: return "x   ";
    default: return "0   ";
  }
}


void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}

// TODO: Write the Search function stub here.
/*
Search( grid, initial_point, goal_point ) :

    1.Initialize an empty list of open nodes.

    2.Initialize a starting node with the following:
        x and y values given by initial_point.
        g = 0, where g is the cost for each move.
        h given by the heuristic function (a function of the current coordinates and the goal).

    3.Add the new node to the list of open nodes.

    4.while the list of open nodes is nonempty:
        4.1 Sort the open list by f-value and pop the optimal cell (called the current cell).
        4.2 Mark the cell's coordinates in the grid as part of the path.
        4.3 if the current cell is the goal cell:
            return the grid.
        else, expand the search to the current node's neighbors. This includes the following steps:
            Check each neighbor cell in the grid to ensure that the cell is empty: it hasn't been closed and is not an obstacle.
            If the cell is empty, compute the cost (g value) and the heuristic, and add to the list of open nodes.
            Mark the cell as closed.

    5.If you exit the while loop because the list of open nodes is empty, you have run out of new nodes to explore and haven't found a path.
*/

/*
编写一个函数，接收两个int数组作为起始位置和结束位置。
函数打印没有找到轮径，并返回空。
函数之后会返回带有路径的board
*/
vector<vector<State>> Search(vector<vector<State>> grid,int initial_point[2], int goal_point[2] ){

    cout << "No path found!" << "\n";
    return vector<vector<State>> {};

}

/*
编写A*的启发函数
Calculate the manhattan distance
*/
int Heuristic(int x1,int y1,int x2,int y2){
    return abs(x1-x2) + abs(y1-y2);//abs绝对值
}

/*
编写向open vector中增加节点的函数
*/
void AddToOpen(int x,int y,int g,int h,vector<vector<int>> &open_nodes,vector<vector<State>> &grid){
    //创建一个格式为<x y g h>的节点，并pushback
    vector<int> node{x,y,g,h};
    open_nodes.push_back(node);
    grid[x][y]=State::kClosed;
}

#include "test.cpp"

int main(){
    int init[2]{0,0};
    int goal[2]{4,5};
    auto board=ReadBoardFile("1.board");
    auto solution=Search(board,init,goal);
    PrintBoard(solution);
    // Tests
    TestHeuristic();
    TestAddToOpen();
}