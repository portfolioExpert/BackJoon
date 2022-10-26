#include <iostream>
#include <algorithm>
using namespace std;

//문제 1431번 시리얼 번호 -> 정렬
#include <cstring>
#include <string>
#include <string.h>
int totalSum(string str){
    int res = 0;
    for(int i = 0;i<str.size();i++){
        if(str[i] >= '0' && str[i] <= '9'){
            res+= str[i] - 48;
        }
    }
    return res;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    string str[51];
    for(int i = 0;i<n;i++){
        cin >> str[i];
    }
    sort(str, str + n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n-1;j++){
            //길이가 짧은 것
            if(str[j].length() > str[j+1].length()){
                string save = str[j+1];
                str[j+1] = str[j];
                str[j] = save;
            }
            //길이가 같다면
            else if(str[j].length() == str[j+1].length()){
                int left = totalSum(str[j]);
                int right = totalSum(str[j+1]);
                if(left > right){
                    string save = str[j+1];
                    str[j+1] = str[j];
                    str[j] = save;
                }
            }
        }
    }
    for(int i = 0;i<n;i++){
        cout << str[i] << "\n";
    }
}