//문제 2920번 음계 -> 구현
int main(){
    int num[9];
    bool as = true, ds = true;
    for(int i = 0;i<8;i++){
        cin >> num[i];
    }
    for(int i = 1;i<=8;i++){
        if(num[i-1] != i){
            as = false;
            break;
        }
    }
    for(int i = 8;i>=1;i--){
        if(num[8 - i] != i){
            ds = false;
            break;
        }
    }
    if(as)
        cout << "ascending";
    else if(ds)
        cout << "descending";
    else
        cout << "mixed";
}