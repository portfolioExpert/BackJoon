//문제 9375번 패션왕 신해빈 -> 맵, 역의 경우의 수
#include <map>
int main(){
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        int n;
        cin >> n;
        map<string,int>m;
        for(int j = 0;j<n;j++){
            string str1, str2;
            cin >> str1 >> str2;
            m[str2]++;
        }
        int sum = 1;
        for(auto y : m){
            sum *= (y.second + 1);
        }
        cout << sum - 1 << "\n";
    }
}