let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
for (let i = 0; i < input.length; i++) {
    input[i] = input[i].split(' ');
}
let n = +input[0][0];
let m = +input[0][1];
let map = new Map();
for (let i = 1; i <= n; i++) {
    map.set(input[i][0], input[i][1]);
}
let result = [];
for (let i = n + 1; i <= m + n; i++) {
    result.push(input[i][0]);
}
console.log(result.map(res => map.get(res)).join('\n'));