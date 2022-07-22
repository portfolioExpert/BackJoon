let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let n = parseInt(input[0])
let m = parseInt(input[1])
let dp = new Array(n + 1)
dp.fill(1)
let result = 1
let settle = []//고정석 리스트
for (let i = 2; i < input.length; i++) {
    settle.push(parseInt(input[i]))
}
//2부터
for (let i = 2; i <= n; i++) {
    //고정석 리스트에 있으면
    if (settle.includes(i)) {
        result *= dp[i - 1]
        continue
    }
    //이전 값이 고정석일 경우
    if (settle.includes(i - 1)) {
        continue
    }
    dp[i] = dp[i - 2] + dp[i - 1]
}
if (!settle.includes(n))
    result *= dp[n]
console.log(result)