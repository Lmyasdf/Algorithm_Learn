/* 
https://www.luogu.com.cn/problem/P1596
思路：遍历所有格子，如果是水坑，就进入bfs，每次ret++
错误：dfs中变量名冲突。dy[i] 写成 dy[j] 
*/
#include<iostream>
using namespace std;
const int N = 1e2+10;
char a[N][N];
bool st[N][N];
int dx[] = {0,0,1,-1,-1,-1,1,1};
int dy[] = {1,-1,0,0,1,-1,-1,1};
int n,m;
int ret = 0;
void dfs(int x,int y){
    for(int i=0;i<8;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<1||ny<1||nx>n||ny>m||st[nx][ny]||a[nx][ny]=='.')continue;
        st[nx][ny] = true;
        dfs(nx,ny);
    }
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
            if(st[i][j]||a[i][j]=='.')continue;
            // st[i][j] = true;
            dfs(i,j);
            ret++;
        }
    }
    cout<<ret;
}