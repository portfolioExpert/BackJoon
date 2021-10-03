#include <iostream>
#include <algorithm>
using namespace std;

//문제 13335번
#include <queue>
queue <int> q;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, w, l, result = 0, state = 0, tr;
    cin >> n >> w >> l;
    while(n){
        cin >> tr;
        n--;
        while(1){
            if(q.empty()){//다리에 아무것도 없으면 무조건 넣어줌
                q.push(tr);
                state+=tr;
                result++;
                break;
            }
            else if(q.size() == w){//다리길이에 맞게 꽉찼을 경우 빼줌
                state-=q.front();
                q.pop();
            }
            else{
                if(state + tr > l){//다음것과 합쳤을 경우 하중이 더 클 경우 0을 넣어서 옆으로 밀어줌
                    q.push(0);
                    result++;
                }
                else{//그게 아니면 넣어줌
                    q.push(tr);
                    state+=tr;
                    result++;
                    break;
                }
            }
        }
    }
    cout << result + w;//다리 길이만큼 건너감
    return 0;
}