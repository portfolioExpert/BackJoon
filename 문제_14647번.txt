#include <iostream>
#include <algorithm>
using namespace std;

//문제 14647번
int main(){
    int n, m, i ,j, num[501][501], row = 0 , col = 0, big = -1, total = 0;
    cin >> n >> m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> num[i][j];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(num[i][j] % 10 == 9){
                row++;
                total++;
            }
            if(num[i][j]/10 % 10 == 9){
                row++;
                total++;
            }
            if(num[i][j]/100 % 10 == 9){
                row++;
                total++;
            }
            if(num[i][j]/1000 % 10 == 9){
                row++;
                total++;
            }
        }
        big = max(big, row);
        row = 0;
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(num[j][i] % 10 == 9)
                col++;
            if(num[j][i]/10 % 10 == 9)
                col++;
            if(num[j][i]/100 % 10 == 9)
                col++;
            if(num[j][i]/1000 % 10 == 9)
                col++;
        }
        big = max(big, col);
        col = 0;
    }
    cout << total - big;
    return 0;
}
//반례
//12
//10 20 9 10 20 30 50 40 41 42 37 60 > 8개