//문제 1715번 카드 정렬하기 -> 그리디, 우선순위 큐
#include <queue>
priority_queue<int>pq;
int main(){
    int n, result = 0;
    cin >> n;
    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        pq.push(-num);
    }
    while(pq.size() > 1){
        int num1 = -pq.top();
        pq.pop();
        int num2 = -pq.top();
        pq.pop();
        result+=(num1 + num2);
        pq.push(-(num1 + num2));
    }
    cout << result;
}