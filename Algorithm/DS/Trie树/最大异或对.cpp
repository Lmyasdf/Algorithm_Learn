//https://www.luogu.com.cn/problem/P10471
//思路：找到每个数x对应的最优解y，得出每组x^y，最后统计最大值
//      利用二进制01存Trie树解决
//错误：倒序for总把i--习惯写成i++
#include<iostream>
using namespace std;
const int N = 1e5+10;
int tree[32*N][2];
int a[N];
int idx;
void insert(int x){
    int cur = 0;
    for(int i=31;i>=0;i--){
        int path = ((x>>i)&1);//位运算1：判断某位是不是1
        if(tree[cur][path]==0)tree[cur][path]=++idx;
        cur = tree[cur][path];
    }
}

int find(int x){
    int ret=0;
    int cur = 0;
    for(int i=31;i>=0;i--){
        int path = ((x>>i)&1);
        //走不通
        if(!tree[cur][path^1]){
            cur = tree[cur][path];
        }
        //走得通
        else{
            cur = tree[cur][path^1];
            ret = ret|(1<<i);//位运算2：将某位变为1
        }
    }
    return ret;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        insert(a[i]);
    }

    int ret = 0;
    for(int i=1;i<=n;i++){
        ret = max(ret,find(a[i]));
    }

    cout<<ret;
}