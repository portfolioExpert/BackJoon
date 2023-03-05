#include <iostream>
#include <algorithm>
using namespace std;

//문제 1058번 친구 -> 브루트포스
//2-친구 조건
//두 사람이 친구, A와 B의 공통 친구 C가 존재 해야한다.
char map[51][51];
int result = 0;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        int sum = 0;
        //0번부터 체크
        for(int j = 0;j<n;j++){
            //같으면 자기자신이므로 패스
            if(i == j)
                continue;
            //1번조건 친구면 2-친구
            if(map[i][j] == 'Y')
                sum++;

            //2번조건 둘다 아는 친구가 있어야 한다.
            //0, 2번을 동시에 아는 사람이 있는지 체크해야한다.
            else{
                for(int k = 0;k<n;k++){
                    if(map[k][i] == 'Y' && map[k][j] == 'Y'){
                        sum++;
                        break;
                    }
                }
            }
        }
        result = max(result, sum);
    }
    cout << result;
}