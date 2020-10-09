#include <iostream>
#include <algorithm>
using namespace std;

//문제 17487번
#include <string>
string str;//왼 0 오른 1
bool visit[26] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1 ,1 ,1, 1, 1 ,1 ,1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
int main(){
    int i, left = 0, right = 0, other = 0;
    getline(cin, str);
    for(i=0; i<str.size();i++){
        if((str[i] >= 'A' && str[i] <= 'Z') || str[i] == ' '){
            other++;
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
            else
                continue;
        }
        if(visit[str[i] - 'a'] == 0)
            left++;
        else
            right++;
    }
    for(i=0;i<other;i++){
        if(left > right)
            right++;
        else
            left++;
    }
    cout << left << " " << right;
    return 0;
}