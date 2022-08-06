let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let dp = new Array(50001);
dp.fill(987654321);
let n = +input[0];
for (let i = 1; i * i <= 50000; i++) {
    dp[i * i] = 1;
}
for (let i = 2; i <= n; i++) {
    for (let j = 1; j * j <= i; j++) {
        dp[i] = Math.min(dp[i], dp[j * j] + dp[i - j * j]);
    }
}
console.log(dp[n]);