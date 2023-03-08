let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let [n, m] = input[0].split(' ').map(o => +o);
let prefixSum = new Array(n + 1);
let arr = [];
input.shift();
for (let i = 0; i < n; i++){
  prefixSum[i] = new Array(n + 1).fill(0);
  arr.push(input[i].split(' ').map(o => +o));
}
prefixSum[n] = new Array(n + 1).fill(0);
prefixSum[1][1] = arr[0][0];
for (let i = 1; i <= n; i++) {
  prefixSum[1][i] = prefixSum[1][i - 1] + arr[0][i - 1];
  prefixSum[i][1] = prefixSum[i - 1][1] + arr[i - 1][0];
}
for (let i = 2; i <= n; i++){
  for (let j = 2; j <= n; j++){
    prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i-1][j-1] + arr[i-1][j-1];
  }
}
let result = "";
for (let i = n; i < m + n; i++){
  let [x1, y1, x2, y2] = input[i].split(' ').map(o => +o);
  result += (prefixSum[x2][y2] - prefixSum[x2][y1 - 1] - prefixSum[x1 - 1][y2] + prefixSum[x1 - 1][y1 - 1]);
  result += '\n';
}
console.log(result);