let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let next = input[0];
let cnt = +0;
while (next.length > 1) {
    let sum = +0;
    for (let i = 0; i < next.length; i++) {
        sum += +next[i];
    }
    next = sum.toString();
    cnt++;
}
console.log(cnt);
if (+next === 3 || +next === 6 || +next === 9)
    console.log("YES");
else
    console.log("NO");