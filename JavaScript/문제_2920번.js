let num = require('fs').readFileSync('/dev/stdin').toString().split(' ');
let as = true, ds = true;
for (let i = 1; i <= 8; i++) {
    if (num[i - 1] != i) {
        as = false;
        break;
    }
}

for (let i = 8; i >= 1; i--) {
    if (num[8 - i] != i) {
        ds = false;
        break;
    }
}
if (as)
    console.log("ascending");
else if (ds)
    console.log("descending")
else
    console.log("mixed")