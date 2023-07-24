let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let n = +input[0];
input.shift();
let arr = input.map(o => +o);
arr.sort((o1, o2) => {
  return o2 - o1;
});
let result = +0;
let sum = +0;
for (let i = 0; i < arr.length; i++) {
  result = Math.max(result, arr[i] * (i + 1));
}
console.log(result);