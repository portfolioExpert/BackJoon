let input = require('fs').readFileSync('/dev/stdin').toString().split(' ');
let a = parseInt(input[0])
let b = parseInt(input[1])
let c = parseInt(input[2])
let visit = Array.from({ length: 201 }, () =>
    Array.from({ length: 201 }, () => Array.from({ length: 201 }, () => 0))
);

let result = []
function bfs() {
    //초반 C만 가득차있으므로
    let q = []
    q.push([0, 0, c])
    while (q.length > 0) {
        let now = q.shift();
        if (visit[now[0]][now[1]][now[2]] === 1)
            continue
        if (now[0] === 0) {
            result.push(now[2])
        }
        visit[now[0]][now[1]][now[2]] = 1 // 방문처리
        //나누어줄 물통 선정 -> 비거나 꽉찰 때 까지
        //0 0 10 -> 8 0 2, 0 9 1

        //가득채울 경우, 한 물통이 비는 경우로 나눠서 계산

        //0에서 1
        if (now[0] + now[1] > b)
            q.push([now[0] + now[1] - b, b, now[2]])
        else
            q.push([0, now[0] + now[1], now[2]])

        //0에서 2
        if (now[0] + now[2] > c)
            q.push([now[0] + now[1] - c, now[1], c])
        else
            q.push([0, now[1], now[0] + now[2]])

        //1에서 0
        if (now[1] + now[0] > a)
            q.push([a, now[1] + now[0] - a, now[2]])
        else
            q.push([now[1] + now[0], 0, now[2]])

        //1에서 2
        if (now[1] + now[2] > c)
            q.push([now[0], now[1] + now[2] - c, c])
        else
            q.push([now[0], 0, now[1] + now[2]])

        //2에서 0
        if (now[2] + now[0] > a)
            q.push([a, now[1], now[2] + now[0] - a])
        else
            q.push([now[2] + now[0], now[1], 0])

        //2에서 1
        if (now[2] + now[1] > b)
            q.push([now[0], b, now[2] + now[1] - b])
        else
            q.push([now[0], now[2] + now[1], 0])
    }
}

bfs()
let s = new Set(result)
result = [...s]
result.sort((a, b) => a - b)
for (let i of result) {
    console.log(i)
}