//문제 1254번 팰린드롬 만들기 -> 브루트포스
#include <string>
string str;
int result[1001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> str;
    string before = "", ori = str;
    int ans = 987654321;
    for(int i = 0;i<ori.size();i++){
        bool flag = true;
        int left = 0;
        int right = (int)str.size() - 1;
        while(left<right){
            if(str[left] == str[right]){
                left++;
                right--;
            }
            else{
                flag = false;
                break;
            }
        }
        if(flag)
            ans = min(ans, (int)str.size());
        before = str[i]+before;
        str= ori + before;
    }
    cout << ans;
}