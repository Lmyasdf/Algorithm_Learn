//https://www.luogu.com.cn/problem/P2758
#include<iostream>
#include<cmath>
using namespace std;
const int N = 2010;
string s,t;
int f[N][N];//存s的1~i位变为t的1~j位最少需要几步操作
int main(){
    cin>>s>>t;
    int l1 = s.length(), l2 = t.length();
    //初始化
    for(int i=1;i<=l1;i++)f[i][0] = i;
    for(int i=1;i<=l2;i++)f[0][i] = i;

    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            //状态转移方程
            //1.如果当前位置字符相同，那么这个位置f值就等于遍历当前
            //字符之前的操作值
            if(s[i-1] == t[j-1]) f[i][j] = f[i-1][j-1];
            //2.如果当前位置字符不同，当前字符可以三种操作达到目的
            //分别分析比较这三种操作的总操作数取最小更新f即可
            else{
                f[i][j] = min(f[i-1][j]+1,f[i][j-1]+1);
                f[i][j] = min(f[i][j],f[i-1][j-1]+1);
            }
        }
    }
    cout<<f[l1][l2];

}