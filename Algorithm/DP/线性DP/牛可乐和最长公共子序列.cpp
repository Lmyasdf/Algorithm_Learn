//https://ac.nowcoder.com/acm/problem/235624
#include<iostream>
#include<string>
using namespace std;
const int N = 5010;
int f[N][N];//存的是两个字符串分别取第几位的最长公共子序列长度
string s,t;
int main(){
    while(cin>>s>>t){
        for(int i=1;i<=s.length();i++){
        for(int j=1;j<=t.length();j++){
            //状态转移方程：
            if(s[i-1] == t[j-1]) f[i][j] = f[i-1][j-1] + 1;
            else f[i][j] = max(f[i-1][j],f[i][j-1]);
        }
        }
        cout<<f[s.length()][t.length()]<<endl;
    }
}