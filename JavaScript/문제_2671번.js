let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const regExp = /^(100+1+|01)+$/
console.log(regExp.test(input[0]) ? "SUBMARINE" : "NOISE")