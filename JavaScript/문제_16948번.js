let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

let n = +input[0];
let visit = Array.from(Array(n + 1), () => Array(n + 1).fill(-1));
input[1] = input[1].split(' ');
let r1 = input[1][0];
let c1 = input[1][1];
let r2 = input[1][2];
let c2 = input[1][3];
let dx = [-2, -2, 0, 0, +2, +2];
let dy = [-1, +1, -2, +2, -1, +1];

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
const bfs = (r1, c1) => {
  let q = new Queue();
  visit[r1][c1] = 0;
  q.push({ first: r1, second: c1 });
  while (q.size() > 0) {
    let now = q.pop();
    let gox = +now.first;
    let goy = +now.second;
    for (let i = 0; i < 6; i++){
      let gx = gox + dx[i];
      let gy = goy + dy[i];
      if (gx >= 0 && gx < n && gy >= 0 && gy < n && visit[gx][gy] === -1) {
        q.push({ first: gx, second: gy });
        visit[gx][gy] = visit[gox][goy] + 1;
      }
    }
  }
}
bfs(r1, c1);
console.log(visit[r2][c2]);