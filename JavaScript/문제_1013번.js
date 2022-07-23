let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let t = parseInt(input[0])
const regExp = /^(100+1+|01)+$/
for (let i = 1; i <= t; i++) {
    console.log(regExp.test(input[i]) ? "YES" : "NO")
}