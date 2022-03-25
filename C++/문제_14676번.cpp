//문제 14676번 영우는 사기꾼 -> 위상정렬
#include <vector>
#include <queue>
int visit[100001];
int built[100001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    queue<int>q;
    vector<int>v[100001];
    for(int i = 0;i<m;i++){
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        visit[to]++;
    }
    for(int i = 0;i<k;i++){
        int command, num;
        cin >> command >> num;
        //건설
        if(command == 1){
            if(visit[num] <= 0){
                built[num]++;
                //최대 3개
                //이미 지어져있으면 다음 위상을 감소시킬 필요가 없다.
                if(built[num] >= 2)
                    continue;
                for(int y : v[num]){
                    visit[y]--;
                }
            }
            else{
                cout << "Lier!";
                return 0;
            }
        }
        //파괴
        else if(command == 2){
            if(built[num] >= 1){
                built[num]--;
                if(built[num] <= 0){
                    for(int y : v[num]){
                        visit[y]++;
                    }
                }
            }
            else{
                cout << "Lier!";
                return 0;
            }
        }
    }
    cout << "King-God-Emperor";
}
//마지막 반례 -> 이미 지은 것 파괴 후 다시 건설 할 때 위상 체크
/*
 3 2 4
 1 2
 2 3
 1 1
 1 2
 2 1
 1 2
 */