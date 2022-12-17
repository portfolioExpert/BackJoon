let input = require("fs")
  .readFileSync("example.txt")
  .toString()
  .trim()
  .split("\n");

//위치당 2번째 전에서는 1, 2 다 가능
//1번째 전에서는 1만 가능
//[1]로는 두 번째 전꺼만
//[2]로는 바로 전꺼만
let n = +input[0];
let dp = new Array(n + 1);
for (let i = 0; i <= n; i++){
  dp[i] = new Array(3).fill(0);
}
dp[1][1] = +input[1];
for (let i = 2; i <= n; i++){
  dp[i][1] = Math.max(dp[i - 2][1], dp[i - 2][2]) + +input[i];
  dp[i][2] = dp[i - 1][1] + +input[i];
}
console.log(Math.max(dp[n][1],dp[n][2]));