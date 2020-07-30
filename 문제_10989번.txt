#include <iostream>
#include <algorithm>
using namespace std;

//문제 10989번 counting sort로 해결
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,j, i, count[10001] = {0}, number;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> number;
        count[number-1]++;
    }
    for(i=0;i<10001;i++){
        if(count[i] != 0){
            for(j=0;j<count[i];j++){
                cout << i+1 << "\n";
            }
        }
    }
    return 0;
}