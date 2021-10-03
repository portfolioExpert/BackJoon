#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//문제 11652번 벡터를 이용하여 메모리와 시간을 줄임
#include <vector>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int i, n, cnt = 1, bigcount = -1;
    long long num, value=0;
    vector<long long> v;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num;
        v.push_back(num);
    }
    value = v[0];//이것 때문에 채점중 100퍼에서 틀렸다고 뜸
    sort(v.begin(),v.end());//오름차순으로 정렬
    for(i=0;i<n-1;i++){
        if(v[i] == v[i+1]){//같으면 증가
            cnt++;
        }
        else//다르면 감소
            cnt = 1;
        if(bigcount < cnt){//어차피 오름차순으로 정렬되므로 같은횟수를 신경 안써도됨
            value = v[i];
            bigcount = cnt;
        }
    }
    cout << value;
    v.clear();
    return 0;
}