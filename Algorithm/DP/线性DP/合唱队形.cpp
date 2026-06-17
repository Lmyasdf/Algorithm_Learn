//https://www.luogu.com.cn/problem/P1091
/* 
总结：两次对向最长上升子序，重点在于问题转化：把找挑出几位转化成队伍内
最长几个数满足序列
错误：总马虎肌肉记忆写错，第二次dp把g数组写成f了 
*/
#include<iostream>
using namespace std;
const int N = 110;
int f[N],g[N],a[N];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i] = 1;
        g[i] = 1;
    }
    int ret = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]<a[i])f[i] = max(f[i],f[j]+1);
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=n;j>i;j--){
            if(a[i]>a[j])g[i] = max(g[i],g[j]+1);
        }
        ret = max(ret,f[i]+g[i]-1);
    }
    cout<<n-ret;
}