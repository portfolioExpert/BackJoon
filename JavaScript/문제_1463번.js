let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let n = +input[0];
let dp = new Array(1000001).fill(987654321);
dp[1] = 0;
for (let i = 2; i <= 1000000; i++) {
    if (i % 3 == 0)
        dp[i] = Math.min(dp[i], dp[i / 3] + 1);
    if (i % 2 == 0)
        dp[i] = Math.min(dp[i], dp[i / 2] + 1);
    dp[i] = Math.min(dp[i], dp[i - 1] + 1);
}
console.log(dp[n]);