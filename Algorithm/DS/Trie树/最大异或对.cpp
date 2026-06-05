#include<iostream>
using namespace std;
const int N = 1e5+10;
int tree[32*N][2];
int a[N];
int idx;
void insert(int x){
    int cur = 0;
    for(int i=31;i>=0;i--){
        int path = ((x>>i)&1);
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
            ret = ret|(1<<i);
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