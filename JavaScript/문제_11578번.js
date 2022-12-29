let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
input[0] = input[0].split(' ');
let n = +input[0][0];
let m = +input[0][1];
input.shift();
let info = [];
for (let i = 0; i < input.length; i++){
  input[i] = input[i].split(' ').map(o => +o);
  input[i].shift()
  info.push(input[i]);
}
let visit = new Array(m + 1).fill(0);
let result = +987654321;
const dfs = (index) => {
  if (index == m) {
    let check = new Array(n + 1).fill(0);
    let sum = +0;
    for (let i = 0; i < m; i++){
      if (visit[i] === 1) {
        info[i].map(o => check[o - 1] = 1);
        sum++;
      }
    }
    for (let i = 0; i < n; i++){
      if (check[i] === 0)
        return;
    }
    result = Math.min(sum, result);
    return;
  }
  visit[index] = 1;
  dfs(index + 1);
  visit[index] = 0;
  dfs(index + 1);
  visit[index] = 0;
}
dfs(0);
if(result === 987654321)
    console.log(-1);
else
    console.log(result);