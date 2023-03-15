let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let [n, m, k, x] = input[0].split(' ').map(o => +o);
let visit = new Array(n + 1).fill(-1);
let matrix = {};
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
for (let i = 0; i <= n; i++){
  matrix[i] = [];
}
input.shift();
for (let i = 0; i < m; i++){
  let [from, to] = input[i].split(' ').map(o => +o);
  matrix[from].push(to);
}
let result = [];
const bfs = (start) => {
  let q = new Queue();
  q.push(start);
  visit[start] = 0;
  while (q.size() > 0) {
    let now = q.pop();
    if (visit[now] > k)
      continue;
    if (visit[now] === k)
      result.push(now);
    for (let i = 0; i < matrix[now].length; i++){
      let next = matrix[now][i];
      if (visit[next] === -1) {
        visit[next] = visit[now] + 1;
        q.push(next);
      }
    }
  }
}
bfs(x);
result.sort((o1, o2) => o1 - o2);
let output = "";
result.map(o => output += o + '\n');
if (result.length === 0)
  console.log(-1);
else
  console.log(output);
