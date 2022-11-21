let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
const n = +input[0];
let arr = [];
for (let i = 1; i <= n; i++){
  arr.push(input[i]);
}
let result = +0;
for (let i = 0; i < n; i++){
  if (arr[i].length % 2 === 1)
    continue;
  let s = [];
  for (let j = 0; j < arr[i].length; j++){
    if (s.length === 0 || s[s.length - 1] !== arr[i][j])
      s.push(arr[i][j]);
    else
      s.pop();
  }
  if (s.length === 0)
    result++;
}
console.log(result);