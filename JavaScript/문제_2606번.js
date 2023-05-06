let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let n = +input[0];
let m = +input[1];
let result = +0;
let graph = {};
let visit = new Array(n + 1).fill(0);
for (let i = 0; i <= n; i++) {
  graph[i] = [];
}
for (let i = 2; i < 2 + m; i++) {
  let [from, to] = input[i].split(' ').map(o => +o);
  graph[from].push(to);
  graph[to].push(from);
}
const dfs = (node) => {
  visit[node] = 1;
  result++;
  for (let i = 0; i < graph[node].length; i++) {
    if (visit[graph[node][i]] == 0) {
      dfs(graph[node][i]);
    }
  }
}
dfs(1);
console.log(result - 1);