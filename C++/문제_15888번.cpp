#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    //허근 경우
    if(b*b -4 * a * c <= 0){
        cout << "둘다틀렸근";
        return 0;
    }
    int num[3];
    //두 근의 합, 곱 공식이 분수일 경우
    double sum = (double)-b/a, mul = (double)c/a;
    if(sum != (int)sum || mul != (int)mul){
        cout << "둘다틀렸근";
        return 0;
    }
    int index = 0;
    for(int i = -100;i<=100;i++){
        if(a * i * i + b * i + c == 0){
            num[index++] = i;
        }
    }
    //근이 없을 경우
    if(index == 0){
        cout << "둘다틀렸근";
        return 0;
    }
    //정수근 일 경우
    for(int i = 0;i<index;i++){
        if(num[i] == 2 || num[i] == 4 || num[i] == 8 || num[i] == 16 || num[i] == 32 || num[i] == 64){
            continue;
        }
        cout << "정수근";
        return 0;
    }
    cout << "이수근";
    return 0;
}