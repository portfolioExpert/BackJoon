//문제 18258번 큐 2 -> deque
#include <queue>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    deque<int>q;
    for(int i = 0;i<n;i++){
        string command = "";
        int num = 0;
        cin >> command;
        if(command == "push"){
            cin >> num;
            q.push_back(num);
        }
        else if(command == "pop"){
            if(q.empty()){
                cout << -1 << "\n";
            }
            else {
                cout << q.front() << "\n";
                q.pop_front();
            }
        }
        else if(command == "size"){
            cout << q.size() << "\n";
        }
        else if(command == "empty"){
            if(q.empty()) {
                cout << 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
        else if(command == "front"){
            if(q.empty()){
                cout << -1 << "\n";
            }
            else {
                cout << q.front() << "\n";
            }
        }
        else if(command == "back"){
            if(q.empty()){
                cout << -1 << "\n";
            }
            else {
                cout << q.back() << "\n";
            }
        }
    }
}