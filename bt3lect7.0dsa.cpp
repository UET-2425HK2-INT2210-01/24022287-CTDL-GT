#include<iosstream>
using namespace std;

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 6;
    cout << "So Fibonacci thu " << n << " la: " << fibonacci(n) << endl; // Output: 8
    return 0;
}
