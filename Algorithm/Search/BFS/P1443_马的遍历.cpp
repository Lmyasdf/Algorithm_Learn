/* 
题目：马的遍历
https://www.luogu.com.cn/problem/P1443
思路：经典bfs，利用队列，先初始化队列，入队头，然后bfs中不断进队孩子，
然后出队头
错误：混淆BFS与递归。标记时机不对。步数逻辑错误，错用pos当做函数参数然后递归
     逻辑判断错误，最后判断跳不到的位置时，if逻辑写错，不是非x并且非y 
     这样x这一行和y这一列就全被忽略了，应该是只排出(x，y)这一点即可
*/
#include<iostream>
#include<queue>
using namespace std;
const int N = 4e2+10;
int n,m,x,y;
int a[N][N];
bool st[N][N];
int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};
queue<pair<int,int>>q;
void bfs(){
    while(q.size()){
        pair<int,int>t = q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];
            if(st[nx][ny]||nx<1||ny<1||nx>n||ny>m)continue;
            st[nx][ny] = true;
            q.push({nx,ny});
            a[nx][ny] = a[t.first][t.second]+1;
        }
    }
}
int main(){
    cin>>n>>m>>x>>y;
    q.push({x,y});
    st[x][y] = true;
    bfs();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!(i==x&&j==y)&&a[i][j]==0){
                cout<<"-1 ";
                continue;
            }
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}