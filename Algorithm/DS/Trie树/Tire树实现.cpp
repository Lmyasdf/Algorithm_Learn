#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e6+10; //表示所有的字符串共有多少个字符

int tree[N][26],p[N],e[N];
int idx;//用来推进树节点索引

void insert(string &s){
    int cur = 0;
    p[cur]++;
    for(char c:s){
        int path = c-'a';
        //如果没走过就新开辟一条路
        if(tree[cur][path]==0)tree[cur][path] = ++idx;
        cur = tree[cur][path];
        p[cur]++;
    }
    e[cur]++;
}

int find(string s){
    int cur = 0;
    for(char c:s){
        int path = c - 'a';
        if(tree[cur][path]==0)return 0;
        cur = tree[cur][path];
    }
    return e[cur];
}

int find_pre(string s){
    int cur = 0;
    for(char c:s){
        int path = c - 'a';
        if(tree[cur][path]==0)return 0;
        cur = tree[cur][path];
    }
    return p[cur];
}
int main(){
    
}