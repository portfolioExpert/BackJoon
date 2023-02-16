let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let n = +input[0];
let arr = [];
input.shift();
input.map((o) => {
  let node = o.split(' ');
  node[0] = +node[0];
  arr.push(node);
});
arr.sort((o1, o2) => {
  return o1[0] - o2[0];
});
let result = '';
arr.map((o) => {
  result += o[0] + ' ' + o[1] + '\n';
});
console.log(result);