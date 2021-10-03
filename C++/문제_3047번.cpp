#include <iostream>
#include <algorithm>
using namespace std;

//문제 3047번
#include <string>
#include <queue>
queue<pair<int, char>> q;
int main(){
    int i, arr[3];
    string str;
    for(i=0;i<3;i++){
        cin >> arr[i];
    }
    sort(arr, arr+3);
    for(i=0;i<3;i++){
        q.push({arr[i], 65+i});
    }
    cin >> str;
    for(i = 0;i<3;i++){
        while(1){
            if(q.front().second == str[i]){
                cout << q.front().first << " ";
                break;
            }
            else{
                int n = q.front().first;
                char ch = q.front().second;
                q.pop();
                q.push({n, ch});
            }
        }
    }
    return 0;
}