//문제 17609번 -> 문자열, 두 포인터
//4번 틀린 이유
//1. 접근 방법의 부적절함, 2,3,4. 경우의 수 마다 처리를 해주지 않았다.
#include <iostream>
#include <algorithm>

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        string str;
        cin >> str;
        int left = 0;
        int right = (int)str.size() - 1;
        int flag = 0;
        while(left < right){
                //같을 때
            if(str[left] == str[right]){
                left++;
                right--;
            }
            //다를 때
            else{
                //왼쪽 하나증가 경우
                int inLeft = left+1;
                int inRight = right;
                while(inLeft < inRight){
                    if(str[inLeft] != str[inRight]){
                        flag = 2;
                        break;
                    }
                    inLeft++;
                    inRight--;
                }
                if(inLeft >= inRight){
                    flag = 1;
                    break;
                }
                //오른쪽 하나 감소 경우
                inLeft = left;
                inRight = right-1;
                while(inLeft < inRight){
                    if(str[inLeft] != str[inRight]){
                        flag = 2;
                        break;
                    }
                    inLeft++;
                    inRight--;
                }
                if(inLeft >= inRight){
                    flag = 1;
                }
                break;
            }
        }
        cout << flag << "\n";
    }
}