/* 
题目：矩阵移动
https://ac.nowcoder.com/acm/problem/51024
思路：多源BFS，就是在BFS基础上初始queue中多插入几个元素（起点）
错误：memset不能写0x3f3f3f3f,而是0x3f，判断时候还是0x3f3f3f3f
 */
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 1e3+10;
int n,m;
char a[N][N];
int dist[N][N];
queue<pair<int,int>>q;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
void dfs(){
    while(q.size()){
        
        pair<int,int>t = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];
            //剪枝
            if(nx>=1&&ny>=1&&nx<=n&&ny<=m&&dist[nx][ny]==0x3f3f3f3f){
                q.push({nx,ny});//入队
                //更新距离
                dist[nx][ny] = min(dist[nx][ny],dist[t.first][t.second]+1);
            }
        }
    }
}
int main(){
    cin>>n>>m;
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j]; 
            if(a[i][j]=='1'){
                dist[i][j] = 0;
                q.push({i,j});
            }
        }
    }
    dfs();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}