//문제 4358번 생태학 -> 맵, 문자열
#include <map>
#include <vector>
#include <string>
vector<pair<string, double>>v;
map<string,int>m;
int main(){
    int total = 0;
    string str;
    while(getline(cin, str)){
        m[str]++;
        total++;
    }
    for(auto it = m.begin(); it!=m.end(); it++){
        v.push_back({it->first, (double)it->second / total * 100});
    }
    sort(v.begin(), v.end());
    for(int i = 0;i<(int)v.size();i++){
        printf("%s %.4lf\n", v[i].first.c_str(), v[i].second);
    }
}