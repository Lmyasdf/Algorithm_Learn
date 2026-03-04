/* 
题目：数独
https://www.luogu.com.cn/problem/P1784
思路：暴力搜索，一个格子一个格子去dfs，画树，找剪枝情况，
    注意只要一种结果，dfs要有返回类型，用来终止递归
错误：1.忘了先判断该格子是否有数，有数跳过
    2.被换行卡住了，不知道怎么办，其实就是y到头了大胆x++更新y就好了， 
    要记住这个dfs的本质就是给格子选数，一个格子选完了，要去下一个格子dfs
 */
#include<iostream>
using namespace std;
const int N = 10;
const int n = 9;
int a[N][N];
bool stx[N][N],sty[N][N],st[N][N][N];
bool dfs(int x,int y){//逐个格子选数
    if(y==9){//大胆更新
        x++;
        y=0;
    }
    if(x==9){//出口
        return true;
    }
    if(a[x][y])return dfs(x,y+1);//当这个格子有数，就直接dfs下一个格子就好了
    for(int i=1;i<=n;i++){
        if(stx[x][i]||sty[y][i]||st[x/3][y/3][i])continue;
        a[x][y] = i;
        stx[x][i] = sty[y][i] = st[x][y][i] = true;
        if(dfs(x,y+1))return true;//递归终止
        //恢复现场，找其他i试
        a[x][y] = 0;
        stx[x][i] = sty[y][i] = st[x][y][i] = false;
    }
    return false;
}
int main(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            a[i][j] = x;
            if(x)stx[i][x] = sty[j][x] = st[i][j][x] = true;
        }
    }
    dfs(0,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}