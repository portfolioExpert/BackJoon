let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
input[0] = input[0].split(' ');
let n = +input[0][0];
let m = +input[0][1];
input.shift();
let arr = [...input[0].split(' ')];
arr = arr.map(o => +o);
let prefixSum = new Array(100001).fill(0);
for (let i = 1; i <= n; i++){
  prefixSum[i] = prefixSum[i - 1] + arr[i-1];
}
let result = "";
for (let i = 1; i <= m; i++){
  input[i] = input[i].split(' ');
  let from = +input[i][0];
  let to = +input[i][1];
  result+=(prefixSum[to] - prefixSum[from - 1]).toString()+"\n";
}
console.log(result);