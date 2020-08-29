#include <iostream>
#include <algorithm>
using namespace std;

//문제 1991번
char tree[26][3];
int key[26];
void preorder(int x);
void inorder(int y);
void postorder(int z);
int main(){
    int n, i, j;
    cin >> n;
    for(i = 0;i<n;i++){
        for(j=0;j<3;j++){
            cin >> tree[i][j];
        }
        key[tree[i][0] - 'A'] = i;//A부터 노드 정보가 입력된 순서를 저장, 함수 쓰기위해 순서 저장
    }
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
    return 0;
}
void preorder(int x){
    cout << tree[x][0];
    if(tree[x][1] != '.')//왼쪽 자식부터 탐색
        preorder(key[tree[x][1] - 'A']);
    if(tree[x][2] != '.')//오른쪽 자식부터 탐색
        preorder(key[tree[x][2] -'A']);
}
void inorder(int y){
    if(tree[y][1] != '.')//왼쪽 부터 최대한 깊은 곳 까지 가서
        inorder(key[tree[y][1] - 'A']);
    cout << tree[y][0];//최대한 깊은 자식 노드부터 출력
    if(tree[y][2] != '.')//이후 오른쪽 부터 최댛나 깊은 곳 까지 가고 다시 왼쪽 자식 부터 조사하고 출력
        inorder(key[tree[y][2] -'A']);
}
void postorder(int z){
    if(tree[z][1] != '.')//왼쪽 자식부터 밑에까지 가고
        postorder(key[tree[z][1] - 'A']);
    if(tree[z][2] != '.')//오른쪽 자식의 리프 노드까지가고
        postorder(key[tree[z][2] -'A']);
    cout << tree[z][0];//더이상 갈 노드가 없으면 리프 노드부터 위로 올라가며 출력
}