//문제 1449번 수리공 항승 -> 정렬
int num[1001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, l;
    cin >> n >> l;
    for(int i = 0;i<n;i++){
        cin >> num[i];
    }
    sort(num, num + n);

    double len = num[0] - 0.5;
    int result = 1;
    for(int i = 1;i<n;i++){
        if(len + l >= num[i]){
            continue;
        }
        else{
            result++;
            len = num[i] - 0.5;
        }
    }
    cout << result;
}