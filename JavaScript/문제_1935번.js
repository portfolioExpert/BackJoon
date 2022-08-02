let input = require('fs').readFileSync('/dev/stdin').toString().split('\n')
let n = +input[0]
let str = input[1]
let s = []
let j = 0;
let m = new Map()
//매칭 시키기
for (let i = 2; i < n + 2 && j < str.length; j++) {
    if (str[j] >= 'A' && str[j] <= 'Z' && !m.has(str[j])) {
        m.set(str[j], +input[i])
        i++
    }
}


for (let i = 0; i < str.length; i++) {
    //100이하 자연수를 해줘야한다
    if (str[i] >= 'A' && str[i] <= 'Z') {
        s.push(m.get(str[i]))
    }
    else {
        let right = s.pop()
        let left = s.pop()
        switch (str[i]) {
            case '*':
                s.push(left * right)
                break
            case '/':
                s.push(left / right)
                break
            case '+':
                s.push(left + right)
                break
            case '-':
                s.push(left - right)
                break
        }
    }
}
console.log(s.pop().toFixed(2))