//문제 2740번 행렬 곱셈 -> 구현
#include <iostream>
#include <algorithm>
using namespace std;
int A[101][101];
int B[101][101];
int result[101][101];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n,m,k;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> A[i][j];
        }
    }
    cin >> m >> k;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<k;j++){
            cin >> B[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<k;j++){
            for(int t = 0; t<m;t++){
                result[i][j] += A[i][t] * B[t][j];
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<k;j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}