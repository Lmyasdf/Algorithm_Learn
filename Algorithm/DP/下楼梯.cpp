//https://www.luogu.com.cn/problem/P10250
#include<iostream>
using namespace std;
const int N = 65;
//1.确定数组存啥状态（定义状态表示），此题表示为到达n级所需步数
long long f[N];
long long fun(int n){
    if(n<3)return f[n];
    //2.推导状态转移方程，最多走3级，故f[n]就是前三级所需步数的累加
    //4.确定调表顺序，本题从前往后
    //5.确定最终结果
    if(f[n]!=0)return f[n];
    return f[n] = fun(n-1) + fun(n-2) + fun(n-3);
}

int main(){
    int n;
    cin>>n;
    //3.初始化，显而易见的位置填上值
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    /* 简洁写法，省略递归方程：
    for(int i=3;i<=n;i++){
        f[i] = f[i-1] + f[i-2] + f[i-3];
    }  */
    cout<<fun(n)<<endl;
}