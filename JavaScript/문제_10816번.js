let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let n = +input[0];
let arr = [...input[1].split(' ')];
let m = +input[2];
let my = [...input[3].split(' ')];
let map = new Map();
for (let i = 0; i < arr.length; i++){
  if (!map.has(+arr[i]))
    map.set(+arr[i], +1);
  else
    map.set(+arr[i], map.get(+arr[i]) + 1);
}
let result = "";
my.map(o => {
  if (map.has(+o))
    result += map.get(+o) + ' ';
  else
    result += '0 ';
});
console.log(result);