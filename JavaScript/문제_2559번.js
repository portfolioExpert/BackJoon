let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let [n, k] = input[0].split(' ');
input.shift();
let arr = input[0].split(' ').map(o=>+o);
let left = +0, right = +k;
let result = +0;
let sum = +0;
for (let i = 0; i < right; i++){
  result += arr[i];
  sum += arr[i];
}
while (left < right && right < n) {
  sum -= arr[left++];
  sum += arr[right++];
  result = Math.max(result, sum);
}
console.log(result);