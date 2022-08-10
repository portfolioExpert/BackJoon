let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
for (let i = 0; i < input.length; i++) {
    input[i] = input[i].split(' ');
}
let n = +input[0][0];
let m = +input[0][1];
let r = +input[0][2];
let node = new Array(n);
const visit = new Array(n).fill(0);

for (let i = 0; i < n; i++) {
    node[i] = [];
}

for (let i = 1; i <= m; i++) {
    let from = +input[i][0];
    let to = +input[i][1];
    node[from - 1].push(to - 1);
    node[to - 1].push(from - 1);
}

for (let i = 0; i < n; i++) {
    node[i].sort((o1, o2) => {
        return o1 - o2;
    });
}
let cnt = +1;
let dfs = (start) => {
    visit[start] = cnt++;
    for (let y of node[start]) {
        if (visit[y] == 0) {
            dfs(y);
        }
    }
}
dfs(r - 1);
console.log(visit.join('\n'));