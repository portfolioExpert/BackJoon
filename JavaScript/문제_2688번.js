let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let dp = new Array(65);
for (let i = 0; i < 65; i++) {
  dp[i] = new Array(10).fill(0);
}
dp[1].fill(+1);
for(let i = 2;i<=64;i++){
  for(let j = 0;j<=9;j++){
    for(let k = 0;k<=j;k++){
      dp[i][j] += dp[i-1][k];
    }
  }
}
const t = +input[0];
for (let i = 1; i <= t; i++){
  let index = +input[i];
  let result = 0;
  dp[index].map(o => result += o);
  console.log(result);
}