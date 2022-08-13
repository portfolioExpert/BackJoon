let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let n = +input[0];
let arr = input[1].split(' ').map(e => +e);
let s = new Set();
let visit = new Array(21).fill(false);
dfs = (index, sum) => {
    if (index == n) {
        return;
    }
    for (let i = index; i < n; i++) {
        if (visit[i] == false) {
            visit[i] = true;
            s.add(sum + arr[i]);
            dfs(i + 1, sum + arr[i]);
            visit[i] = false;
        }
    }
}
dfs(0, 0);
for (let i = 1; i < 2000001; i++) {
    if (!s.has(i)) {
        console.log(i)
        return;
    }
}