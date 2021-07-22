//문제 1786번 찾기 -> KMP입문
//KMP 접두사 접미사 일치로 테이블 찾고
#include <string>
#include <vector>
vector<int>v;
vector<int> maketable(string pat){
    int size = (int)pat.size();
    //일치하는 인덱스를 저장하는 벡터
    vector<int> table(size, 0);
    int j = 0;
    for(int i = 1;i<size;i++){
        //일치하지 않을 경우 한칸 뒤 테이블 값으로 이동 시켜 준다
        while(j > 0 && pat[i] != pat[j]){
            j = table[j-1];
        }
        //일치하는 경우 테이블값에 인덱스를 1 더해서 넣어준다
        if(pat[i] == pat[j]){
            table[i] = ++j;
        }
    }
    return table;
}
int kmp(string ori, string pat){
    int cnt = 0;
    vector<int> table = maketable(pat);
    int orisize = (int)ori.size();
    int patsize = (int)pat.size();
    int j = 0;
    for(int i = 0;i<orisize;i++){
        //일치하는지 보고 일치하지 않으면 j를 해당 테이블 전 값으로 준다
        while(j>0 && ori[i] != pat[j]){
            j = table[j-1];
        }
        //모두 일치했을때
        if(ori[i] == pat[j]){
            if(j == patsize - 1){
                v.push_back(i - patsize + 2);
                j = table[j];//찾은 뒤에도 그만큼 점프시키기 위해서
                cnt++;
            }
            //전체 문자가 일치하지 않았을때
            else{
                j++;
            }
        }
    }
    return cnt;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    cout << kmp(str1, str2) << "\n";
    for(int y : v){
        cout << y << " ";
    }
}