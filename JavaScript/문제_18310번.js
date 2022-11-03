let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let n = +input[0];
let arr = input[1].split(" ").map((o) => +o);
arr.sort((o1, o2) => {
  return o1 - o2;
});
let sum = +0;
let result = arr[0];
//오른쪽 먼저 다 더하고 시작
for (let i = 0; i < arr.length; i++) {
  sum += arr[i] - arr[0];
}
for (let i = 1; i < arr.length; i++) {
  if (sum > sum + (arr[i] - arr[i - 1]) * i - (arr[i] - arr[i - 1]) * (arr.length - i)) {
    sum = sum + (arr[i] - arr[i - 1]) * i - (arr[i] - arr[i - 1]) * (arr.length - i);
    result = arr[i];
  }
}
console.log(result);