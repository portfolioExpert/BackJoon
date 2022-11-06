//문제 2304번 창고 다각형 -> 스택
#include <vector>
#include <stack>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    vector<pair<int,int>>v;
    stack<pair<int,int>>s;//왼쪽 아래, 높이
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int l, h;
        cin >> l >> h;
        v.push_back({l, h});
    }
    sort(v.begin(), v.end());
    int result = 0;
    int maxheight = 0;
    //왼쪽부터 큰 기둥으로
    for(int i = 0;i<v.size();i++){
        //비어있고
        if(s.empty()){
            s.push({v[i]});
            continue;
        }
        //큰 기둥을 만나면
        if(s.top().second <= v[i].second){
            result+= (v[i].first - s.top().first) * s.top().second;
            s.pop();
            s.push(v[i]);
            maxheight = max(maxheight, v[i].second);
        }
    }
    if(s.size() == 1)
        result+=s.top().second;
    //오른쪽부터 큰 기둥으로
    stack<pair<int,int>>ri;
    for(int i = (int)v.size() - 1;i >= 0 ;i--){
        //비어있고
        if(ri.empty()){
            ri.push({v[i].first + 1, v[i].second});
            continue;
        }
        if(ri.top().second == maxheight)
            break;
        //큰 기둥을 만나면
        if(ri.top().second <= v[i].second){
            result+= (ri.top().first - (v[i].first + 1)) * ri.top().second;
            ri.pop();
            ri.push({v[i].first + 1, v[i].second});
        }
    }
    cout << result;
}