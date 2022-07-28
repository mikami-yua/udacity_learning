#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::abs;
using std::sort;

// TODO: Add kStart and KFinish enumerators to the State enum.
enum class State {kStart, kFinish, kEmpty, kObstacle, kClosed, kPath};

// directional deltas, up,left,down,right
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

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
      case State::kPath: return "🚗   ";
      case State::kEmpty: return "E   ";
      case State::kClosed: return "C   ";
      case State::kStart: return "🚦   ";
      case State::kFinish: return "🏁   ";
      default: return "?   ";
    // TODO: Add cases to return "🚦   " for kStart
    // and "🏁   " for kFinish.

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

/*
编写比较函数
比较两个节点的f值并返回较小的那个节点
*/
bool Compare(vector<int> &node1,vector<int> &node2){
    return (node1[2]+node1[3] > node2[2]+node2[3]);
}

/*
编写降序函数
将二位向量降序排列
*/
void CellSort(vector<vector<int>> *v){
    sort(v->begin(),v->end(),Compare);
}

/*
编写函数检测邻居
检测单元格是不是障碍物
1.检测是不是再表格的定义域
2.检测单元格是不是empty状态
*/
bool CheckValidCell(int x,int y,vector<vector<State>> &grid){
    if (x>=0 && x<grid.size() && y>=0&& y<grid.size())
    {
        if (State::kEmpty==grid[x][y])
        {
            return true;
        }
        
    }
    return false;
}

/*
编写函数扩展当前节点
1.获取当前节点
2.循环浏览当前节点的所有邻居
3.检测邻居是否在网格上
4.递增g值，计算h值，并将邻居添加到open vector
input:
reference of ...
    The current node,
    the open vector,
    the grid, and
    an int array for the goal coordinates.
*/
void ExpandNeighbors(vector<int> &cur_node,int *goal,vector<vector<int>> &open_vector,vector<vector<State>> &gird){

    //获取当前节点的数据
    int cur_x=cur_node[0];
    int cur_y=cur_node[1];
    int cur_g=cur_node[2];
    int cur_h=cur_node[3];
    int new_g=cur_g+1;
    cout << __func__ << ", cru x:"<<cur_x<<", cur y:"<<cur_y<<"\n";

    //循环当前节点的所有潜在邻居
    for(int i=0;i<4;i++){
        int poetential_x=cur_x+delta[i][0];
        int poetential_y=cur_y+delta[i][1];

        //检测当前邻居是否在表上，且是否可达
        // if the point is State::kEmpty (which means not kObstcal, kPath)
        if(CheckValidCell(poetential_x,poetential_y,gird)){
            //递增g值，计算h值，并将邻居添加到open vector
            int new_h=Heuristic(poetential_x,poetential_y,goal[0],goal[1]);
            cout<< poetential_x<<poetential_y<<goal[0]<<goal[1]<<new_g<<new_h<<"\n";
            AddToOpen(poetential_x,poetential_y,new_g,new_h,open_vector,gird);
        }

    }
}

/*
编写一个函数，接收两个int数组作为起始位置和结束位置。
实现A*搜索
*/
vector<vector<State>> Search(vector<vector<State>> grid,int initial_point[2], int goal_point[2] ){
    //创建open向量
    vector<vector<int>> open {};

    //TODO:初始化开始节点
    int x=initial_point[0];
    int y=initial_point[1];
    int g=0;
    int h=Heuristic(x,y,goal_point[0],goal_point[1]);
    
    //TODO:使用AddToOpen函数将起始节点添加到向量中
    // We immediately treat the init node as the first open node
    AddToOpen(x,y,g,h,open,grid);

    /*
    实现while循环
        当open向量为非空时{
            1.使用CellSort对开放列表进行排序，并获得当前节点
            2.从当前节点获取x和y值
            3.并将grid[x][y]设置为kPath
            4.检查是否已经达到目标。如果是，则返回grid
            5.如果还没有完成，将搜索范围扩大到当前节点的邻居。这一步将在后面的测验中完成。
        }
    */
   while (open.size()>0)
   {
        //sort all open list by f value
        CellSort(&open);
        //get the min f value node, the node is where we will go
        //because the Compare get the decending order , the lastest node is the min-f node
        vector<int> curminfnode=open.back();
        open.pop_back();
        int cur_x=curminfnode[0];
        int cur_y=curminfnode[1];
        grid[cur_x][cur_y]=State::kPath;

        if (cur_x==goal_point[0] && cur_y==goal_point[1])
        {
            return grid;
        }
        // If we're not done, expand search to current node's neighbors.
        ExpandNeighbors(curminfnode,goal_point,open,grid);
   }
   
    // We've run out of new nodes to explore and haven't found a path.
    cout << "No path found!" << "\n";
    return vector<vector<State>> {};

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
    TestCompare();
    TestSearch();
    TestCheckValidCell();
    TestExpandNeighbors();
    TestExpandNeighbors();
}