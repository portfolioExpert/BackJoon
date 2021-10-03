#include <iostream>
#include <algorithm>
using namespace std;

//문제 1992번
char arr[64][64];
void quadtree(int x, int y, int length);
int main(){
    int n, i, j;
    cin >> n;
    for(i = 0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    quadtree(0, 0, n);
    return 0;
}
void quadtree(int x, int y, int length){
    bool check = 1;
    char state = arr[y][x];
    int i, j;
    for(i=y;i<y+length;i++){
        for(j=x;j<x+length;j++){
            if(state != arr[i][j]){
                check = 0;
                break;
            }
        }
    }
    if(check == 1){
        cout << state;
    }
    else{
        cout <<"(";
        quadtree(x, y, length / 2);
        quadtree(x+length/2, y, length/2);
        quadtree(x, y + length / 2, length/2);
        quadtree(x+length/2, y+length/2, length/2);
        cout << ")";
    }
}