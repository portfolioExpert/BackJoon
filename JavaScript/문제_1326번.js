let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let n = +input[0];
input[1] = input[1].split(' ');
input[2] = input[2].split(' ');
let arr = input[1].map(o => +o);
let visit = new Array(10001).fill(-1);
let a = +input[2][0];
let b = +input[2][1];

let bfs = (go) => {
    visit[go] = 0;
    let q = [];
    q.push(+go);
    while (q.length > 0) {
        let now = +q.shift();
        for (let next = now + arr[now]; next < n; next += arr[now]) {
            if (visit[next] == -1) {
                visit[next] = visit[now] + 1;
                q.push(+next);
            }
        }
        for (let next = now - arr[now]; next >= 0; next -= arr[now]) {
            if (visit[next] == -1) {
                visit[next] = visit[now] + 1;
                q.push(+next);
            }
        }
    }
}
bfs(a - 1);
console.log(visit[b - 1]);