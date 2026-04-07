/* 
https://www.luogu.com.cn/problem/P1955
思路：解题思路很简单就是先遍历e==1情况，进行合并，然后遍历0情况，找有没有非法元素
    其中数据范围较大，因此使用了离散化。具体详情见注释。 
*/
#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 2e5+10;//N开双倍因为x，y两个数，映射到fa数组里必须要双倍大小

struct st{
    int x,y,e;
}a[N];
int T,n;
int fa[N];

//并查集三板斧
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void un(int x,int y){
    int fx = find(x);
    int fy = find(y);
    fa[fx] = fy;
}
bool check(int x,int y){
    return find(x)==find(y);
}

int main(){
    cin>>T;
    while(T--){
        vector<long long>v;//存x,y
        unordered_map<long long,int>m;//用来通过下标映射xy
        cin>>n;
        int x,y,e;
        //输入
        for(int i=1;i<=n;i++){
            cin>>x>>y>>e;
            v.push_back(x);
            v.push_back(y);
            a[i].x = x;
            a[i].y = y;
            a[i].e = e;
        }
        //排序
        sort(v.begin(),v.end());
        //去重(一定注意unique需要一个值来接它)
        auto it = unique(v.begin(),v.end());
        //vector使用unique之后记得清楚后面的数，得到正确的size大小
        v.erase(it,v.end());
        
        //存映射和 初始化fa数组（都指向自身）！！！！先统一初始化，不要边遍历边初始化
        for(int i=0;i<v.size();i++){
            m[v[i]] = i + 1;
            fa[i+1] = i+1;
        }
        //先遍历一遍e==1，合并一下集合
        for(int i=1;i<=n;i++){
            if(a[i].e==1)un(m[a[i].x],m[a[i].y]);
        }
        //接下来遍历e==0，判断是否有不等两数存在一个集合中
        bool flag = true;
        for(int i=1;i<=n;i++){
            if(a[i].e==0){
                if(check(m[a[i].x],m[a[i].y])){
                    flag = false;
                    break;
                }
            }
        }
        //输出结果
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}