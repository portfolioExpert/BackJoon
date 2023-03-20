let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let [n, m] = input[0].split(' ').map(o => +o);
input.shift();
let graph = {};
let visit = new Array(n + 1).fill(0);
for (let i = 0; i <= n; i++){
  graph[i] = [];
}
for (let i = 0; i < m; i++){
  let [from, to] = input[i].split(' ');
  graph[from].push(to);
  graph[to].push(from);
}
let result = +0;
const dfs = (start) => {
  if (visit[start] === 1)
    return;
  visit[start] = 1;
  for (let i = 0; i < graph[start].length; i++){
    dfs(graph[start][i]);
  }
}
for (let i = 1; i <= n; i++){
  if (visit[i] === 0) {
    dfs(i);
    result++;
  }
}
console.log(result);