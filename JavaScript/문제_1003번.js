let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let t = +input[0];
let dp = new Array(41).fill(987654321);
let result0 = 0;
let result1 = 0;
const topdown = (n) => {
    if (n <= 1) 
        return n;
    if (dp[n] != 987654321)
        return dp[n];
    return dp[n] = topdown(n - 1) + topdown(n - 2);
}
for (let i = 0; i < t; i++) {
    if (+input[i + 1] == 0)
        console.log(1 + " " + 0);
    else
        console.log(topdown(+input[i + 1] - 1) + " " + topdown(+input[i + 1]));
}