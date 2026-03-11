#define NOMINMAX           
#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include<fstream>
#include "MazeGame.h"
#include<conio.h>
#include<windows.h>
using namespace std;

void chooseDifficulty(int &w,int &l){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    cout<<"--------------------------------------------"<<endl;
    cout<<"!!!!!!!!!!!! Welcome to MazeGame !!!!!!!!!!!"<<endl;
    cout<<"--------------------------------------------"<<endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"-- (请切换至全屏并切换英文输入法进行游戏) --"<<endl;
    SetConsoleTextAttribute(hConsole, 11);
    cout<<"\n1. 简单 (20 * 20)\n2. 中等 (40 * 30)\n3. 困难 (60 * 40)"<<endl;
    cout<<"请按数字选择难度："<<endl;
    
    char choice = _getch();
    switch(choice) {
        case '1': w = 20; l = 20; break; 
        case '2': w = 40; l = 30; break;
        case '3': w = 60; l = 40; break;
        default:  w = 20; l = 20; break; // 默认简单
    }
}

int main() {
    //创建迷宫
    while(1){
        int w,l;
        system("cls");
        chooseDifficulty(w,l);
        MazeGame game(w,l);
        game.generate();
        system("cls");
        //游戏玩法
        bool help = false;
        while(true){
            game.print();
            cout << "移动 (按W/A/S/D, Q退出): " << endl;
            if(!help){
                cout<<"如果你感觉困难，可以按H寻求帮助"<<endl;
            }
            char input = _getch(); 
            if(input == 'q'||input == 'Q')break;
            else if((input == 'h'||input == 'H')&&!help){
                game.autoSolve();
                help = true;
                system("cls");
                continue;
            }
            //胜利判断
            int win = game.move(input);
            if(win == 2){
                game.print();
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 14);
                
                cout<<"\n\n ★ ★ ★  恭喜你！成功找到出口！ ★ ★ ★"<<endl;
                cout<<"按 C 并回车可再来一局, Q 退出"<<endl;
                char in;
                cin>>in;
                if(in == 'c'||in == 'C')break;
                else if(in =='q'||in == 'Q')return 0;
            }
        }
    }
}