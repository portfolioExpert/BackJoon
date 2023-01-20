let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let dp = new Array(1001).fill(0);
let n = +input[0];
const topdown = (now) => {
  if (now === 1)
    return 1;
  if (now === 2)
    return 3;
  if (dp[now] != 0)
    return dp[now];
  //now - 2에 *2는 네모를 채우기는 경우의 수는 2개이기 때문
  return dp[now] += (topdown(now - 1) + 2 * topdown(now - 2)) % 10007;
}
console.log(topdown(n));