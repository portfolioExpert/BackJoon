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
input = input[0].split(' ');
let start = +input[0];
let end = +input[1];
let visit = new Array(100001).fill(+999999999);
let dis = [1, -1, 2];
const bfs = (node) => {
  let q = new Queue();
  q.push(node);
  visit[node] = 0;
  while (q.size() > 0) {
    let now = q.pop();
    for (let i = 0; i < 3; i++) {
      let next = now + dis[i];
      if (i == 2) {
        next = now * 2;
        if (visit[next] > visit[now]) {
          q.push(next);
          visit[next] = visit[now];
        }
      }
      else if (next <= 100000 && next >= 0 && visit[next] > visit[now] + 1) {
        q.push(next);
        visit[next] = visit[now] + 1;
      }
    }
  }
}
bfs(start);
console.log(visit[end]);