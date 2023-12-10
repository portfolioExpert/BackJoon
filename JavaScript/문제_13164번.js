let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
input[0] = input[0].split(' ');
input[1] = input[1].split(' ');
let n = +input[0][0];
let k = +input[0][1];
let arr = [];
for (let i = 1; i < input[1].length; i++) {
  arr.push(+input[1][i] - +input[1][i - 1]);
}
arr.sort((o1, o2) => {
  return o1 - o2;
})
let result = +0;
for (let i = 0; i < n - k; i++) {
  result += arr[i];
}
console.log(result);