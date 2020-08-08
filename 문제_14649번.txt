#include <iostream>
#include <algorithm>
using namespace std;

//문제 14649번
int main(){
    int n, i, po1[101],j, cntb = 0 ,cntg = 0, cntr = 0;
    double money;
    char color[101], po2[101];
    fill_n(color, 101, 'b');
    cin >> money;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> po1[i] >> po2[i];
    }
    for(i=1;i<=n;i++){
        if(po2[i] == 'R'){
            for(j=po1[i]+1;j<=100;j++){
                if(color[j] == 'b')
                    color[j] = 'r';
                else if(color[j] == 'r')
                    color[j] = 'g';
                else if(color[j] == 'g')
                    color[j] = 'b';
            }
        }
        else if(po2[i] == 'L'){
            for(j=po1[i]-1; j>=1;j--){
                if(color[j] == 'b')
                    color[j] = 'r';
                else if(color[j] == 'r')
                    color[j] = 'g';
                else if(color[j] == 'g')
                    color[j] = 'b';
            }
        }
    }
    for(i=1;i<=100;i++){
        if(color[i] == 'r')cntr++;
        else if(color[i] == 'b')cntb++;
        else if(color[i] == 'g')cntg++;
    }
    printf("%.2lf\n%.2lf\n%.2lf", (double)money * cntb / 100, (double)money * cntr / 100, (double)money * cntg / 100);
    return 0;
}