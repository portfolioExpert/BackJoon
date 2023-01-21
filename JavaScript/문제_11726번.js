let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let dp = new Array(1001).fill(0);
let n = +input[0];
const topdown = (now) => {
  if (now <= 2)
    return now;
  if (dp[now] != 0)
    return dp[now];
  return dp[now] += (topdown(now - 1) + topdown(now - 2)) % 10007;
}
console.log(topdown(n));