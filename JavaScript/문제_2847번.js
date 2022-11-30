let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let n = +input[0];
let arr = [];
for (let i = 1; i <= n; i++){
  arr.push(+input[i]);
}
let result = +0;
for (let i = n - 1; i > 0 ; i--){
  while (arr[i] <= arr[i - 1]) {
    arr[i-1]--;
    result++;
  }
}
console.log(result);