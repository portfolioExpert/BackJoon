let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

let n = +input[0];
let arr = [];
let parent = new Array(n + 1);
const find = (node) => {
  if (parent[node] == node)
    return node;
  return parent[node] = find(parent[node]);
}
const merge = (node1, node2) => {
  node1 = find(node1);
  node2 = find(node2);
  if (node1 != node2)
    parent[node2] = node1;
}

for (let i = 1; i <= n; i++){
  input[i] = input[i].split(' ').map(o => +o);
  arr.push(input[i]);
  parent[i] = i;
}
let pq = [];//간선, from, to
for (let i = 0; i < n; i++){
  for (let j = i + 1; j < n; j++){
    pq.push({ cost: arr[i][j], from: i, to: j });
  }
}
pq.sort((o1, o2) => {
  return o1.cost - o2.cost;
});
let result = 0;
for (let i = 0; i < pq.length; i++){
  let from = pq[i].from;
  let to = pq[i].to;
  let weight = pq[i].cost;
  if (find(from) != find(to)) {
    result += weight;
    merge(from, to);
  }
}
console.log(result);