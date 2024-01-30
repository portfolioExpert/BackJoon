let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
input[0] = input[0].split(' ');
let n = input[0][0];
let m = input[0][1];
let arr = [];
for (let i = 1; i <= n; i++) {
  arr.push(+input[i]);
}
arr.sort((o1, o2) => {
  return o1 - o2;
});
let left = +0, right = +0;
let result = +2147483647;
while (left <= right && right < n) {
  if (arr[right] - arr[left] >= m) {
    result = Math.min(result, arr[right] - arr[left]);
    left++;
  }
  else {
    right++;
  }
}
console.log(result);