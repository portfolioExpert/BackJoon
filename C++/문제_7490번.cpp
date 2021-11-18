//문제 7490번 0 만들기 -> 백트래킹
#include <string>
#include <vector>
char arr[3] = {' ', '+', '-'};
void dfs(int index, int n, string str){
    if(index > n){
        vector <int>num;
        vector <char>cal;
        for(int i = 0;i<(int)str.size();i++){
            if(str[i] == ' '){
                int num1 = num.back();
                num.pop_back();
                int innum = num1 * 10;
                num.push_back(innum + (str[i + 1] -48));
                i++;
            }
            else{
                if(str[i] >= '1' && str[i] <= '9')
                    num.push_back(str[i] - 48);
                else
                    cal.push_back(str[i]);
            }
        }

        for(int i = 0;i<(int)cal.size();i++){
            char ch = cal[i];
            if(ch == '+'){
                num[i+1] = num[i] + num[i+1];
            }
            else if(ch == '-'){
                num[i+1] = num[i] - num[i+1];
            }
        }
        if(num[num.size() - 1] == 0)
            cout << str <<"\n";
        return;
    }
    for(int i = 0;i<3;i++){
        str+=arr[i];
        str+=index+48;
        dfs(index+1, n, str);
        str = str.substr(0, (int)str.size()-2);
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        int n;
        cin >> n;
        string str = "1";
        dfs(2, n, str);
        cout << "\n";
    }
}