//문제 1107번 리모컨 -> 브루트포스
#include<cmath>
#include <string>
typedef long long ll;
bool visit[10];
int n, m, len, result = 987654321;
//길이를 알아보는 것
int getlen(int number){
    if(number == 0){
        //고장났으면 길이 0
        if(visit[number] == 1)
            return 0;
        else
            return 1;
    }
    //길이 측정
    int len = 0;
    while(number){
        if(visit[number % 10] == 1)
            return 0;
        len++;
        number/=10;
    }
    return len;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int num;
        cin >> num;
        visit[num] = 1;
    }
    result = abs(n - 100);
    //처음에 갈 수 있는 채널을 선택한 뒤
    for(int i = 0;i<=1000000;i++){
        int c = i;
        int len = getlen(c);
        if(len > 0){
            int dis = abs(c - n);
            result = min(result, dis + len);
        }
    }
    cout << result;
}