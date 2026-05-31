/*
https://www.luogu.com.cn/problem/P1196
核心：x所在序列拼接在y后面，那fx到fy的距离d就是fy所在集合元素数目
     因此需要新增一个count数组(记录各个元素所在集合的元素数)来维护
     权值 
*/
#include<iostream>
#include<cmath>
using namespace std;
const int N = 5e5+10;
int fa[N],d[N],count[N];
int find(int x){
    if(fa[x] == x)return x;
    int t = find(fa[x]);
    d[x] += d[fa[x]];
    return fa[x] = t;
}
void un(int x ,int y){
    int fx = find(x), fy = find(y);
    if(fx != fy){
        fa[fx] = fy;
        d[fx] = count[fy];
        count[fy] += count[fx];
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)fa[i] = i,count[i]=1;
    for(int i=1;i<=n;i++){
        char c;
        int a,b;
        cin>>c>>a>>b;
        if(c == 'M'){
            un(a,b);
        }   
        else{
            int fx = find(a),fy = find(b);
            if(fx != fy){
                cout<<"-1"<<endl;
                continue;
            }
            else{
                cout<<abs(d[b]-d[a])-1<<endl;
            }
        }
    }

}