let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
for (let i = 0; i < input.length; i++) {
    input[i] = input[i].split(' ');
}
let n = +input[0][0];
let m = +input[0][1];
let num = [];
for (let i = 0; i < n; i++) {
    num.push(+input[1][i]);
}
const output = [];
const dfs = (len, list) => {
    if (len == m) {
        output.push(list.join(' '));
        return;
    }
    for (let i = 0; i < n; i++) {
        list.push(num[i]);
        dfs(len + 1, list);
        list.pop();
    }
}
num.sort((o1, o2) => {
    return o1 - o2;
})
dfs(+0, []);
console.log(output.join('\n'));