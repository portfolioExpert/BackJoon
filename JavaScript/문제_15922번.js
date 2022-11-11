let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let n = +input[0];
let arr = [];
for (let i = 1; i < input.length; i++) {
  input[i] = input[i].split(" ");
  arr.push([+input[i][0], +input[i][1]]);
}
let start = arr[0][0];
let end = arr[0][1];
let result = +0;
for (let i = 1; i < arr.length; i++) {
  if (end >= arr[i][0]) {
    end = Math.max(arr[i][1], end);
  } else {
    result += end - start;
    start = arr[i][0];
    end = arr[i][1];
  }
}
console.log(result + end - start);