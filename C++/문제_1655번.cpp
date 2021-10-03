//문제 1655번 가운데를 말해요
#include <queue>
#include <cmath>
priority_queue<int>lpq;//최대힙
priority_queue<int>rpq;//최소힙
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    int middle = 0;
    cin >> n;
    for(int i = 1;i<=n;i++){
        int num;
        cin >> num;
        if(lpq.empty() && rpq.empty()){
            lpq.push(num);
            middle = num;
        }
        else{
            if(num <= middle)
                lpq.push(num);
            else
                rpq.push(-num);
            //미들을 기준으로 작은것은 왼쪽 큰 것은 오른쪽으로 분류
            if(lpq.size() < rpq.size()){
                while(lpq.size()<=rpq.size()){
                    int getter = -rpq.top();
                    rpq.pop();
                    lpq.push(getter);
                }
            }
            else{
                //총 개수가 홀수든 짝수든 상관없이 무조건 왼쪽을 크게 둘 것
                while(lpq.size() > rpq.size() + 1){
                    int getter = lpq.top();
                    lpq.pop();
                    rpq.push(-getter);
                }
            }
            middle = lpq.top();
        }
        cout << middle << "\n";
    }
}