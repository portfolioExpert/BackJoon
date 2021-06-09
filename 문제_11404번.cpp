//문제 11404번
int city[101][101];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        fill_n(city[i], n + 1, 9999999);
    }
    for(int i = 0;i<m;i++){
        int num1, num2, val;
        cin >> num1 >> num2 >> val;
        city[num1][num2] = min(city[num1][num2], val);
    }
    for(int i = 1;i<=n;i++){
        city[i][i] = 0;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=n;k++){

                city[j][k] = min(city[j][k], city[j][i] + city[i][k]);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(city[i][j] >= 9999999){
                cout << 0 << " ";
            }
            else
                cout << city[i][j] << " ";
        }
        cout <<"\n";
    }
}