#include<iostream>
using namespace std;
const int N = 1e5+10;
int stk[N];//栈容器
int t = 0;//栈顶指针
void push(int x){
    stk[++t] = x;
}
void pop(){
    if(t>0) t--;
}
int top(){
    return stk[t];
}
bool empty(){
    return t==0;
    /* if(t>0)return false;
    else return true;  */
}
int size(){
    return t;
}
int main(){
    push(10);
    push(20);
    push(30);
    
    cout<<"栈顶元素为："<<top()<<endl;
    cout<<"栈的大小为："<<size()<<endl;
    pop();
    cout<<"栈顶元素为："<<top()<<endl;
    cout<<"栈的大小为："<<size()<<endl;

    //遍历
    for(int i=t;i>0;i--)cout<<stk[i]<<" ";

}