const dx = [1, -1, 0, 0, 1, -1, 1, -1];
const dy = [0, 0, 1, -1, 1, 1, -1, -1];
let input = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ');
let kingx = 8 - +input[0][1]
let kingy = input[0][0]
kingy = kingy.charCodeAt(0) - 65
let stonex = 8 - +input[1][1]
let stoney = input[1][0]
stoney = stoney.charCodeAt(0) - 65
let n = parseInt(input[2])
input = input.toString().trim().split("\n")
let command = []
for (let i = 0; i < n; i++) {
    command.push(input[i + 1])
}
for (let i = 0; i < n; i++) {
    let gox = 0, goy = 0
    switch (command[i]) {
        case 'B':
            gox = dx[0]
            goy = dy[0]
            break
        case 'T':
            gox = dx[1]
            goy = dy[1]
            break
        case 'R':
            gox = dx[2]
            goy = dy[2]
            break
        case 'L':
            gox = dx[3]
            goy = dy[3]
            break
        case 'RB':
            gox = dx[4]
            goy = dy[4]
            break
        case 'RT':
            gox = dx[5]
            goy = dy[5]
            break
        case 'LB':
            gox = dx[6]
            goy = dy[6]
            break
        case 'LT':
            gox = dx[7]
            goy = dy[7]
            break
    }
    //킹이 안나가고
    if (kingx + gox >= 0 && kingx + gox < 8 && kingy + goy >= 0 && kingy + goy < 8) {
        //돌도 안나가고
        if (stonex + gox >= 0 && stonex + gox < 8 && stoney + goy >= 0 && stoney + goy < 8) {
            //돌이 있다면 돌먼저 이동
            if (kingx + gox == stonex && kingy + goy == stoney) {
                stonex = stonex + gox
                stoney = stoney + goy
            }
        }
        //움직이는 자리에 돌이 없다면 이동
        if (kingx + gox != stonex || kingy + goy != stoney) {
            kingx = kingx + gox
            kingy = kingy + goy
        }
    }
}
console.log(String.fromCharCode(kingy + 65) + String(8 - kingx) + "\n" + String.fromCharCode(stoney + 65) + String(8 - stonex))