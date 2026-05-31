// https://www.luogu.com.cn/problem/P2024
#include<iostream>
using namespace std;
const int N = 5e4+10;
int fa[N],d[N];
int find(int x){
    if(x = fa[x]) return x;
    int t = find(fa[x]);
    d[x] += d[fa[x]];
    return fa[x] = t;
}
void un(int x,int y,int w){
    int fx = find(x),fy = find(y);
    if(fx != fy){
        fa[fx] = fy;
        d[fx] = d[y] + w - d[x];
    }
}
int main(){
    int n,k;
    int ret = 0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)fa[i] = i;
    while(k--){
        int op,a,b;
        cin>>op>>a>>b;
        if(a>n||b>n){
            ret++;
            continue;
        }
        if(op == 1){
            if(find(a)!=find(b) && (((d[b]-d[a])%3)+3)%3 != 0)ret++;
            else un(a,b,0);
        }
        else {
            if(find(a)!=find(b) &&  (((d[b]-d[a])%3)+3)%3 != 1)ret++;
            else un(a,b,2);//÷ÿµ„
        }
    }
    cout<<ret;
}