#include <iostream>
#include <algorithm>
using namespace std;

//문제 14492번
int main(){
    int size, i, j,k, a[301][301], b[301][301], c[301][301] = {0}, result = 0;
    cin >> size;
    for(i=1;i<=size;i++){
        for(j=1;j<=size;j++){
            cin >> a[i][j];
        }
    }
    for(i=1;i<=size;i++){
        for(j=1;j<=size;j++){
            cin >> b[i][j];
        }
    }
    for(i=1;i<=size;i++){
        for(j=1;j<=size;j++){
            for(k=1;k<=size;k++){
                c[i][j] |= a[i][k] & b[k][j];
            }
        }
    }
    for(i=1;i<=size;i++){
        for(j=1;j<=size;j++){
            if(c[i][j] == 1)result++;
        }
    }
    cout << result;
    return 0;
}