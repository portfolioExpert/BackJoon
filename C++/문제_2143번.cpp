//문제 2143번 두 배열의 합 -> 누적합, 이분탐색, 맵
//누적합을 구해서 맵으로 저장한 뒤 탐색을 이분탐색으로 하여 개수를 구하는 문제로
//요즘 발상하긴 어려운 문제 같다.
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
int A, B;
int aSum[1001];
int bSum[1001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    map<int, int>ma;//A 부분합, 개수
    map<int, int>mb;
    long long result = 0;
    int t, n, m;
    cin >> t >> n;
    for(int i = 1;i<=n;i++){
        cin >> A;
        aSum[i] = aSum[i-1] + A;
    }
    cin >> m;
    for(int i = 1;i<=m;i++){
        cin >> B;
        bSum[i] = bSum[i-1] + B;
    }

    //A 부분합 개수 파악
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<i;j++){
            int preSum = aSum[i] - aSum[j];
            if(ma[preSum] == 0)
                ma[preSum] = 1;
            else
                ma[preSum] = ma[preSum] + 1;
        }
    }
    //B 부분합 개수 파악
    for(int i = 1;i<=m;i++){
        for(int j = 0;j<i;j++){
            int preSum = bSum[i] - bSum[j];
            if(mb[preSum] == 0)
                mb[preSum] = 1;
            else
                mb[preSum] = mb[preSum] + 1;
        }
    }
    //A: 1-2, 2-1, 3-2, 4-2, 5-1, 6-1, 7-1
    //b: 1-1, 2-1, 3-1, 4-1, 5-1, 6-1
    //이러면 문제가 1부터 1000까지 부분합을 보면 총 22만개가 나와 시간 초과가됨
    //-> nlogn으로 풀면 되는데 vector로 모두 넣고

    vector<pair<int,int>>v1;//값 개수
    vector<pair<int,int>>v2;//값 개수
    for(auto iter = ma.begin();iter != ma.end(); iter++){
        v1.push_back({iter->first, iter->second});
    }
    for(auto iter = mb.begin();iter != mb.end(); iter++){
        v2.push_back({iter->first, iter->second});
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for(int i = 0;i<v1.size();i++){
        int Avalue = v1[i].first;
        int Acnt = v1[i].second;
        int left = 0;
        int right = (int)(v2.size()-1);
        int mid = (left + right) / 2;
        while(left <= right){
            mid = (left + right) / 2;
            if(v2[mid].first + Avalue > t){
                right = mid - 1;
            }
            else if(v2[mid].first + Avalue < t)
                left = mid + 1;
            else
                break;

        }
        if(v2[mid].first + Avalue == t){
            result+=(long long) Acnt * v2[mid].second;
        }
    }
    cout << result;
}