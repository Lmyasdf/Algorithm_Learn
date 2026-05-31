//https://www.luogu.com.cn/problem/P3370
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1e4+10;
const int P = 131;
typedef unsigned long long ULL;
ULL f[N],p[N];//前缀数组
int n;

//*核心公式 计算字符串哈希值
void myhash(string s){
    p[0] = 1;//p[0]必须先初始化为1
    for(int i=1;i<=s.size();i++){//注意是1~s.size()
        f[i] = f[i-1]*P + s[i-1]; //前i位字符组成的串的哈希值
        p[i] = p[i-1]*P; //某位的次方
    }
}

//查询子串
ULL cal(int l,int r){
    return f[r] - f[l-1]*p[r-l+1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n;
    cin.ignore();
    vector<ULL>v;//注意vector类型也要ULL
    
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        myhash(s);
        v.push_back(f[s.size()]);
    }

    sort(v.begin(),v.end());//去重之前先排序
    auto a = unique(v.begin(),v.end());
    v.erase(a,v.end());
    cout<<v.size();
} 