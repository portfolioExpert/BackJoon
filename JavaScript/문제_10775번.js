let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let g = +input[0];
let p = +input[1];
let parent = new Array(g + 1);
const find = (node) => {
  if (parent[node] === node)
    return node;
  return parent[node] = find(parent[node]);
}
const merge = (node1, node2) => {
  node1 = find(node1);
  node2 = find(node2);
  parent[node1] = node2;
}
//parent는 현재 게이트에서 도킹 시킬 수 있는 비행기 개수를 의미
for (let i = 0; i <= g; i++){
  parent[i] = i;
}

let result = +0;
for (let i = 2; i < 2 + p; i++){
  let par = find(+input[i]);
  // 부모가 0이면 더 이상 도킹 할 수 가없다.
  // 현 노드에서 -1과 머지 시키는 이유는 현재 게이트에 도킹시키고 -1번째 게이트에서 도킹시킬 수 있는 비행기 수를
  // 따라가게 하기 위해
  if (par != 0) {
    merge(par, par - 1);
    result++;
  }
  else
    break;
}
console.log(result);