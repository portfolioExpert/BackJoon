let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let [n, x] = input[0].split(' ').map(o => +o);
input.shift();
let arr = input[0].split(' ').map(o=>+o);
let sum = +0, maxval = +0;
let left = 0, right = x - 1;
for (let i = 0; i < x; i++){
  sum += arr[i];
  maxval += arr[i];
}
let result = sum === 0 ? 0 : 1;
while (right < n - 1) {
  sum -= arr[left++];
  sum += arr[right + 1];
  right++;
  if (maxval < sum) {
    result = 1;
    maxval = sum;
  }
  else if (maxval === sum)
    result++;
}
if (maxval === 0)
  console.log('SAD');
else {
  console.log(maxval);
  console.log(result);
}