#ifndef MAZEGAME_H
#define MAZEGAME_H
#include<string>
#include<vector>
#include<stack>
using namespace std;

class MazeGame {
private:
    int length, width;
    vector<vector<int>> maze;  // 用二维数组存储迷宫，0代表墙，1代表路
    
    int playerX,playerY; //玩家当前位置

public:
    // 构造函数，构造迷宫的大小
    MazeGame(int l,int w);

    //生成迷宫
    void generate();

    //核心：DFS算法挖路
    void dfs(int x, int y);

    //打印迷宫
    void print();
    void printColor();

    //玩家移动逻辑实现
    int move(char direction);

    //获取玩家位置
    int getPlayerX() const { return playerX; }
    int getPlayerY() const { return playerY; }

    bool win();


    //自动寻路逻辑实现
    struct Point{
        int x,y;
        bool operator==(const Point &other){
            return x == other.x && y == other.y;
        }
    };
    void autoSolve();
};
#endif