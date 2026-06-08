#include<iostream>
using namespace std;
const int N = 1e5+10;
const int p = 100003;
int f[N];//确定状态（步数）
int main(){
    int n,k;
    cin>>n>>k;
    f[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k&&i>=j;j++){//公式推导，注意保证i>=j防止越界
            f[i] = (f[i] + f[i-j])%p;
        }
    }
    cout<<f[n]%p;
}