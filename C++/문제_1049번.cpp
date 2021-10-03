#include <iostream>
#include <algorithm>
using namespace std;

//문제 1049번
int main(){
    int n, m, i , pack[51], piece[51], price = 999999999, sum = 0, packsmall = 999999999, piecesmall = 999999999;
    cin >> n >> m;
    for(i=0;i<m;i++){
        cin >> pack[i] >> piece[i];
        packsmall = min(pack[i],packsmall);
        piecesmall = min(piece[i], piecesmall);
    }
    if(n<6){
        price = min(packsmall, piecesmall * n);
    }
    else{
        sum+=min(packsmall,piecesmall*6) * (n/6);
        sum+=min(packsmall,piecesmall*(n % 6));
        price = min(price, sum);
    }
    cout << price;
    return 0;
}