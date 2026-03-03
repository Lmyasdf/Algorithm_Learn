/* 
题目：选数
链接：https://www.luogu.com.cn/problem/P1036
思路：暴力搜索，dfs递归搜出所有组合情况，判断和是否为素数即可
错误: 1.错误使用哈希表。使用哈希表，这样不同数相同和就合并成了一种情况，出错
    2.判断过程在dfs出口处就可以了，不用再创建数组存这些结果最后在main中遍历判断
*/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N = 1e8;
int cnt = 0;
int n,k;

bool isPrime[N];
vector<int>primes;
vector<int>v,v2;

// bool isPrime(long long x){
//     if(x<2)return false;
//     if(x==2||x==3)return true;
//     if(x%2==0||x%3==0)return false;
//     for(long long i=5;i*i<=x;i+=6)if(x%i==0||x%(i+2)==0)return false;
//     return true;
// }

//线性筛：
void linearSieve(){
    memset(isPrime,true,sizeof(isPrime));//先全初始化为true
    isPrime[0] = false;//两个特殊值
    isPrime[1] = false;
    for(int i=2;i<=N;i++){//遍历2~N
        if(isPrime[i])primes.push_back(i);//是素数就入素数组
        for(int a:primes){//遍历素数数组
            if(1LL*a*i>N)break;
            isPrime[a*i] = false;//标记合数
            if(i%a==0)break;//更大的素数*i得到的数后面一定会被后面i更大*a标记
        }
    }
}
void dfs(int begin){
    if(v2.size()==k){
        int sum=0;
       for(int i=0;i<k;i++)sum+=v2[i];
       if(isPrime[sum])cnt++;
       return;
    }
    for(int i=begin;i<n;i++){
        v2.push_back(v[i]);
        dfs(i+1);
        v2.pop_back();
    }
}
int main(){
    linearSieve();    
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    dfs(0);
    cout<<cnt;
}