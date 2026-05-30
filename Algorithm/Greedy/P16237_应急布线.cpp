//https://www.luogu.com.cn/problem/P16237
#include<iostream>
#include<cmath>
using namespace std;
const int N = 1e5+10;
int n,op;
int fa[N];
int ret;
int sz[N];
int find(int x){
    return fa[x]==x? x : fa[x] = find(fa[x]);
}
void un(int x,int y){
    int fy = find(y);
    int fx = find(x);
    if(fy != fx){
        fa[fy] = fx;
        sz[fx] += sz[fy];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>op;
    for(int i=1;i<=n;i++){
        fa[i] = i;
        sz[i] = 1;
    }
    while(op--){
        int a,b;
        cin>>a>>b;
        un(a,b);
    }
    for(int i=1;i<=n;i++){
        if(find(i)==i){
            ret++;
        }
    }
    int add = ret - 1;  // 需要添加的边数
    int ans2 = ceil(2.0*add / n);//注意括号内非整形
    cout << add << " " << ans2 << endl;
    return 0;
}