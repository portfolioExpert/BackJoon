let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
input[0] = input[0].split(' ');
let num = input[1].split(' ');
let n = input[0][0];
let c = input[0][1];
let m = new Map();
for (let i = 0; i < num.length; i++) {
    if (!m.has(num[i]))
        m.set(num[i], 1);
    else
        m.set(num[i], m.get(num[i]) + 1);
}
let arr = [...m];
arr.sort((o1, o2) => {
    return o2[1] - o1[1];
})
let result = [];
for (let i = 0; i < arr.length; i++) {
    for (let j = 0; j < arr[i][1]; j++) {
        result.push(+arr[i][0]);
    }
}
console.log(result.join(' '));