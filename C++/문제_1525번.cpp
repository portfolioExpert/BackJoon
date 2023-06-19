#include <iostream>
#include <algorithm>
using namespace std;

//문제 1525번 퍼즐 -> BFS
//방문처리가 꽤 어렵게 해야되서 생각하기 쉽지 않다.
#include <set>
#include <queue>
set<int>s;
int arr[9];
//위는 -3, 아래 +3, 오른 + 1, 왼 -1
int dx[4] = {-3, 3, 1, -1};
int bfs(int start){
    s.insert(start);
    queue<pair<string,int>>q;
    q.push({to_string(start), 0});
    while(!q.empty()){
        int cnt = q.front().second;
        string now = q.front().first;
        q.pop();
        if(now == "123456780")
            return cnt;
        int gox = 0;//0의 원래 인덱스
        for(int i = 0;i<now.size();i++){
            if(now[i]=='0'){
                gox = i;
                break;
            }
        }
        for(int i = 0;i<4;i++){
            int next = gox + dx[i];
            //왼쪽은 -1하면 안되고
            if(dx[i] == -1 && gox % 3 == 0)
                continue;
            //오른쪽은 +1하면 안되고
            if(dx[i] == 1 && gox % 3 == 2)
                continue;
            if(next >= 0 && next < 9){
                string nextStr = now;
                swap(nextStr[gox], nextStr[next]);
                if(s.find(stoi(nextStr)) == s.end()){
                    q.push({nextStr, cnt + 1});
                    s.insert(stoi(nextStr));
                }
            }
        }
    }
    return -1;
}
int main(){
    string str="";
    for(int i = 0;i<9;i++){
        cin >> arr[i];
        str+=arr[i] + '0';
    }
    cout << bfs(stoi(str));
}