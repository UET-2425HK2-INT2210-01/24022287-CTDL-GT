#include<iostream>
using namespace std;
int tinhgiaithua(int n){
    if(n<=1) return n;
    return n*tinhgiaithua(n-1);
    int main() {
        int n=5;
        cout<<"Giai thua cua"<<n<<"la:"<<tinhgiaithua(n);
    }
    return 0;
}
