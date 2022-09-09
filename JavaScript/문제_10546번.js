let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let n = +input[0];
input.shift();
const m = new Map();
for (let i = 0; i < input.length; i++) {
    if (!m.has(input[i]))
        m.set(input[i], 1);
    else
        m.set(input[i], m.get(input[i]) + 1);
}
let arr = []
for (let i of m) {
    if (i[1] % 2 != 0) {
        arr.push(i[0]);
    }
}
arr.map(item => console.log(item));