//문제 21610번 마법사 상어와 비바라기 -> 시뮬레이션
#include <vector>
int map[51][51];
int n, m;
int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
vector<pair<int,int>>cloud;
void move(int d, int s){
    for(int i = 0;i<(int)cloud.size();i++){
        int gox = cloud[i].first;
        int goy = cloud[i].second;
        for(int j = 0;j<s;j++){
            gox+= dx[d];
            goy+= dy[d];
            if(gox < 1)
                gox = n;
            if(gox > n)
                gox = 1;
            if(goy < 1)
                goy = n;
            if(goy > n)
                goy = 1;
        }
        cloud[i].first = gox;
        cloud[i].second = goy;
        map[gox][goy]++;
    }
}
void watercopy(){
    for(int i = 0;i<(int)cloud.size();i++){
        int gox = cloud[i].first;
        int goy = cloud[i].second;
        for(int j = 2;j<=8;j+=2){
            int gx = gox + dx[j];
            int gy = goy + dy[j];
            if(gx >= 1 && gx <= n && gy >= 1 && gy <= n && map[gx][gy] > 0){
                map[gox][goy]++;
            }
        }
    }
}
void makeCloud(){
    vector<pair<int,int>>newCloud;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(map[i][j] >= 2){
                bool flag = true;
                for(int k = 0;k<(int)cloud.size();k++){
                    if(i == cloud[k].first && j == cloud[k].second){
                        flag = 0;
                        break;
                    }
                }
                if(flag){
                    newCloud.push_back({i,j});
                    map[i][j] -= 2;
                }
            }
        }
    }
    cloud = newCloud;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin >> map[i][j];
        }
    }
    cloud.push_back({n,1});
    cloud.push_back({n,2});
    cloud.push_back({n-1, 1});
    cloud.push_back({n-1, 2});
    for(int i = 0;i<m;i++){
        int d, s;
        cin >> d >> s;
        //1. 움직이고, 2. 물 증가
        move(d, s);
        //물 복사 마법
        watercopy();
        //구름 만들고 그 칸 -2
        makeCloud();
    }
    int sum = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            sum+=map[i][j];
        }
    }
    cout << sum;
}