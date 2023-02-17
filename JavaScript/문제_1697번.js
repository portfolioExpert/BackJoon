let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let [n, m] = input[0].split(' ').map(o => +o);
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
let visit = new Array(100001).fill(+987654321);
let dis = [1, -1, 2];
const bfs = (start) => {
  let q = new Queue();
  q.push(start);
  visit[start] = 0;
  while (q.size() > 0) {
    let now = q.pop();
    for (let i = 0; i < 3; i++){
      let next = now + dis[i];
      if (i === 2)
        next = now * dis[i];
      if (next >= 0 && next <= 100000 && visit[next] > visit[now] + 1) {
        visit[next] = visit[now] + 1;
        q.push(next);
      }
    }
  }
}
bfs(n);
console.log(visit[m]);