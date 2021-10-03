#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//문제 2798번
int main(){
    int n, big, i, j, k, num[101], sum = 0;
    cin >> n >> big;
    for(i=0;i<n;i++){
        cin >> num[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            for(k=j+1;k<n;k++){
                if((num[i] + num[j] + num[k] <= big) && (num[i] + num[j] + num[k] > sum))
                    sum = num[i] + num[j] + num[k];
            }
        }
    }
    printf("%d", sum);
    return 0;
}