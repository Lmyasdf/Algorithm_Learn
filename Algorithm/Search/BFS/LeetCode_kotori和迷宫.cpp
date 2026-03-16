/* 
题目：迷宫
https://ac.nowcoder.com/acm/problem/50041
思路：BFS
错误：缺少禁止回头逻辑,if里也要加上判断如果走过就continue
     出口不可以继续走，要continue尽快剪掉，在e入队前剪掉
     注意审题，没有出口就输出-1
 */
#include<iostream>
#include<queue>
using namespace std;
typedef pair<int,int> II;
int n,m;
queue<II>q;
const int N = 35;
char c[N][N];
int a[N][N];
bool st[N][N];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int ret = 0x3f3f3f3f;
int count = 0;
void bfs(){
    while(q.size()){
        II t = q.front();
        q.pop();//出队
        for(int i=0;i<4;i++){
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];
            if(nx<1||ny<1||nx>n||ny>m||c[nx][ny]=='*'||st[nx][ny])continue;
            st[nx][ny] = true;
            a[nx][ny] = a[t.first][t.second]+1;
            if(c[nx][ny] == 'e') {
                count++;
                if(count==1)ret = a[nx][ny];
                continue;
            }

            q.push({nx,ny}); 
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c[i][j];
            if(c[i][j]=='k'){
                q.push({i,j});
                st[i][j] = true;
            }
        }
    }
    bfs();
    if(count)cout<<count<<" "<<ret;
    else cout<<"-1";
}