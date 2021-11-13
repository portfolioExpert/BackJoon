//문제 15662번 톱니바퀴2 -> 구현
#include <vector>
char topni[1001][9];
void rotate(vector<pair<int,int>>v){
    for(int i = 0;i<(int)v.size();i++){
        int number = v[i].first;
        //반시계 일때
        if(v[i].second == -1){
            int save = topni[number][0];
            for(int j = 0;j<7;j++){
                topni[number][j] = topni[number][j+1];
            }
            topni[number][7] = save;
        }
        else{
            int save = topni[number][7];
            for(int j = 7;j>=1;j--){
                topni[number][j] = topni[number][j-1];
            }
            topni[number][0] = save;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 1;i<=t;i++){
        for(int j = 0;j<8;j++){
            cin >> topni[i][j];
        }
    }
    int k;
    cin >> k;
    for(int i = 0;i<k;i++){
        int num, direct;
        //방향은 1은 시계, -1은 반시계
        cin >> num >> direct;
        vector<pair<int,int>>rotatearr;
        rotatearr.push_back({num, direct});
        //왼쪽
        int leftbefore = direct;
        for(int j = num;j>=2;j--){
            //같은 극이면 멈추고
            if(topni[j][6] == topni[j-1][2])
                break;
            //다른 극이면 해당 방향과 반대
            else{
                rotatearr.push_back({j - 1, -leftbefore});
                leftbefore = -leftbefore;
            }
        }
        //오른쪽
        int rightbefore = direct;
        for(int j = num;j<t;j++){
            //같은 극이면 멈추고
            if(topni[j][2] == topni[j+1][6])
                break;
            //다른 극이면 해당 방향과 반대
            else{
                rotatearr.push_back({j + 1, -rightbefore});
                rightbefore = -rightbefore;
            }
        }
        //변환
        rotate(rotatearr);
    }
    int cnt = 0;
    for(int i = 1;i<=t;i++){
        if(topni[i][0] == '1')
            cnt++;
    }
    cout << cnt;
}