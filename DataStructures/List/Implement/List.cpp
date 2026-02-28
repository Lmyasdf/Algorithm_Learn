#include<iostream>
using namespace std;
class Node{
private:
    int data;
public:
    Node* ne;
    Node* pre;
    //构造函数
    Node(int val):data(val),ne(nullptr),pre(nullptr){}
    //获取数据
    int getData()const{return data;}
    //设置数据
    void setData(int x){data = x;}

};
class List{
private:
    Node* head;
    Node* tail;
    int size;
public:
    //构造函数
    List():head(nullptr),tail(nullptr),size(0){}

    //析构函数
    ~List(){
        Node* current = head;
        while(current!=nullptr){
            Node* next = current->ne;
            delete current;
            current = next;
        }
    }

    //获取链表大小
    int getSize()const{return size;}

    //判断空
    bool isEmpty()const{return size==0;}

    //头插
    void pushFront(int val){
        Node* newNode = new Node(val);
        if(isEmpty()){
            head = newNode;
            tail = head;
        }
        else{
            head->pre = newNode;
            newNode->pre = head;
            head = newNode;
        }
        size++;//不要忘记！！
    }

    //尾插
    void pushBack(int val){
        Node* newNode = new Node(val);
        if(isEmpty()){
            tail = newNode;
            head = tail;
        }
        else{
            tail->ne = newNode;
            newNode->pre = tail;
            tail = newNode;
        }
        size++;//不要忘记！！
    }

    //打印
    void printList(){
        Node* cur = head;
        while(cur!=nullptr){
            cout<<cur->getData()<<" ";
            cur = cur->ne;
        }
        cout<<endl;
    }

    //插入到任意位置
    bool insert(int val,int position){
        if(position<0||position>size){
            cout<<"插入失败，位置错误"<<endl;
            return false;
        }
        if(position==0){
            pushFront(val);
            return true;
        }
        else if(position==size-1){
            pushBack(val);
            return true;
        }
        Node* newNode = new Node(val);
        Node* cur = head;
        for(int i=0;i<position;i++)cur = cur->ne;
        //重点逻辑：
        newNode->pre = cur->pre;
        newNode->ne = cur;
        cur->pre->ne = newNode;
        cur->pre = newNode;

        size++;
        return true;
    }

    //删除节点
    bool remove(int position){
        if(position<0||position>=size){
            cout<<"删除失败，位置错误"<<endl;
            return false;
        }
        Node* toDelete;
        if(position==0){
            toDelete = head;
            head = head->ne;
            if(head!=nullptr)head->pre = nullptr;
            else tail = nullptr;
        }
        else if(position==size-1){
            toDelete = tail;
            tail = tail->pre;
            if(tail==nullptr)head = nullptr;
            else tail->ne = nullptr;
        }
        else{
            toDelete = head;
            for(int i=0;i<position;i++)toDelete = toDelete->ne;
            toDelete->pre->ne = toDelete->ne;
            toDelete->ne->pre = toDelete->pre;
        }
        delete toDelete;
        size--;
        return true;
    }
    
    //查找
    int find(int val){
        Node* cur = head;
        int position = 0;
        while(cur!=nullptr){
            if(cur->getData()==val)return position;
            cur = cur->ne;
            position++;
        }
        return -1;
    }
};


int main(){
    //测试：
    List list;
    list.pushBack(1);
    list.pushFront(50);
    cout<<list.find(2)<<endl;
    cout<<"链表大小："<<list.getSize()<<endl;
    list.remove(1);
    list.printList();
    list.insert(10,0);
    list.insert(99,1);
    list.printList();
    cout<<"99的位置:"<<list.find(99)<<endl;
    cout<<"链表大小："<<list.getSize()<<endl;

}