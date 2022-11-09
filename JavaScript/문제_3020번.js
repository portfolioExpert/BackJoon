let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let nh = input[0].split(" ");
let n = +nh[0];
let h = +nh[1];
let arr = new Array(h + 2).fill(0);
let result = new Array(h + 2).fill(0);
for (let i = 1; i <= n; i++) {
  let now = +input[i];
  if (i % 2 != +0) {
    arr[1] += 1;
    arr[now + 1] += -1;
  } else {
    arr[h + 1] += -1;
    arr[h - now + 1] += 1;
  }
}
let res = +987654321;
let cnt = +0;
for (let i = 1; i <= h; i++) {
  result[i] = result[i - 1] + arr[i];
  if (res > result[i]) {
    cnt = 1;
    res = result[i];
  } else if (res === result[i]) {
    cnt++;
  }
}
console.log(res, cnt);