let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
const n = +input[0];
let dp = new Array(n).fill(1); //인덱스까지 최대 긴 감소하는 수열
let arr = input[1].split(" ").map((o) => +o);
let result = 0;
for (let i = 0; i < n; i++) {
  let big = +0;
  for (let j = 0; j < i; j++) {
    //현 위치보다 큰 것을 찾아야 그 다음에 내가 감소로 들어간다.
    if (arr[i] < arr[j]) {
      big = Math.max(big, dp[j]);
    }
  }
  dp[i] = big + 1;
  result = Math.max(result, dp[i]);
}
console.log(n - result);