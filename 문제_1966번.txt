#include <iostream>
#include <algorithm>
using namespace std;

//문제 1966번
#include <queue>
#include <vector>
int main(){
    int n, m ,i, t, j, cnt = 1, num;
    cin >> t;
    for(i=0;i<t;i++){
        cin >> n >> m;
        vector <int> v;//안에서 선언 해주면 자동 초기화
        queue <pair<int, int >> q;
        for(j = 0;j<n;j++){
            cin >> num;
            v.push_back(num);//중요도만 저장
            q.push({num, j});//중요도와 인덱스를 저장
        }
        sort(v.begin(), v.end());//중요도를 오름차순으로 정렬하고
        for(;;){
            if(v.back() == q.front().first && q.front().second == m){//중요도가 같고 맨처음 인덱스과 저장한 인덱스가 같을때 출력
                cout << cnt << "\n";
                break;
            }
            else if(v.back() > q.front().first){//현재 꺼내야할 중요도보다 작은 경우 큐에 다시 넣음
                int save = q.front().first;
                int index = q.front().second;
                q.pop();
                q.push({save, index});
            }
            else{//꺼내야할 중요도와 큐 중요도가 같으면 꺼냄
                q.pop();
                v.pop_back();
                cnt++;
            }
        }
        cnt = 1;
    }
}