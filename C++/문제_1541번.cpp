//문제 1541번 잃어버린 괄호 -> 문자열
#include <string>
#include <queue>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    string str;
    cin >> str;
    string number="";
    int sum = 0;
    bool flag = false;
    queue<int>q;
    for(int i = 0;i<str.size();i++){
        if(str[i] >='0' && str[i] <='9'){
            number+=str[i];
            if(i == str.size() - 1){
                if(flag)
                    q.push(stoi(number));
                else
                    sum+=stoi(number);
            }
        }
        else{
            int num = stoi(number);
            if(flag)
                q.push(num);
            else
                sum+=num;
            //음수
            if(str[i] == '-'){
                //첫 - 일경우
                if(flag == false){
                    flag = true;
                }
                //이미 -일 경우 먼저 계산 후 다시 -처리
                else{
                    while(!q.empty()){
                        sum-=q.front();
                        q.pop();
                    }
                }
            }
            number = "";
        }
    }
    while(!q.empty()){
        sum-=q.front();
        q.pop();
    }
    cout << sum;
}