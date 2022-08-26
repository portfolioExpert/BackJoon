#include <iostream>
#include <algorithm>
using namespace std;

//문제 1059번 좋은 구간 -> 브루트포스, 정렬
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int result = 0;
    int l, n;
    cin >> l;
    int num[51];
    for(int i = 0;i<l;i++){
        cin >> num[i];
    }
    cin >> n;
    sort(num, num+l);
    //왼쪽
    for(int i = 1;i<num[0];i++){
        for(int j = i+1;j<num[0];j++){
            if(n >= i && n <= j)
                result++;
        }
    }
    //가운데
    for(int i = 0;i<l-1;i++){
        int left = num[i]+1;
        int right = num[i+1];
        for(int j = left;j<right-1;j++){
            for(int k = j + 1;k<right;k++){
                if(n >= j && n <= k)
                    result++;
            }
        }
    }
    //오른쪽
    for(int i = num[l-1] + 1;i<1000;i++){
        for(int j = i+1;j<=1000;j++){
            if(n >= i && n <= j)
                result++;
        }
    }

    cout << result;
}