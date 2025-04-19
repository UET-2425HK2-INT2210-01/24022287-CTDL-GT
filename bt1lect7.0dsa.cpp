#include<iostream>
using namespace std;
int sum(int n) {
    if(n<=1) return n;
    return n+ sum(n-1);
}
int main() {
    int n = 5;
    cout << "Tong tu 1 den " << n << " la: " << sum(n) << endl; // Output: 15
    return 0;
}
