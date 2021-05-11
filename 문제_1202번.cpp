#include <iostream>
#include <algorithm>
using namespace std;

//문제 1202번
#include <vector>
#include <queue>
typedef long long ll;
priority_queue <ll> pq;
vector <pair<ll,ll>> v;
priority_queue <ll> bag;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n, k,weight, price,i, bag[300001], result = 0;
    cin >> n >> k;
    for(i=0;i<n;i++){
        cin >> weight >> price;
        v.push_back({weight, price});
    }
    for(i=0;i<k;i++){
        cin >> bag[i];
    }
    sort(v.begin(),v.end());//무게 기준 오름차순 정리
    sort(bag, bag+k);//낮은 무게순 오름차순 정리
    ll index = 0;//한번 확인한 보석은 다시 확인 하지 않음
    //낮은 가방의 무게에 가장 큰 가격의 보석을 넣어준다
    for(i=0;i<k;i++){
        for(;index<n && bag[i]>= v[index].first;){//i번째 무게에 수용 가능한 보석은 전부 넣는다 어차피 무게가 가장 작은 것 부터니까 뒤에 가방은 무조건 수용 가능
            pq.push(v[index++].second);
        }
        if(!pq.empty()){//가방의 갯수만큼 큰것 부터 차례대로 더해줌
            result+=pq.top();
            pq.pop();
        }
    }
    cout << result;
    return 0;
}

//이것에서 약간 최적화
//#include <vector>
//#include <queue>
//typedef long long ll;
//priority_queue <ll> pq;
//vector <pair<ll,ll>> v;
//priority_queue <ll> bag;
//int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
//    ll n, k,weight, price,i, result = 0, num;
//    cin >> n >> k;
//    for(i=0;i<n;i++){
//        cin >> weight >> price;
//        v.push_back({weight, price});
//    }
//    for(i=0;i<k;i++){
//        cin >> num;
//        bag.push(num);
//    }
//    sort(v.begin(),v.end());//무게 기준 오름차순 정리
//    sort(bag, bag+k);//낮은 무게순 오름차순 정리
//    ll index = 0;//한번 확인한 보석은 다시 확인 하지 않음
//    //낮은 가방의 무게에 가장 큰 가격의 보석을 넣어준다
//    for(i=0;i<k;i++){
//        for(;index<n && bag.top()>= v[index].first;){//i번째 무게에 수용 가능한 보석은 전부 넣는다 어차피 무게가 가장 작은 것 부터니까 뒤에 가방은 무조건 수용 가능
//            pq.push(v[index++].second);
//        }
//        if(!pq.empty()){//가방의 갯수만큼 큰것 부터 차례대로 더해줌
//            result+=pq.top();
//            pq.pop();
//            bag.pop();
//        }
//    }
//    cout << result;
//    return 0;
//}