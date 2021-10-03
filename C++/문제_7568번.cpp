#include <iostream>
#include <algorithm>
using namespace std;

//문제 7568번
int main(){
    int n, i, fat[51][2], rank[51], j;
    fill_n(rank, 51, 1);
    cin >> n;
    for(i=0;i<n;i++){
        cin >> fat[i][0] >> fat[i][1];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i == j){

            }
            if(fat[i][0] < fat[j][0]){
                if(fat[i][1] < fat[j][1]){
                    rank[i]++;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        cout << rank[i] << "\n";
    }
    return 0;
}