let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");ㅁ
let arr = [...input.map(o => +o)];
let s = new Set();
let visit = new Array(10).fill(false);
const dfs = (len, num) => {
  if (len == 8) {
    s.add(parseInt(num));
    return;
  }
  s.add(parseInt(num));
  for (let i = 0; i <= 9; i++){
    if (visit[i] == 0) {
      visit[i] = 1;
      dfs(len + 1, num + i.toString());
      visit[i] = 0;
    }
  }
}
for (let i = 1; i <= 9; i++){
  visit[i] = 1;
  dfs(1, i.toString());
  visit[i] = 0;
}
let number = [...s];
number.sort((o1, o2) => {
  return o1 - o2;
});
for (let i = 0; i < arr.length - 1; i++){
  console.log(number[arr[i] - 1]);
}