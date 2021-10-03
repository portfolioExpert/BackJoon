#include <iostream>
#include <algorithm>
using namespace std;

//문제 1920번
int arr[100001];
bool bs(int size, int search);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m, i, num;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    cin >> m;
    for(i = 0;i<m;i++){
        cin >> num;
        if(bs(n, num) == 1)
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
    return 0;
}
bool bs(int size, int search){
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    while(end - start >= 0){
        if(search > arr[mid]){
            start = mid+1;
        }
        else if(search == arr[mid])
            return 1;
        else
            end = mid - 1;
        mid = (start + end)/2;
    }
    return 0;
}