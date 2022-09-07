//문제 18111번 마인크래프트 -> 브루트 포스
//틀렸습니다 원인은 맵을 입력받고 차례대로 본건
//해법은 큰 값 순서대로 처리해야한다.
#include <vector>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n ,m ,b;
    int result1 = 987654321, result2 = 0;
    vector<int>v;
    cin >> n >> m >> b;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            int num;
            cin >> num;
            v.push_back(num);
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    //0부터 256까지 높이를 다 본다
    for(int i = 0;i<=256;i++){
        int have = b;
        int time = 0;
        bool flag = true;
        for(int j = 0;j<v.size();j++){
            //같으면 패스
            if(v[j] == i)
                continue;
            //제거
            if(v[j] > i){
                time+= (v[j] - i) * 2;
                have+=(v[j] - i);
            }
            //블록 쌓기
            else if(v[j] < i){
                //가지고 있는 것 보다 쌓아야할 것이 많다면 그 값이 안되니 멈춤
                if(have < i - v[j]){
                    flag = false;
                    break;
                }
                time+= i - v[j];
                have-=i-v[j];
            }
        }
        if(flag && result1 >= time){
            result1 = time;
            result2 = i;
        }
    }
    cout << result1 << " " << result2;
}