#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "MazeGame.h"
#include<iostream>
#include <cstdlib>
#include <ctime>
#include<windows.h>
#include<conio.h>
#include<queue>
#include<vector>
#include<stack>
using namespace std;


MazeGame::MazeGame(int l, int w):playerX(1),playerY(1){
    // 保证迷宫的长和宽是奇数
    length = (l % 2 == 0) ? l + 1 : l;
    width = (w % 2 == 0) ? w + 1 : w;

    // 创建二维数组，所有位置初始化为0（墙）
    maze.resize(width, vector<int>(length, 0));
}

//生成迷宫
void MazeGame::generate(){
    srand((unsigned int)time(NULL));  // 时间种子
    dfs(1,1);
    maze[width - 2][length - 2] = 2;//设置终点
}

//利用dfs挖路
void MazeGame::dfs(int x, int y){
    //首先先将新跳到的位置设置为路（1）
    maze[x][y] = 1;

    //矩阵移动，创建四个方向的向量，每个向量两个单位长度
    //右移：0,+2  左移：0,-2  上移：-2,0  下移：+2,0
    int dx[4] = {0,0,-2,2};
    int dy[4] = {2,-2,0,0};
    int pos[4] = {0,1,2,3};

    //打乱pos索引的顺序，利用rand，保证移动方向的随机性
    for(int i=0;i<4;i++){
        int r = rand() % 4;
        swap(pos[i],pos[r]);
    }

    for(int t=0;t<4;t++){//错误修改：rand改为for，因为要遍历所有方向
        int nx = x + dx[pos[t]];
        int ny = y + dy[pos[t]];
        //判断移动位置是否合法，合法就挖
        if(nx>=1&&ny>=1&&nx<=width-2&&ny<=length-2&&maze[nx][ny]==0){
            //中间跳过的位置挖为路
            maze[(nx+x)/2][(ny+y)/2] = 1;
            //在新的位置继续去挖
            dfs(nx,ny);
        }
    }
    
}

//打印迷宫
void MazeGame::print() {
    // 获取标准输出句柄
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    // 隐藏光标以减少闪烁感（可选优化）
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    // 将光标重置到左上角 (0,0)，避免使用 system("cls") 导致的黑屏闪烁
    COORD coord = { 0, 0 };
    SetConsoleCursorPosition(hConsole, coord);

    // 记录当前正在使用的颜色，初始化为一个不存在的颜色值(99)，强制第一次循环设置颜色
    WORD currentActiveColor = 99; 

    // 遍历迷宫的行
    for (int i = 0; i < width; i++) {
        // 用于临时存放当前行中“颜色相同”的一段字符，实现批量写入
        std::wstring lineBuffer = L"";
        
        // 遍历当前行的每一列
        for (int j = 0; j < length; j++) {
            wchar_t cellChars[3] = { L' ', L' ', L'\0' };
            WORD cellColor;

            // 1. 优先级最高：判定是否为玩家位置
            if (i == playerX && j == playerY) {
                cellChars[0] = L'☻'; cellChars[1] = L' '; // 玩家图标
                cellColor = 11; // 蓝色
            } 
            // 2. 判定是否为墙壁
            else if (maze[i][j] == 0) {
                cellChars[0] = L'▓'; cellChars[1] = L'▓'; // 墙壁使用两个宽字符凑成正方形
                cellColor = 8; // 灰色
            } 
            // 3. 判定是否为终点 (假设迷宫数值 2 为终点)
            else if (maze[i][j] == 2) {
                cellChars[0] = L'⚑'; cellChars[1] = L' '; // 旗帜图标
                cellColor = 14; // 黄色
            }
            // 4. 判定是否为寻路算法标记的路径 (数值 3)
            else if (maze[i][j] == 3) {
                cellChars[0] = L'·'; cellChars[1] = L'·'; // 路径点
                cellColor = 10; // 绿色
            }
            // 5. 默认为普通通路
            else {
                cellChars[0] = L' '; cellChars[1] = L' '; 
                cellColor = 7; // 标准白色
            }

            // 核心优化逻辑：如果当前格颜色与上一格不同，先将缓冲区内容打印出来
            if (cellColor != currentActiveColor) {
                if (!lineBuffer.empty()) {
                    // 批量写入之前缓存的同色字符
                    WriteConsoleW(hConsole, lineBuffer.c_str(), lineBuffer.size(), NULL, NULL);
                    lineBuffer = L"";
                }
                // 切换系统颜色属性
                SetConsoleTextAttribute(hConsole, cellColor);
                currentActiveColor = cellColor;
            }
            
            // 将当前格字符加入缓冲区
            lineBuffer += cellChars;
        }
        
        // 打印当前行剩余的字符
        if (!lineBuffer.empty()) {
            WriteConsoleW(hConsole, lineBuffer.c_str(), lineBuffer.size(), NULL, NULL);
        }
        
        // 显式写入换行符
        wchar_t newline = L'\n';
        WriteConsoleW(hConsole, &newline, 1, NULL, NULL);
    }

    // 渲染完毕后恢复光标显示，方便其他控制台操作
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

//玩家移动逻辑实现
int MazeGame::move(char direction){
    int nx = playerX, ny = playerY;
    if(direction == 'w'||direction == 'W')nx--;
    else if(direction == 's'||direction == 'S')nx++;
    else if(direction == 'a'||direction == 'A')ny--;
    else if(direction == 'd'||direction == 'D')ny++;
    else return 0;
    if(nx==width-2 && ny==length-2){
        playerX = nx;
        playerY = ny;
        return 2;
    }
    if(nx>=1 && ny>=1 && nx<=width-2 && ny<=length-2 && (maze[nx][ny]==1||maze[nx][ny]==3)){
        if(maze[nx][ny]==3)maze[nx][ny]=1;
        playerX = nx;
        playerY = ny;
        return 1;
    }
    return 0;
}


//BFS自动寻路
void MazeGame::autoSolve(){
    Point start = {playerX, playerY};
    Point end = {width - 2, length - 2};
    //记录上一个位置
    vector<vector<Point>> parent(width,vector<Point>(length,{-1,-1}));

    queue<Point> q;
    q.push(start);
    parent[start.x][start.y] = start;

    //方向数组
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool found = false;

    while(q.size()){
        Point cur = q.front();
        q.pop();
        //找到终点
        if(cur.x == end.x && cur.y == end.y){
            found = true;
            break;
        }
        
        for(int i=0;i<4;i++){
            //移动
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            //路或者终点
            if(nx>=1&&ny>=1&&nx<=width-2&&ny<=length-2
                &&(maze[nx][ny]==1||maze[nx][ny]==2)
                &&parent[nx][ny] == Point{-1,-1}){
                    parent[nx][ny] = cur;
                    q.push({nx,ny});
            }
        }
    }
    //标记路径
    stack<Point>st;
    if(found){
        Point temp = end;
        while(!(temp.x == start.x&&temp.y==start.y)){
            //把来时路标记为3
            if(maze[temp.x][temp.y]==1) st.push(temp);
            temp = parent[temp.x][temp.y];
        }
        while(st.size()){
            maze[st.top().x][st.top().y] = 3;
            st.pop();
            print();
            Sleep(20);
        }
    }
    
}