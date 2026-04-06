/* https://www.luogu.com.cn/problem/P1596
思路：利用并查集，把W分成若干个集合，最后找有几个父节点，就知道有几个水坑
错误：1.定义的f数组大小只设置[N],而访问的时候是二维转一维，大小应该是[N*N]
     2.忘记判断a[nx][ny]指向的是否是'W'就un了
     3.DFS后遗症，用st标记，拦截路径，在并查集中会出错，错误切断路径 
改进：可以for从头到尾遍历，让每个位置都指向自身     
     */
#include<iostream>
using namespace std;
const int N =1e2+10;
char a[N][N];
int f[N*N];
int n,m;
int ret;
int dx[] = {0,0,1,-1,-1,-1,1,1};
int dy[] = {1,-1,0,0,-1,1,-1,1};
int find(int x){
    return f[x]==x?x:f[x] = find(f[x]);
}
void un(int x,int y){
    int fx = find(x);
    int fy = find(y);
    f[fx] = fy;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='W')f[i*m+j] = i*m+j;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='W'){
                for(int k=0;k<8;k++){
                    int nx = i+dx[k];
                    int ny = j + dy[k];
                    if(nx<0||ny<0||nx>=n||ny>=m||a[nx][ny]!='W')continue;
                    un(i*m+j,nx*m+ny);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='W'){
                if(i*m+j==find(i*m+j))ret++;
            }
        }
    }
    cout<<ret;
}