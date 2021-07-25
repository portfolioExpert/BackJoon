//문제 1701번 Cubeditor -> KMP 테이블 제작
//접두사와 접미사 비교를 0부터 하는것이 아닌 인덱스를 0, 1, 2 부터 잘라가면서 진행해야한다
#include <vector>
#include <string>
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
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    string str;
    cin >> str;
    int result = 0;
    for(int i = 0;i<str.size();i++){
        vector<int>table = maketable(str.substr(i, str.size() - i));
        for(int j = 0;j<table.size();j++)
            result = max(result, table[j]);
    }
    cout << result;
}