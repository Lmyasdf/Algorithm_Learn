//https://www.luogu.com.cn/problem/P1115
#include<iostream>
using namespace std;
const int N = 2e5+10;
int f[N],a[N];//1.确定状态：以该位置为终点，从开始到这里的最大和
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //3.初始化
    int ret = a[1];//错误：初始化为0，在全为负数的测试点会挂掉
    for(int i=1;i<=n;i++){
        f[i] = max(f[i-1]+a[i],a[i]);//2.推导状态转移方程
        ret = max(f[i],ret);
    }
    cout<<ret;
}