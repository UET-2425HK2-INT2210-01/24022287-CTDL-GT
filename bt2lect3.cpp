Thuật toán 1: vòng lặp
    hàm lũy thừa(n)
    lưu kết quả =1
    cho m=abs(n)
    cho vòng lặp i từ 1 đến m làm:
    kết quả =kết quả*2
    nếu n>0 trả lại kết quả
    nếu n<0 trả lại 1.0/(kết quả)
Thuật toán 2 : đệ quy
    hàm lũy thừa đệ quy(n)
    nếu n=0 trả về 1
    m=abs(n)
    lấy một nửa =lũy thừa đệ quy(m/2)
    nếu m %2==0 : kết quả = (một nửa)*(một nửa)
    ngược lại : kết quả =(một nửa)*(một nửa)*2
    nếu n<0 kết quả = 1/(kết quả)
    trả về kết quả
