let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let [n, k] = input[0].split(' ').map(o => +o);
let arr = new Array(k).fill(0);
let flag = true;
for (let i = 0; i < k; i++){
  n -= i + 1;
  arr[i] = i + 1;
  if (n < 0) {
    flag = false;
    break;
  }
}
let index = k - 1;
while (n > 0) {
  if (index < 0)
    index = k - 1;
  arr[index--]++;
  n--;
}
if (!flag) {
  console.log(-1);
}
else
  console.log(arr[k - 1] - arr[0]);