let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let n = +input[0];
input.shift();
let m = new Map();
for (let word of input) {
    if (!m.has(word)) {
        m.set(word, 1);
    }
    else
        m.set(word, m.get(word) + 1);
}
let book = new Array(...m);
book.sort();
book.sort((o1, o2) => {
    return o2[1] - o1[1];
})
console.log((book[0][0]));