/* 题目：滑雪
https://www.luogu.com.cn/problem/P1434
思路：遍历所有点，从每个点开始dfs，最后输出最大值，dfs中应用记忆化搜索，16行是关键
没搜索过，就给他赋值表示滑过的同时也赋了该点可以滑最少本身一个位置
 */
#include<iostream>
#include<cstring>
using namespace std;
const int N = 110;
int f[N][N],a[N][N];
int n,m;
int ret = 0;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int dfs(int x,int y){
    if(f[x][y])return f[x][y];
    f[x][y] = 1;//关键
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=1&&ny>=1&&nx<=n&&ny<=m&&a[nx][ny]>a[x][y]){
            f[x][y] = max(dfs(nx,ny)+1,f[x][y]);
        }
    }
    return f[x][y];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ret=max(dfs(i,j),ret);
        }
    }
    cout<<ret;
}