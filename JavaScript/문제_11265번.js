let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
input[0] = input[0].split(' ');
let n = +input[0][0];
let m = +input[0][1];
let arr = [];
for (let i = 1; i <= n; i++){
  input[i] = input[i].split(' ').map(o=> +o);
  arr.push(input[i]);
}
for (let i = 0; i < n; i++){
  for (let j = 0; j < n; j++){
    for (let k = 0; k < n; k++){
      arr[j][k] = Math.min(arr[j][i] + arr[i][k], arr[j][k]);
    }
  }
}
for (let i = n + 1; i < n + 1 + m; i++){
  input[i] = input[i].split(' ');
  let from = input[i][0] - 1;
  let to = input[i][1] - 1;
  let cost = input[i][2];
  if (arr[from][to] <= cost)
    console.log('Enjoy other party');
  else
    console.log('Stay here');
}