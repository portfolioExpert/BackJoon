//문제 1068번
#include <vector>
typedef struct Node{
    int val;
    int parent;
    vector<int>child;
}Node;
Node node[51];
bool state[51];
void check(int now, int from);
int era, result;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, root = 0;
    cin >> n;
    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        if(num == -1){
            root = i;
            node[i].parent = -1;
            continue;
        }
        node[num].child.push_back(i);
        node[i].parent = num;
    }
    cin >> era;
    state[era] = 1;
    for(int i = 0;i<n;i++){
        check(i, i);
    }
    for(int i = 0;i<n;i++){
        bool flag = 0;
        if(node[i].child.size() == 0 && state[i] == 0)
            result++;
        else{
            for(int j =0;j<node[i].child.size();j++){
                if(state[node[i].child[j]] == 0){
                    flag = 1;
                    break;
                }
            }
            if(state[i] == 0 && flag == 0)
                result++;
        }
    }
    cout << result;
}
void check(int now, int from){
    if(now == -1){
        return;
    }
    if(now == era){
        state[from] = 1;
        return;
    }
    check(node[now].parent, from);
}