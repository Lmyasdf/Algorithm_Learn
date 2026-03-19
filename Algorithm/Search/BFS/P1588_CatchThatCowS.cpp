/* 
题目：抓牛
https://www.luogu.com.cn/problem/P1588
错误：剪枝顺序错误，应该先判断索引是否合法，再判断该索引对应数组值是否合法
      剪枝条件写错，是d[i]>1e5而不是a[d[i]]
 */
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N = 1e5+10;
int a[N];
int x,y;
void bfs(queue<int>q){
    while(q.size()){
        int t = q.front();
        q.pop();
        int A = t-1,B = t+1,C = t*2;
        int d[] = {A,B,C};
        for(int i=0;i<3;i++){
            if(d[i]>1e5||d[i]<0)continue;
            if(a[d[i]]!=-1)continue;
    
            q.push(d[i]);
            a[d[i]] = a[t] + 1;
            if(d[i] == y)return;
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        memset(a,-1,sizeof(a));
        cin>>x>>y;
        a[x] = 0;
        queue<int>q;
        q.push(x);
        bfs(q);
        cout<<a[y]<<endl;
    }
}