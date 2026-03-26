/* 
题目：小明的游戏
https://www.luogu.com.cn/problem/P4554
思路：01BFS
 */
#include<iostream>
#include<deque>
#include<cstring>
using namespace std;
const int N = 510;
int n,m,x1,y_1,x2,y2;
int dist[N][N];
char c[N][N];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void bfs(){
    if(x1==x2&&y_1==y2)return;//起点等于重点，直接return

    //双端队列，0队头1队尾
    deque<pair<int,int>>q;
    q.push_back({x1,y_1});

    //初始化dist数组
    memset(dist,-1,sizeof(dist));
    dist[x1][y_1] = 0;
    //经典BFS流程
    while(q.size()){
        pair<int,int>t = q.front();
        q.pop_front();
        //注意出口位置，是在出队时候判断是不是终点，因为这个时候才是最优解
        if(t.first==x2&&t.second == y2)return;
        for(int i=0;i<4;i++){
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];
            if(nx>=0&&ny>=0&&nx<n&&ny<m){
                int w = (c[t.first][t.second] == c[nx][ny]?0:1);
                //重点：
                //1.没走过，0队头1队尾
                if(dist[nx][ny]==-1){
                    dist[nx][ny] = dist[t.first][t.second] + w;
                    if(w==1)q.push_back({nx,ny});
                    else q.push_front({nx,ny});
                }
                //2.走过更新dist的最优解
                else if(dist[t.first][t.second]+w<dist[nx][ny]){
                    dist[nx][ny] = dist[t.first][t.second] + w;
                }
            }
        
        }
    }
}
int main(){
    while(cin>>n>>m,n&&m){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        cin>>x1>>y_1>>x2>>y2;
        bfs();
        cout<<dist[x2][y2]<<endl;
    }
    
}