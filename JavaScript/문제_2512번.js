let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let n = +input[0];
input.shift();
let arr = input[0].split(' ').map(o => +o);
arr.sort((o1, o2) => {
  return o1 - o2;
});
let m = +input[1];
let result = +0, sum = +0;
let left = 0, right = arr[n-1];
while (left <= right) {
  let mid = parseInt((left + right) / 2);
  let innerSum = +0;
  arr.map((o) => {
    if (o >= mid)
      innerSum += mid;
    else
      innerSum += o;
  });
  if (sum < innerSum && m >= innerSum) {
    sum = innerSum;
    result = mid;
    left = mid + 1;
  }
  else
    right = mid - 1;
}
console.log(result);