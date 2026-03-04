#include<iostream>
using namespace std;
class MyQueue{
private:
    static const int MaxSize = 10;
    int data[MaxSize];//0-8可以存数
    int head;
    int tail;

public:
    MyQueue():head(0),tail(0){}
    bool isEmpty(){
        return head==tail;
    }
    
    bool isFull(){
        return (tail+1)%MaxSize == head; //tail的下一个位置是head就是满，取模运算实现首尾相连
    }

    void push(int val){
        if(isFull()){
            cout<<"队列已满,入队失败"<<endl;
            return;
        }
        data[tail] = val;
        tail = (tail+1)%MaxSize;//向后移动，到末尾自动回0
    }

    int pop(){
        if(isEmpty()){
            cout<<"队列已空，无法出队"<<endl;
            return -1;
        }
        int tmp = data[head];
        head = (head+1) % MaxSize;
        return tmp;
    }

    void print(){
        if(isEmpty()){
            cout<<"队列为空,打印失败"<<endl;
            return;
        }
        int i = head;
        while(i!=tail){
            cout<<data[i]<<" ";
            i = (i+1) % MaxSize;
        }
        cout<<endl;
    }

};

int main(){
    MyQueue queue;
    queue.push(10);
    queue.push(99);
    queue.push(20);
    queue.print();
    queue.pop();
    queue.print();
}