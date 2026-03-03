/* 
题目：飞机降落
https://www.luogu.com.cn/problem/P9241

思路：利用DFS暴力搜索遍历所有情况，画树模拟剪枝情况，本题
    类似排列问题，需要找出所有排列，然后返回true和false

    错误：1.注意输出格式：YES而不是Yes
     2.多组测试数据记得memset一下，注意包含头文件cstring
 */
#include<iostream>
#include<cstring>
using namespace std;
const int N =15;
int t[N],d[N],l[N];
int n;
bool st[N];
bool dfs(int pos,int end){
    //出口
    if(pos>n)return true;
    
    for(int i=1;i<=n;i++){
        if(st[i])continue;//剪枝
        if(t[i]+d[i]<end)continue;//剪枝
        st[i] = true;//标记已选择
        int newend = max(t[i],end) + l[i];//新选择的飞机的结束时间/位置
        if(dfs(pos+1,newend))return true;
        //如果dfs返回true，即选择的飞机合法，那么就直接向上一层dfs返回true，
        //表示选择成功，最开始的dfs返回的表示能否把n架飞机安排妥当
        st[i] = false;//恢复现场。如果上层dfs返回false选择失败，那就标记这个i还没选择
    }
    return false;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        memset(st,0,sizeof(st));
        cin>>n;
        for(int i=1;i<=n;i++)cin>>t[i]>>d[i]>>l[i];
        if(dfs(1,0))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}