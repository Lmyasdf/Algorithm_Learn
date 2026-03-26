/* 
题目：ThreeStates
https://www.luogu.com.cn/problem/CF590C
思路：遍历所有位置，找每个点到三个国家的距离，利用多源BFS + 01BFS进行遍历
最后输出最小ret
 */
#include<iostream>
#include<deque>
#include<cstring>
using namespace std;
const int N = 1e3+10;
int n,m;
int dist[4][N][N];
char a[N][N];
int ret = 0x3f3f3f3f;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
void bfs(int num){
    deque<pair<int,int>>q;
    memset(dist[num],-1,sizeof(dist[num]));
    //入队，标记dist为0
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==(char)('0'+num)){
                dist[num][i][j] = 0;
                q.push_back({i,j});
            }
        }
    }
    while(q.size()){
        pair<int,int>t = q.front();
        q.pop_front();
        for(int i=0;i<4;i++){
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];
            if(nx>=1&&ny>=1&&nx<=n&&ny<=m&&a[nx][ny]!='#'){
                int w = a[nx][ny]=='.'?1:0;
                //没走过
                if(dist[num][nx][ny]==-1){
                    dist[num][nx][ny] = dist[num][t.first][t.second] + w;
                    if(w==1)q.push_back({nx,ny});
                    else q.push_front({nx,ny});
                }
            }
        }

    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    bfs(1);
    bfs(2);
    bfs(3);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='#')continue;
            int x = dist[1][i][j];
            int y = dist[2][i][j]; 
            int z = dist[3][i][j];
            if(x==-1||y==-1||z==-1)continue;//注意过滤非法值
            if(a[i][j]=='.')ret = min(ret,x+y+z-2);
            else ret = min(ret,x+y+z);
        }
    }
    if(ret == 0x3f3f3f3f)cout<<"-1"<<endl;
    else cout<<ret;

}