//문제 13975번 파일 합치기3 -> 우선순위 큐, 자료형 신경써야할듯
#include <queue>
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        cin >> n;
        priority_queue<int>pq;
        int result = 0;
        for(int j = 0;j<n;j++){
            int num;
            cin >> num;
            pq.push(-num);
        }
        while(pq.size() >= 2){
            int num1 = -pq.top();
            pq.pop();
            int num2 = -pq.top();
            pq.pop();
            result+= (num1 + num2);
            pq.push(-(num1 + num2));
        }
        cout << result << "\n";
    }
}