let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let num = [];
dfs = (cnt, now, str) => {
    if (now < 0)
        return;
    if (cnt == 10) {
        return;
    }
    for (let i = now; i >= 0; i--) {
        num.push(parseInt(str + i));
        dfs(cnt + 1, i - 1, str + i);
    }
}
dfs(0, 9, '');
num.sort((o1, o2) => {
    return o1 - o2;
})
if (num.length < +input)
    console.log(-1);
else
    console.log(num[+input - 1]);