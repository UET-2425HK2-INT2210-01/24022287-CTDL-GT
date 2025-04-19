#include<iostream>
using namespace std;
int tinhluythua(int x,int n)
    if(n==0) return 1;
    return x*tinhluythua(x,n-1);
    }
    int main(){
         int x = 2, n = 3;
    cout << x << "^" << n << " = " << tinhluythua(x, n) << endl;
    return 0;
    }

