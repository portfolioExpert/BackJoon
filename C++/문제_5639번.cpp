//문제 5639번 이진 검색 트리 -> 분할정복
int arr[10001];
int idx;
void postOrder(int left, int right){
    if(left >= right){
        return;
    }
    int root = arr[left];
    int i = 0;
    //범위를 정하기 위해서 큰 값이 나오는 곳이 오른쪽
    for(i = left;i<right;i++){
        if(arr[left] < arr[i])
            break;
    }
    //왼쪽
    postOrder(left + 1, i);
    //오른쪽
    postOrder(i, right);
    cout << root << "\n";
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int num;
    while(cin >> num){
        arr[idx++] = num;
    }
    postOrder(0, idx);
}