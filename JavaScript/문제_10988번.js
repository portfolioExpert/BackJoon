let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let str = input[0];
let left = 0;
let right = str.length - 1;
while (left <= right) {
  if (str[left] == str[right]) {
    left++;
    right--;
  }
  else {
    console.log(0);
    return;
  }
}
console.log(1);