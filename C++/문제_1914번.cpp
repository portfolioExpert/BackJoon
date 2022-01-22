//문제 1914번 하노이 탑 -> 큰 수 연산, 재귀
#include <cmath>
#include <string>
void hanoi(int n, int left, int center, int right){
    if(n == 1){
        cout << left << " " << right << "\n";
        return;
    }
    else{
        hanoi(n - 1, left, right, center);
        cout << left << " " << right << "\n";
        hanoi(n - 1, center, left, right);
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    string str = to_string(pow(2, n));
    int index = (int)str.find('.');
    str = str.substr(0, index);
    str[str.size() - 1]--;
    cout << str << "\n";
    if(n <= 20)
        hanoi(n, 1, 2, 3);
}