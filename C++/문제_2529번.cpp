//문제 2529 -> 부등호
//getchar와 cin, cout을 빠르게 하는 것을 같이 사용하면 안된다.
#include <string>
#include <cstring>
void dfs(int k, int index, string str, string check, string &maxval, string &minval, bool *visit){
    if(k + 1 == index){
        for(int i = 0;i<k;i++){
            int now = str[i] - 48;
            int next = str[i + 1] - 48;
            if(check[i] == '<'){
                if(now > next)
                    return;
            }
            else{
                if(now < next)
                    return;
            }
        }
        if(stol(maxval) < stol(str))
                maxval = str;
        if(stol(minval) > stol(str))
                minval = str;
        return;
    }
    for(int i = 0;i<10;i++){
        if(visit[i] == 0){
            str+= i+48;
            visit[i] = 1;
            dfs(k, index + 1, str, check, maxval, minval, visit);
            str.pop_back();
            visit[i] = 0;
        }
    }
}
int main(){
    int k;
    bool visit[10];
    memset(visit, 0, sizeof(visit));
    string str;
    string maxval = "0";
    string minval = "9999999999";
    cin >> k;
    getchar();
    getline(cin, str);
    string input;
    for(int i = 0;i<str.size();i++){
        if(str[i] != ' ')
            input+=str[i];
    }
    dfs(k, 0, "", input, maxval, minval, visit);
    cout << maxval << "\n" << minval;
}