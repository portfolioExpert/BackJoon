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
let left = +0, right = +20000000000000;//길이 단위
let result = +0;
while (left + 1 < right) {
  let mid = Math.floor((left + right) / 2);//길이
  let sum = +0;//랜선의 개수
  for (let i = 0; i < arr.length; i++){
    sum += Math.floor(arr[i] / mid);
  }
  if (sum < m)
    right = mid;
  else{
    left = mid;
    result = Math.max(result, left);
  }
}
console.log(result);