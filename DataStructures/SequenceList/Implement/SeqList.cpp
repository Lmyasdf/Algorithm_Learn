#include<iostream>
using namespace std;
struct SeqList{
    int *p;
    int length;
    int capacity;
};
void InitList(SeqList &L,int InitSize){//鍒濆鍖?
    L.p = new int [InitSize];
    L.length = 0;
    L.capacity = InitSize;
    cout<<"初始化成功，大小为："<<L.capacity<<endl;
}
void DeleList(SeqList &L){
    if(L.p!=nullptr){
        delete[] L.p;
        L.p = nullptr;
    }
}
int main(){
    SeqList L;
    InitList(L,10);
}