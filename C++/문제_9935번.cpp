//문제 9935번 문자열 폭발 -> 문자열을 뒤로 점검해야한다
char result[1000001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    string str;
    cin >> str;
    string bomb;
    cin >> bomb;
    int index = 0;
    for(int i = 0;i<str.size();i++){
        result[index++] = str[i];
        //왜 마지막이냐면 뒤로가면서 제거하기 위해서
        if(result[index-1] == bomb[bomb.size() - 1]){
            bool flag = true;
            //
            if(index - bomb.size() < 0)
                continue;
            for(int j = 0;j<bomb.size();j++){
                if(result[index - j - 1] != bomb[bomb.size() - j - 1]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                index-=bomb.size();
            }
        }
    }
    if(index == 0)
        cout << "FRULA";
    else{
        for(int i = 0;i<index;i++){
            cout << result[i];
        }
    }
}