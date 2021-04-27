#include <iostream>
#include <algorithm>
using namespace std;

//문제 1929번
bool arr[1000001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i, n, m;
    cin >> n >> m;
    for(i = 2;i<=m;i++){//2부터 m까지 소수 체크를 위해서 방문처리
        arr[i] = 1;
    }
    for(int i = 2; i*i<=m;i++){//2부터 소수판별하면서 지워나간다
        if(arr[i]){
            if(i * i > 1000000)//지우는 값이 1000000이 넘어가면 멈춘다
                break;
            else{
                for(int j = i * i; j<=m;j+=i){//소수인 배수들은 전부 지운다
                    arr[j] = 0;
                }
            }
        }
    }
    for(i = n; i<=m;i++){
        if(arr[i] == 1)
            cout << i << "\n";
    }
    return 0;
}