let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
class Queue {
  constructor() {
    this.storage = {};
    this.front = 0;
    this.rear = 0;
  }

  size() {
    if (this.storage[this.rear] === undefined) {
      return 0;
    } else {
      return this.rear - this.rear + 1;
    }
  }

  push(value) {
    if (this.size() === 0) {
      this.storage['0'] = value;
    } else {
      this.rear += 1;
      this.storage[this.rear] = value;
    }
  }

  pop() {
    let temp;
    if (this.front === this.rear) {
      temp = this.storage[this.front];
      delete this.storage[this.front];
      this.front = 0;
      this.rear = 0;
    } else {
      temp = this.storage[this.front];
      delete this.storage[this.front];
      this.front += 1;
    }
    return temp;
  }

  front() {
    return this.storage[front];
  }
}
input[0] = input[0].split(' ');
let n = +input[0][0];
let m = +input[0][1];
let arr = [];
let visit = new Array(n);
for (let i = 1; i < n + 1; i++) {
  input[i] = input[i].split(' ').map(o => +o);
  arr.push(input[i]);
}
for (let i = 0; i < n; i++) {
  visit[i] = [];
  for (let j = 0; j < m; j++) {
    visit[i].push(0);
  }
}
let dx = [1, -1, 0, 0];
let dy = [0, 0, 1, -1];
let result1 = +0;
let result2 = +0;
const bfs = (x, y) => {
  let sum = +0;
  const q = new Queue();
  q.push({ x: x, y: y });
  while (q.size() > 0) {
    let now = q.pop();
    let gox = now.x;
    let goy = now.y;
    sum++;
    for (let i = 0; i < 4; i++) {
      let gx = gox + dx[i];
      let gy = goy + dy[i];
      if (gx >= 0 && gx < n && gy >= 0 && gy < m && arr[gx][gy] == 1 && visit[gx][gy] == 0) {
        visit[gx][gy] = 1;
        q.push({ x: gx, y: gy });
      }
    }
  }
  result2 = Math.max(result2, sum);
}
for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    if (arr[i][j] == 1 && visit[i][j] == 0) {
      visit[i][j] = 1;
      result1++;
      bfs(i, j);
    }
  }
}
console.log(result1 + "\n" + result2);