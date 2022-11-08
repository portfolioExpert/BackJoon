//문제 2608번 로마 숫자 -> 맵, 구현
#include <string>
#include <map>
#include <vector>
map<string, int>m;
int maker(string str){
    int res = 0;
    for(int i = 0;i<str.size();i++){
        //앞이 더 클 경우
        string left = "";
        left += str[i];

        //끝값이면
        if(i == (int)str.size() - 1){
            res+=m[left];
            break;
        }
        string right = "";
        right += str[i+1];
        string with = left + right;
        if(m[left] >= m[right]){
            res+=m[left];
        }
        //그게 아니면 합친값
        else{
            res+=m[with];
            i++;
        }
    }
    return res;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    string str1, str2;
    cin >> str1 >> str2;
    m["I"] = 1;
    m["V"] = 5;
    m["X"] = 10;
    m["L"] = 50;
    m["C"] = 100;
    m["D"] = 500;
    m["M"] = 1000;

    m["IV"] = 4;
    m["IX"] = 9;
    m["XL"] = 40;
    m["XC"] = 90;
    m["CD"] = 400;
    m["CM"] = 900;
    int total = maker(str1) + maker(str2);
    cout << total << "\n";
    string totalstr = to_string(total);
    string result = "";

    vector<pair<int,string>>v;//숫자
    for(auto iter = m.begin();iter!=m.end();iter++){
        v.push_back({iter->second, iter->first});
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int index = 0;
    while(total && index < v.size()){
        if(total >= v[index].first){
            total-=v[index].first;
            result+=v[index].second;
        }
        else{
            index++;
        }
    }
    cout << result;
}