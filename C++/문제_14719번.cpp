//문제 14719번 빗물 -> 구현
int length[501];
int result;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int h, w;
    cin >> h >> w;
    for(int i = 0;i<w;i++){
        cin >> length[i];
    }
    for(int i = 1;i<w;i++){
        int left = length[i];
        int right = length[i];
        //기준으로 제일 작은 것을 찾고
        for(int j = 0;j<i;j++){
            left = max(left, length[j]);
        }
        //기준에서 제알 큰 것을 찾고
        for(int j = i + 1;j<w;j++){
            right = max(right, length[j]);
        }
        //그 중에 더 작은 것에서 빼준다
        result += (min(left, right) - length[i]);
    }
    cout << result;
}