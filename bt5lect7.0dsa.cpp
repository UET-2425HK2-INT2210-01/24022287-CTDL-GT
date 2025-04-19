#include<iostream>
using namespace std;
int countDigits(int n) {
    if (n < 10) return 1;
    return 1 + countDigits(n / 10);
}

int main() {
    int n = 12345;
    cout << "So chu so cua " << n << " la: " << countDigits(n) << endl;
}
