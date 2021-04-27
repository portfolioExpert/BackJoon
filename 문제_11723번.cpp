#include <iostream>
#include <algorithm>
using namespace std;

//문제 11723번
#include <string.h>
#include <string>
bool visit[21];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    string str;
    cin >> n;
    while(n--){
        int num;
        cin >> str;
        if(str == "add"){
            cin >> num;
            visit[num] = 1;
        }
        else if(str == "remove"){
            cin >> num;
            visit[num] = 0;
        }
        else if(str == "check"){
            cin >> num;
            if(visit[num])
                cout << 1;
            else
                cout << 0;
            cout << "\n";
        }
        else if(str == "toggle"){
            cin >> num;
            if(visit[num])
                visit[num] = 0;
            else
                visit[num] = 1;
        }
        else if(str == "all"){
            fill_n(visit+1, 21, 1);
            //memset(visit+1, 1, size_t(visit));
        }
        else if(str == "empty")
            fill_n(visit+1, 21, 0);
            //memset(visit+1, 0, size_t(visit));
    }
    return 0;
}