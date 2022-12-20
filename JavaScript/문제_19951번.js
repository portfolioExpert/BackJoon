let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
input[0] = input[0].split(' ');
let n = +input[0][0];
let m = +input[0][1];
let arr = [0, ...input[1].split(' ').map(o => +o)]
let prefixSum = new Array(n + 1).fill(0);
for (let i = 2; i < 2 + m; i++){
  input[i] = input[i].split(' ');
  let from = +input[i][0];
  let to = +input[i][1];
  let cost = +input[i][2];
  prefixSum[from] += cost;
  prefixSum[to + 1] -= cost;
}
for (let i = 1; i <= n; i++){
  prefixSum[i] += prefixSum[i - 1];
  arr[i] += prefixSum[i];
}
arr.shift();
console.log(arr.join(' '));