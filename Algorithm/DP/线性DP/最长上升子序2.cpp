//https://ac.nowcoder.com/acm/problem/226831
//解法二：贪心 + 二分
//维护一个数组f，位数表示长度为几位，存的数表示当前长度的最小末尾值
//每进入遍历一个a[i]值，就去判断它该更新在哪里
#include<iostream>
using namespace std;
const int N = 1e5+10;
int f[N],a[N];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int length = 0;
    for(int i=1;i<=n;i++){
        if(length == 0||a[i]>f[length]){
            f[++length] = a[i];
            continue;
        }
        int l = 1, r = length;
        while(l<r){
            int mid = (l+r)/2;
            if(a[i]<=f[mid]){
                r = mid;
            }
            else l = mid + 1;
        }
        f[l] = a[i];
    }
    cout<<length<<endl;
}