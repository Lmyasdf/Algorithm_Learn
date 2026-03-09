/* 
题目：小猫爬山
https://www.luogu.com.cn/problem/P10483
思路：一只小猫一只小猫分析，进dfs看看放哪个车上，画树，剪枝
错误：不是所有缆车都放不下才考虑加新车，而是不管什么情况都尝试加新车，否则容易错过最优解
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 20;
int c[N];
int n,M;
int ret = 0x3f3f3f3f;
int sum = 1;
vector<int>v;
bool mycmp(int a,int b){
    return a>b;
}
void dfs(int pos,int car){
    if(car >= ret)return;//大于当前的解，必然不是最优解，直接return
    if(pos==n){//递归出口
        ret = min(ret,car);
        return;
    }

    for(int i=1;i<=car;i++){//遍历所有车
        if(c[i]+v[pos]>M)continue;//放不下就continue
        c[i] += v[pos];
        dfs(pos+1,car);
        c[i] -= v[pos];
    }
    //尝试加一辆车
    c[car+1] += v[pos];
    dfs(pos+1,car+1);
    c[car+1] -= v[pos];        
    
}
int main(){
    cin>>n>>M;
    
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end(),mycmp);//自定义降序排列，先放大的进缆车，快速填满缆车
    dfs(0,1);
    cout<<ret;
}