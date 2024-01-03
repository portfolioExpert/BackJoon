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
let n = +input[0];
let visit = new Array(n);
for (let i = 0; i < n; i++) {
  visit[i] = new Array(n).fill(0);
}
let map = [];
let dx = [1, -1, 0, 0];
let dy = [0, 0, 1, -1];
for (let i = 0; i < n; i++) {
  map[i] = [];
  for (let j = 0; j < n; j++) {
    map[i].push(input[i + 1][j]);
  }
}
const bfs = (x, y, ch) => {
  let q = new Queue();
  q.push({ x: x, y: y });
  visit[x][y] = 1;
  while (q.size() > 0) {
    let now = q.pop();
    let gox = now.x;
    let goy = now.y;
    for (let i = 0; i < 4; i++) {
      let gx = gox + dx[i];
      let gy = goy + dy[i];
      if (gx >= 0 && gx < n && gy >= 0 && gy < n && map[gx][gy] == ch && visit[gx][gy] == 0) {
        visit[gx][gy] = 1;
        q.push({ x: gx, y: gy });
      }
    }
  }
}
let result1 = 0, result2 = 0;
for (let i = 0; i < n; i++) {
  for (let j = 0; j < n; j++) {
    if (visit[i][j] == 0) {
      result1++;
      bfs(i, j, map[i][j]);
    }
  }
}
for (let i = 0; i < n; i++) {
  for (let j = 0; j < n; j++) {
    if (map[i][j] == 'R') {
      map[i][j] = 'G';
    }
  }
}
visit = new Array(n);
for (let i = 0; i < n; i++) {
  visit[i] = new Array(n).fill(0);
}
for (let i = 0; i < n; i++) {
  for (let j = 0; j < n; j++) {
    if (visit[i][j] == 0) {
      result2++;
      bfs(i, j, map[i][j]);
    }
  }
}
console.log(result1 + ' ' + result2);