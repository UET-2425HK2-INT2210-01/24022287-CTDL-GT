#include <iostream>
using namespace std;

int reverseHelper(int n, int revNum) {
    if (n == 0) return revNum;  // Điều kiện dừng, khi n là 0, trả về revNum
    return reverseHelper(n / 10, revNum * 10 + n % 10);  // Đẩy chữ số cuối vào revNum
}

int reverse(int n) {
    return reverseHelper(n, 0);  // Khởi tạo đối số revNum bằng 0
}

int main() {
    int n = 1234;
    cout << "So dao nguoc cua " << n << " la: " << reverse(n) << endl; // Output: 4321
    return 0;
}
