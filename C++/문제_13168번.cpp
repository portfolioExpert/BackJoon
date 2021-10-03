#include <iostream>
#include <algorithm>
using namespace std;

//문제 13168번
#include <vector>
#include <map>
#include <queue>
#include <string>
map<string, int>city;
vector<int> visit;
typedef struct Node{
    string name;
    string from;
}Node;
double sum1, sum2, dp[101];
bool flag = 0;
vector<pair<pair<int,int>, double>> node[101];
double dijkstra(int from, int to);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, trainprice, m, i, t;
    cin >> n >> trainprice;
    for(i=0;i<n;i++){
        string str;
        cin >> str;
        city.insert(make_pair(str, i));
    }
    cin >> m;
    for(i=0;i<m;i++){
        string str;
        cin >> str;
        visit.push_back(city.find(str)->second);
    }
    cin >> t;
    for(i=0;i<t;i++){
        string str, from ,to;
        int pri;
        cin >> str >> from >> to >> pri;
        int check;
        if(str == "Mugunghwa" || str == "ITX-Saemaeul" || str == "ITX-Cheongchun")
            check = 0;
        else if(str == "S-Train" || str == "V-Train")
            check = 1;
        else
            check = 2;
        node[city.find(from)->second].push_back({{check,city.find(to)->second}, pri});
        node[city.find(to)->second].push_back({{check,city.find(from)->second}, pri});
    }
    //내일로 X
    for(int i = 0;i<m - 1;i++){
        sum1+=dijkstra(visit[i], visit[i+1]);
    }
    flag = 1;
    //내일로 O
    for(int i = 0;i<m - 1;i++){
        sum2+=dijkstra(visit[i], visit[i+1]);
    }
    if(sum2 + trainprice < sum1)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
double dijkstra(int from, int to){
    fill_n(dp, 101, 987654321);
    priority_queue<pair<double ,int>>pq;
    dp[from] = 0;
    pq.push({0, from});
    while(!pq.empty()){
        int pos = pq.top().second;
        double val = -pq.top().first;
        pq.pop();
        if(dp[pos] < val)continue;
        for(int i=0;i<node[pos].size();i++){
            int near = node[pos][i].first.second;
            double cost = val;
            if(flag == 1){
                if(node[pos][i].first.first == 0)
                    cost += 0;
                else if(node[pos][i].first.first == 1)
                    cost += (double)node[pos][i].second / 2;
                else
                    cost += node[pos][i].second;
            }
            else
                cost += node[pos][i].second;
            if(cost < dp[near]){
                dp[near] = cost;
                pq.push({-cost, near});
            }
        }
    }
    return dp[to];
}