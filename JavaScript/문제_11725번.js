let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let n = +input[0];
input.shift();
let visit = new Array(n + 1).fill(0);
let check = new Array(n + 1).fill(0);
let node = {};
for (let i = 1; i <= n; i++){
  node[i] = [];
}
for (let i = 0; i < input.length; i++){
  let [from, to] = input[i].split(' ');
  node[from].push(to);
  node[to].push(from);
}
const dfs = (now, parent) => {
  visit[now] = 1;
  check[now] = +parent;
  for (let i = 0; i < node[now].length; i++){
    let next = node[now][i];
    if (visit[next] == 0) {
      dfs(next, now);
    }
  }
}
dfs(1, 0);
let result = "";
for (let i = 2; i <= n; i++){
  result += check[i];
  result += '\n';
}
console.log(result);