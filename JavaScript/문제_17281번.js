let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let n = +input[0];
input.shift();
for (let i = 0; i < input.length; i++) {
    input[i] = input[i].split(' ').map(item => +item);
}
let result = +0;
let visit = new Array(10).fill(false);
//횟수와 타순을 넣는 것
const dfs = (cnt, arr) => {
    if (cnt == 9) {
        let score = +0;
        let number = +0;
        //이닝
        for (let i = 0; i < n; i++) {
            //한 이닝당 아웃 카운트 3
            let out = +0;
            let base = new Array(3).fill(0);//3, 2, 1루
            let j = number;
            for (; ; j++) {
                if (j >= 9)
                    j = 0;
                if (out == 3)
                    break;
                let plus = +0;
                switch (input[i][arr[j]]) {
                    case 0:
                        out++;
                        break;
                    case 1:
                        plus += base[0];
                        base[0] = base[1];
                        base[1] = base[2];
                        base[2] = 1;
                        break;
                    case 2:
                        plus += base[0];
                        plus += base[1];
                        base[0] = base[2];
                        base[1] = 1;
                        base[2] = 0;
                        break;
                    case 3:
                        plus += base[0];
                        plus += base[1];
                        plus += base[2];
                        base[0] = 1;
                        base[1] = 0;
                        base[2] = 0;
                        break;
                    case 4:
                        for (let i = 0; i < 3; i++) {
                            plus += base[i];
                            base[i] = 0;
                        }
                        plus += +1;
                        break;
                }
                score += plus;
            }
            number = j;
        }
        result = Math.max(result, score);
        return;
    }
    //해당 타순이 배치가 되었다면 패스
    if (arr[cnt] != -1) {
        dfs(cnt + 1, arr);
        return;
    }

    //남은 타자
    for (let i = 1; i < 9; i++) {
        //i번째 타자가 배치가 안되었다면
        if (visit[i] == 0) {
            visit[i] = 1;
            arr[cnt] = i;
            dfs(cnt + 1, arr);
            arr[cnt] = -1;
            visit[i] = 0;
        }
    }
}
//4번 타자에 1번을 배치
visit[0] = 1;
dfs(0, [-1, -1, -1, 0, -1, -1, -1, -1, -1]);
console.log(result);