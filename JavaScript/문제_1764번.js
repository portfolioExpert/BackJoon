let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

input[0] = input[0].split(' ');
let n = +input[0][0];
let m = +input[0][1];
let mapper = new Map();
let result = +0;
for (let i = 0; i < n + m; i++){
  if (!mapper.has(input[i + 1]))
    mapper.set(input[i + 1], 1);
  else {
    mapper.set(input[i + 1], 2);
    result++;
  }
}
let arr = [...mapper];
console.log(result);
arr.sort().map(o => {
  if (o[1] === 2)
    console.log(o[0]);
});