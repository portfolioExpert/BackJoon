//문제 2503번 숫자 야구 -> 브루트 포스
typedef struct info{
    int num, st, ball;
}info;
#include <vector>
vector<int>result;
bool visit[1001];
bool check(info ball, int num){
    int third = ball.num % 10;
    int second = (ball.num / 10) % 10;
    int first = (ball.num / 100) % 10;
    int st = 0;
    int bl = 0;

    //스트라이크 체크
    if(first == (num/100) % 10)
        st++;
    if(second == (num / 10) % 10)
        st++;
    if(third == num % 10)
        st++;

    //볼 체크
    if(first == (num / 10) % 10)
        bl++;
    if(first == num % 10)
        bl++;

    if(second == (num / 100) % 10)
        bl++;
    if(second == num % 10)
        bl++;

    if(third == (num / 100) % 10)
        bl++;
    if(third == (num / 10) % 10)
        bl++;

    if(ball.st == st && ball.ball == bl)
        return true;

    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    info ballinfo[101];
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int num, st, ball;
        cin >> num >> st >> ball;
        ballinfo[i].num = num;
        ballinfo[i].st = st;
        ballinfo[i].ball = ball;
    }
    for(int i = 123;i<=999;i++){
        //0이 있으면 안되고
        if(i % 10 == 0 || (i / 10) % 10 == 0 || (i/100) % 10 == 0)
            continue;
        //서로 다른 숫자
        int third = i % 10;
        int second = (i / 10) % 10;
        int first = (i / 100) % 10;

        if(first == second || first == third || second == third)
            continue;

        bool flag = true;
        for(int j = 0;j<n;j++){
            if(!check(ballinfo[j], i)){
                flag = false;
                break;
            }
        }
        if(flag)
            result.push_back(i);
    }
    cout << result.size();
}