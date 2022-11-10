//문제 11508번 2+1 세일 -> 정렬, 그리디
#include <iostream>
#include <algorithm>
using namespace std;
int num[100001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> num[i];
    }
    sort(num, num + n);
    reverse(num, num + n);
    int result = 0;
    for(int i = 0;i<n;i+=3){
        //3개씩 될 때
        if(i + 2 < n){
            result += num[i];
            result += num[i+1];
        }
        else{
            if(i + 1 < n){
                result += num[i];
                result += num[i+1];
            }
            else
                result += num[i];
        }
    }
    cout << result;
}