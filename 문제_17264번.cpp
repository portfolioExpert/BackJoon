#include <iostream>
#include <algorithm>
using namespace std;

//문제 17264번
string winplayer[1001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int game, know, up, down, goal, i, sum = 0, j=0, check = 0, k = 0;
    string player, with;
    char w;
    cin >> game >> know;
    cin >> up >> down >> goal;
    for(i=0;i<know;i++){
        cin >> player >> w;
        if(w == 'W')
            winplayer[j++]=player;
    }
    for(i=0;i<game;i++){
        cin >> with;
        for(k = 0; k<j;k++){
            if(with == winplayer[k]){
                sum+=up;
                break;
            }
        }
        if(k == j)
            sum-=down;
        if(sum < 0)
            sum = 0;
        if(sum>=goal)
            check = 1;
    }
    if(check == 1)
        cout << "I AM NOT IRONMAN!!";
    else
        cout << "I AM IRONMAN!!";
    return 0;
}