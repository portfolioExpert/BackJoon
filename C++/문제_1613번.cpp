//문제 1613번 역사 -> 플로이드 와샬 응용
int n, k, s;
int result[401][401];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0;i<k;i++){
        int num1, num2;
        cin >> num1 >> num2;
        result[num1][num2] = -1;
        result[num2][num1] = 1;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int t = 1;t<=n;t++){
                if(result[j][t] == 0){
                    //둘다 뒤에 것이 먼저 일어났다면
                    if(result[j][i] == 1 && result[i][t] == 1){
                        result[j][t] = 1;
                    }
                    //둘다 앞에 것이 먼저 일어났다면
                    else if(result[j][i] == -1 && result[i][t] == -1){
                        result[j][t] = -1;
                    }
                }
            }
        }
    }
    cin >> s;
    for(int i = 0;i<s;i++){
        int num1, num2;
        cin >> num1 >> num2;
        cout << result[num1][num2] << "\n";
    }
}