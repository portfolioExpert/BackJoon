//문제 4673번 셀프 넘버 -> 구현
#include <cstring>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    bool visit[10001];
    memset(visit, 0 ,sizeof(visit));
    for(int i = 1;i<=10000;i++){
        if(visit[i])
            continue;
        int make = i;
        while(make<=10000){
            int num = make;
            while(num){
                make += num % 10;
                num/=10;
            }
            if(make > 10000)
                break;
            visit[make] = true;
        }
    }
    for(int i = 1;i<=10000;i++){
        if(visit[i] == 0)
            cout << i << "\n";
    }
}