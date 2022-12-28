let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
input[0] = input[0].split(' ');
let n = +input[0][0];
let m = +input[0][1];
input.shift();
let node = [...input];
let visit = Array.from(Array(n), () => Array(m).fill(0));
let flag = false;
//S N W E
let dx = [1, -1, 0, 0];
let dy = [0, 0, -1, 1];
let mapper = new Map();
mapper.set('S', 0);
mapper.set('N', 1);
mapper.set('W', 2);
mapper.set('E', 3);
let cnt = +1;
//now는 처음에 시작한 번호
const dfs = (x, y, now) => {
  //같은 조직이 아닌데 새로운 곳을 발견하면 흡수
  if (visit[x][y] !== 0 && visit[x][y] !== now) {
    flag = true;
    return;
  }
  //같은 조직을 재방문일 경우 끝
  if (visit[x][y] !== 0 && visit[x][y] === now) {
    return;
  }
  visit[x][y] = +now;
  let gox = x + dx[mapper.get(node[x][y])];
  let goy = y + dy[mapper.get(node[x][y])];
  dfs(gox, goy, now);
}
let result = +0;
for (let i = 0; i < n; i++){
  for (let j = 0; j < m; j++){
    if (visit[i][j] !== 0)
      continue;
    dfs(i, j, cnt);
    cnt++;
    if(!flag)
      result++;
    flag = false;
  }
}
console.log(result);