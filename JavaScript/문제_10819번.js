let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let n = +input[0];
let arr = input[1].split(' ').map(o => +o);
let node = [];
let visit = new Array(n).fill(0);
let result = 0;
const dfs = (cnt) => {
  if (cnt == n) {
    let sum = 0;
    for (let i = 0; i < n - 1; i++) {
      sum += Math.abs(node[i] - node[i + 1]);
    }
    result = Math.max(result, sum);
    return;
  }
  for (let i = 0; i < n; i++) {
    if (visit[i] == 0) {
      visit[i] = 1;
      node.push(arr[i]);
      dfs(cnt + 1);
      node.pop();
      visit[i] = 0;
    }
  }
}
dfs(0);
console.log(result);