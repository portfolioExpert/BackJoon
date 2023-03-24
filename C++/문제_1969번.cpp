#include <iostream>
#include <algorithm>
using namespace std;

//문제 1969번 DNA -> 구현, 문자열
#include <cstring>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    string arr[1001];
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    string resultStr ="";
    int cnt[26];
    for(int i = 0;i<m;i++){
        memset(cnt, 0 ,sizeof(cnt));
        for(int j = 0;j<n;j++){
            cnt[arr[j][i] - 'A']++;
        }
        int cntt = 0;
        char ch = '\0';
        for(int j = 0;j<26;j++){
            if(cntt < cnt[j]){
                cntt = cnt[j];
                ch = j + 'A';
            }
        }
        resultStr+=ch;
    }
    int sum = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(resultStr[j] != arr[i][j])
                sum++;
        }
    }
    cout << resultStr << "\n" << sum;
}