#include <iostream>
#include <algorithm>
//문제 7662 이중 우선순위 큐 -> 우선순위 큐, 맵
#include <map>
#include <queue>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        int command;
        cin >> command;
        priority_queue<int>maxHeap;//최대출력
        priority_queue<int, vector<int>, greater<int>>minHeap;//최소출력
        map<int, int>m;//큐안에 숫자의 개수를 저장하는 곳
        for(int j = 0;j<command;j++){
            char ch;
            int num;
            cin >> ch >> num;
            if(ch == 'I'){
                maxHeap.push(num);
                minHeap.push(num);
                m[num]++;
            }
            //D일 경우
            else{
                //최대 삭제
                if(num == 1){
                    while(!maxHeap.empty()){
                        //값을 찾으면
                        if(m[maxHeap.top()] > 0){
                            m[maxHeap.top()]--;
                            maxHeap.pop();
                            break;
                        }
                        maxHeap.pop();
                    }
                }
                //최소 삭제
                else{//개수가 있다면 삭제
                    while(!minHeap.empty()){
                        //값을 찾았다면
                        if(m[minHeap.top()] > 0){
                            m[minHeap.top()]--;
                            minHeap.pop();
                            break;
                        }
                        minHeap.pop();
                    }
                }
            }
        }
        while(!maxHeap.empty()){
            if(m[maxHeap.top()] > 0){
                break;
            }
            maxHeap.pop();
        }
        while(!minHeap.empty()){
            if(m[minHeap.top()] > 0){
                break;
            }
            minHeap.pop();
        }
        if(maxHeap.empty() || minHeap.empty())
            cout << "EMPTY"<<"\n";
        else{
            while(!maxHeap.empty()){
                if(m[maxHeap.top()] > 0){
                    cout << maxHeap.top() << " ";
                    break;
                }
                maxHeap.pop();
            }
            while(!minHeap.empty()){
                if(m[minHeap.top()] > 0){
                    cout << minHeap.top() << "\n";
                    break;
                }
                minHeap.pop();
            }
        }
    }
}