#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//문제 10610번
bool big(int x, int y);
int main(){
    int i = 0, check = 0, k, sum = 0;
    char first[100001];
    fill_n(first, 100001, '*');
    for(i=0;;i++){
        cin >> first[i];
        if(first[i] == '*')
            break;
    }
    for(k=0;;k++){
        sum+=first[k]-'0';
        if(first[k] == '0'){
            check = 1;
        }
        if(k == i)break;
    }
    sort(first, first+i, big);
    if(check == 1 && sum % 3 == 0){
        for(int j = 0;j<i;j++){
            cout << first[j];
        }
    }
    else
        cout << -1;
    return 0;
}
bool big(int x, int y){
    return x > y;
}