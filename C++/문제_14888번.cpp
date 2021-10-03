//문제 14888번
int num[12];
int result[12];
int cal[4];
int minval = 1111111111, maxval = -1111111111, n;
void dfs(int index);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> num[i];
        result[i] = num[i];
    }
    cin >> cal[0] >> cal[1] >> cal[2] >> cal[3];
    dfs(0);
    cout << maxval << "\n" << minval;
}
void dfs(int index){
    if(index == n - 1){
        minval = min(minval, result[index]);
        maxval = max(maxval, result[index]);
        return;
    }
    for(int i = 0;i<4;i++){
        for(int j = 0;j<cal[i];j++){
            if(i == 0){
                result[index + 1] = result[index] + result[index + 1];
            }
            else if(i == 1){
                result[index + 1] = result[index] - result[index + 1];
            }
            else if(i == 2){
                result[index + 1] = result[index] * result[index + 1];
            }
            else if(i == 3){
                result[index + 1] = result[index] / result[index + 1];
            }
            cal[i]--;
            dfs(index+1);
            cal[i]++;
            result[index + 1] = num[index + 1];
        }
    }
}