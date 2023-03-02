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

let [n, m] = input[0].split(' ').map(o => +o);
let dx = [1, -1, 0, 0];
let dy = [0, 0, 1, -1];
input.shift();
let map = [];
let visit = new Array(n);
for (let i = 0; i < n; i++){
  visit[i] = new Array(m).fill(-1);
}
input.map((o) => map.push(o));
const bfs = () => {
  let q = new Queue();
  q.push({ first: 0, second: 0 });
  visit[0][0] = 1;
  while (q.size() > 0) {
    let now = q.pop();
    let gox = now.first;
    let goy = now.second;
    for (let i = 0; i < 4; i++){
      let gx = gox + dx[i];
      let gy = goy + dy[i];
      if (gx >= 0 && gx < n && gy >= 0 && gy < m && map[gx][gy] == 1 && visit[gx][gy] === -1) {
        q.push({ first: gx, second: gy });
        visit[gx][gy] = visit[gox][goy] + 1;
      }
    }
  }
}
bfs();
console.log(visit[n - 1][m - 1]);