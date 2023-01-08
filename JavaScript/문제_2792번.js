let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
input[0] = input[0].split(' ');
let n = +input[0][0];
let m = +input[0][1];
input.shift();
let arr = [...input.map(o=>+o)];
//이분 탐색인데 result는 몇개로 나누어 줄 것 인가
let result = +1111111111;
let right = -1;
let left = +1;
for (let i = 0; i < arr.length; i++){
  right = Math.max(right, arr[i]);
}
let bigger = +0;
const divide = (val) => {
  let sum = +0;
  let maxBig = +0;
  for (let i = 0; i < arr.length; i++){
    sum += parseInt(arr[i] / val);
    if (parseInt(arr[i] % val))
      sum++;
  }
  if (sum <= n) {
    return true;
  }
  else
    false;
}
while (left <= right) {
  let mid = parseInt((left + right) / 2);
  bigger = +0;
  if (divide(mid)) {
    result = Math.min(result, mid);
    right = mid - 1;
  }
  else 
    left = mid + 1;
}
console.log(result);