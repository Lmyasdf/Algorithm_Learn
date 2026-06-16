//https://www.luogu.com.cn/problem/B3637
#include<iostream>
using namespace std;
const int N = 5e3+10;
int f[N],a[N];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        f[i] = 1;
        cin>>a[i];
    }
    int m = 1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            if(a[i]>a[j])f[i] = max(f[i],f[j]+1);
        }
        m = max(m,f[i]);
    }
    cout<<m;
}