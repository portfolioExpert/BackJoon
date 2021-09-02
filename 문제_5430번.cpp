//문제 5430번 AC -> 문자열
//두번째 틀렸습니다 에서 숫자0도 포함시키니 정답..
#include <string>
#include <queue>
#include <string.h>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        string command, number;
        cin >> command;
        deque<int>arr;
        int n;
        cin >> n;
        cin >> number;
        string makenumber = "";
        //배열 만들기
        for(int j = 0;j<(int)number.size();j++){
            if(number[j] >= '0' && number[j] <='9'){
                makenumber+=number[j];
            }
            else{
                if(makenumber != "")
                    arr.push_back(stoi(makenumber));
                makenumber = "";
            }
        }
        //명령 처리
        bool flag = 0; //0일때는 앞에 1일때는 뒤에
        bool wrong = 0;
        for(int j = 0;j<(int)command.size();j++){
            if(command[j] == 'R'){
                if(flag)
                    flag = 0;
                else
                    flag = 1;
            }
            else{
                if(arr.size() == 0){
                    cout << "error" << "\n";
                    wrong = 1;
                    break;
                }
                if(flag)
                    arr.pop_back();
                else
                    arr.pop_front();
            }
        }
        if(wrong)
            continue;
        cout << "[";
        while(arr.size() > 1){
            if(flag){
                cout << arr.back() << ",";
                arr.pop_back();
            }
            else{
                cout << arr.front() << ",";
                arr.pop_front();
            }
        }
        if(arr.size() == 0){
            cout << "]" << "\n";
        }
        else
            cout << arr.front() << "]" << "\n";
    }
    return 0;
}