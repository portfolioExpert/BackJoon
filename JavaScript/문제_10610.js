let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let str = input[0].split('');
let sum = +0;
for (let i = 0; i < str.length; i++){
  sum += parseInt(str[i]);
}
if (str.includes('0') && sum % 3 === 0) {
  str.sort((o1, o2) =>{
    return o2 - o1;
  })
  console.log(str.join(''));
}
else
  console.log(-1);