#include<iostream>
using namespace std;
struct LNode{
    int data;
    struct LNode *next;
};
typedef struct LNode Node;
typedef struct LNode *LinkList;

void merge(LinkList &La,LinkList &Lb){
    LNode* pa = La->next;
    LNode* pb = Lb->next;
    LNode* q;
    La->next = nullptr;

    //判断双链表的最小值头插到La中
    while(pa!=nullptr && pb!=nullptr){
        if(pa->data <= pb->data){
            q = pa;
            pa = pa->next;
        }
        else{
            q = pb;
            pb = pb->next;
        }
        //头插
        q->next = La->next;
        La->next = q;
    }

    //将剩余的节点插入La中
    while(pa != nullptr){
        q = pa;
        pa = pa->next;
        q->next = La->next;
        La->next = q;
    }
    while(pb != nullptr){
        q = pb;
        pb = pb->next;
        q->next = La->next;
        La->next = q;
    }
    //释放资源
    delete Lb;
    Lb = nullptr;
}
int main(){
    
}