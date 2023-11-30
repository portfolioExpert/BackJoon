let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let n = +input[0];
let stack = [];
let result = '';
for (let i = 1; i < input.length; i++) {
  let comm = +input[i][0];
  switch (comm) {
    case 1: let num = +input[i].slice(2);
      stack.push(num);
      break;
    case 2: if (stack.length != 0) {
      result += stack.pop();
    }
    else {
      result += '-1';
    }
      result += '\n';
      break;
    case 3: result += stack.length;
      result += '\n';
      break;
    case 4: if (stack.length == 0)
      result += '1';
    else
      result += '0';
      result += '\n';
      break;
    case 5: if (stack.length != 0) {
      result += stack[stack.length - 1];
      result += '\n';
    }
    else {
      result += '-1';
      result += '\n';
    }
  }
}
console.log(result);