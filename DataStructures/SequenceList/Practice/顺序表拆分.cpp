#include<iostream>
using namespace std;
struct SList{
    int data[10];
    int length;
};
void spilt(SList A, SList &B, SList &C){
    B.length = 0;
    C.length = 0;
    for(int i=0;i<A.length;i++){
        int a = A.data[i];
        if(a>=0) B.data[B.length++] = a;
        else C.data[C.length++] = a;
    }
}