/* 
题目：队列安排 
https://www.luogu.com.cn/problem/P1160
思路：本题涉及左右随意插入和删除，所以需要创建ne和pre数组，构成双向链表
错误：忘了初始化。最开始有一个1在队列中，要把他和0连接上，否后面从ne[0]开始遍历就会出问题
 */
#include<iostream>
using namespace std;
const int N = 1e5+10;
int ne[N],pre[N],st[N];
int main(){
    int n;
    cin>>n;

    //这个初始化非常重要需要注意！
    st[1] = 1;
    ne[0] = 1;
    pre[1] = 0;

    for(int i=2;i<=n;i++){
        int a,op;
        cin>>a>>op;
        st[i] = 1;
        if(op==0){
            ne[pre[a]] = i;
            ne[i] = a;
            pre[i] = pre[a];
            pre[a] = i;
        }
        else if(op==1){
            pre[ne[a]] = i;
            ne[i] = ne[a];
            ne[a] = i;
            pre[i] = a;
        }
    }
    int m;
    cin>>m;//删除的数目
    for(int i=1;i<=m;i++){
        int toDelete;//要删除的数
        cin>>toDelete;
        if(!st[toDelete])continue;
        st[toDelete] = 0;
        pre[ne[toDelete]] = pre[toDelete];
        ne[pre[toDelete]] = ne[toDelete];
    }
    //从ne[0]开始遍历链表输出：
    for(int i=ne[0];i!=0;i=ne[i])cout<<i<<" ";
}