//문제 1748번 수 이어 쓰기 1 -> 수학
int getSize(int num){
    int result = 0;
    while(num){
        num/=10;
        result++;
    }
    return result;
}
int main(){
    int n;
    cin >> n;
    int length = getSize(n);
    switch(length){
        case 1: cout << n;
            break;
        case 2: cout << 9 + (n - 9) * 2;
            break;
        case 3: cout << 9 + (90 * 2) + (n - 99) * 3;
            break;
        case 4: cout << 9 + (90 * 2 + 900 * 3) + (n - 999) * 4;
            break;
        case 5: cout << 9 + (90 * 2 + 900 * 3 + 9000 * 4) + (n-9999) * 5;
            break;
        case 6: cout << 9 + (90 * 2 + 900 * 3 + 9000 * 4 + 90000 * 5) + (n-99999) * 6;
            break;
        case 7: cout << 9 + (90 * 2 + 900 * 3 + 9000 * 4 + 90000 * 5 + 900000 * 6) + (n-999999) * 7;
            break;
        case 8 : cout << 9 + (90 * 2 + 900 * 3 + 9000 * 4 + 90000 * 5 + 900000 * 6 + 9000000 * 7) + (n - 9999999) * 8;
            break;
        case 9: cout << 9 + (90 * 2 + 900 * 3 + 9000 * 4 + 90000 * 5 + 900000 * 6 + 9000000 * 7 + 90000000 * 8) + (n - 99999999) * 9;
            break;
    }
}