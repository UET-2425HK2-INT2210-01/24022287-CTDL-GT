#include<iostream>
using namespace std;

int sumDigits(int n) {
    if (n == 0) return 0;
    return n % 10 + sumDigits(n / 10);
}

int main() {
    int n = 1234;
    cout << "Tong cac chu so cua " << n << " la: " << sumDigits(n) << endl; // Output: 10
    return 0;
}
