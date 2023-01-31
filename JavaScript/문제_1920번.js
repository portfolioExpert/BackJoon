let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let n = +input[0];
let arr = input[1].split(' ');
let m = +input[2];
let search = input[3].split(' ');
arr = arr.map(o => +o);
arr.sort((o1, o2) => {
  return o1 - o2;
});
let result = "";
search.map((o) => {
  let left = +0;
  let right = n - 1;
  let flag = true;
  while (left <= right) {ㅁ
    let mid = parseInt((left + right) / 2);
    if (arr[mid] > +o)
      right = mid - 1;
    else if (arr[mid] < +o)
      left = mid + 1;
    else {
      flag = false;
      break;
    }
  }
  if (!flag)
    result += '1\n';
  else
    result += '0\n';
  
});
console.log(result);