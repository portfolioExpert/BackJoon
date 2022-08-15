//문제 10867번 중복 빼고 정렬하기 -> 정렬
#include <set>
set<int>s;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        s.insert(num);
    }
    for(int y : s){
        cout << y << " ";
    }
}