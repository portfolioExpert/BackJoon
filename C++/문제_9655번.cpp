//문제 9655번 돌 게임 -> 구현, 게임이론
int main(){
    int n;
    cin >> n;
    bool turn = 1;//1이 상근차례, 0이 창영차례
    while(n){
        if(n > 3){
            n-=3;
        }
        else
            n--;
        if(n <= 0){
            if(turn)
                cout << "SK";
            else
                cout << "CY";
            return 0;
        }
        turn = !turn;
    }
}