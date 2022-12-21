let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

let n = +input[0];
let arr = [];
for (let i = 1; i <= n; i++){
  arr.push(input[i].split(' ').map(o => +o));
}
arr.sort((o1, o2) => {
  if (o1[0] === o2[0])
    return o1[1] - o2[1];
  return o1[0] - o2[0];
});
let maxval = -1000000001;
let start = -1000000001;
let result = +0;
for (let i = 0; i < arr.length; i++){
  if (maxval >= arr[i][0]) {
    maxval = Math.max(maxval, arr[i][1]);
  }
  else {
    result += maxval - start; 
    start = arr[i][0];
    maxval = arr[i][1];
  }
}
console.log(result + maxval - start);