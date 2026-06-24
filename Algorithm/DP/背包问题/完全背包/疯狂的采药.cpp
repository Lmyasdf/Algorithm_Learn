//https://www.luogu.com.cn/problem/P1616
#include<iostream>
using namespace std;
const int T = 1e7+10;
const int N = 1e4+10;
int a[N],w[N];
long long f[T]; 
int t,n;
int main(){
    cin>>t>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>w[i];
    for(int i=1;i<=n;i++){
        for(int j=a[i];j<=t;j++){
            f[j] = max(f[j],f[j-a[i]]+w[i]);
        }
    }
    cout<<f[t];
}