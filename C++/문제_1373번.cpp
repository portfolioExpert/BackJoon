//문제 1373번 2진수 8진수 -> 문자열
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    string str, result = "";
    int i = 0;
    cin >> str;
    if(str == "0"){
        cout << 0;
        return 0;
    }
    switch(str.size() % 3){
        case 1:
            i = 1;
            result+= '1';
            break;
        case 2 :
            i = 2;
            result+=(((str[0] - 48) * 2) + ((str[1] - 48) * 1)) + 48;
            break;
    }
    for(;i<str.size();i+=3){
        int sum = 0;
        sum+= (str[i] - 48) * 4;
        sum+= (str[i+1] - 48) * 2;
        sum+= (str[i+2] - 48) * 1;
        result+= sum + 48;
    }
    cout << result;
}