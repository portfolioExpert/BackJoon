//문제 4948번 베르트랑 공준 -> 에라토스테네스의 체
#include <cstring>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    bool arr[250000];
    memset(arr, 0, sizeof(arr));
    arr[1] = true;
    for(int i = 2;i<=250000;i++){
        if(arr[i] == true)
            continue;
        for(int j = i + i;j<=250000;j+=i){
            arr[j] = true;
        }
    }
    int num;
    while(1){
        cin >> num;
        if(num == 0)
            return 0;
        int sum = 0;
        for(int i = num + 1;i<=num*2;i++){
            if(arr[i] == false)
                sum++;
        }
        cout << sum << "\n";
    }
}