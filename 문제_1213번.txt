#include <iostream>
#include <algorithm>
using namespace std;

//문제 1213번
#include <vector>
int main(){
    char ch[51], cnt = 0, save = 0, cntAl=0, k=0, total = 0, count[51], stay;
    int i, j;
    vector <char> v;
    cin >> ch;
    for(i=0;;i++){
        if(ch[i] == 0)break;
        v.push_back(ch[i]);
    }
    sort(v.begin(),v.end());
    //같은 알파벳이 나온 횟수 홀수이고 횟수가 2번이상일 경우 체크 ex)AAABBB 일경우
    stay = v[0];//기준으로 삼을 것
    for(j=0;j<v.size();j++){
        if(stay == v[j]){
            cntAl++;
        }
        else{
            count[k++] = cntAl;
            stay = v[j];
            j--;
            cntAl=0;
        }
    }
    count[k++] = cntAl;
    for(j=0;j<k;j++){
        if(count[j] % 2 ==1)total++;
    }
    if(total > 1){
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    //정렬한 것에서 임의로 저장후 삭제후 뒤로 붙인다
    for(j=0;j<v.size();){//알파벳이 한번씩만 나온횟수 체크
        if(v[j] != v[j+1]){
            save = v[j];
            cnt++;
            v.erase(v.begin()+j);
            if(cnt>1){//AABCDD처럼 하나나온 알파벳이 2개 이상일경우
                cout << "I'm Sorry Hansoo";
                return 0;
            }
        }
        if(v[j] == v[j+1])
            j+=2;
    }
    if(save != 0)
        v.push_back(save);
    if(cnt == 1){//가운데가 하나일 때
        for(j=i-2;j>=0;){
            v.push_back(v[j]);
            v.erase(v.begin()+j);
            j-=2;
        }
    }
    else if(cnt == 0){//가운데가 두개일 때
        for(j=i-3;j>=0;){
            v.push_back(v[j]);
            v.erase(v.begin()+j);
            j-=2;
        }
    }
    for(j=0;j<v.size();j++){
        cout << v[j];
    }
    return 0;
}