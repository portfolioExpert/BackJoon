//문제 1092번 배 -> 그리디
#include <vector>
#include<queue>
vector<int>v, box;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m, time = 0, index = 0;
    cin >> n;
    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    cin >> m;
    sort(v.begin(), v.end());
    reverse(v.begin(),v.end());
    for(int i = 0;i<m;i++){
        int num;
        cin >> num;
        box.push_back(num);
    }
    sort(box.begin(), box.end());
    reverse(box.begin(), box.end());
    if(v[0] < box.front()){
        cout << -1;
        return 0;
    }
    while(box.size() > 0){
        priority_queue<int>nextq;
        for(int i = 0;i<(int)box.size();i++){
            if(v[index] >= box[i]){
                index++;
                box.erase(box.begin() + i);
                i--;
            }
        }
        time++;
        index = 0;
    }
    cout << time;
}