let dx = [1, - 1, 0, 0];
let dy = [0, 0, 1, -1];
let result = 0;
let visit = new Array(51)
for (let i = 0; i < 51; i++) {
    visit[i] = new Array(51);
}
let input = require("fs").readFileSync('/dev/stdin').toString().trim().split("\n");
let n = +input[0];
let map = input.slice(1).map(v => v.split(""));
function rowdfs(x, y, ch) {
    if (x < 0 || x >= n || y < 0 || y >= n || ch != map[x][y] || visit[x][y])
        return 0
    visit[x][y] = 1
    //세로
    let row = 0;
    row += rowdfs(x + dx[0], y, ch) + rowdfs(x + dx[1], y, ch) + 1;
    visit[x][y] = 0
    return row;
}

function coldfs(x, y, ch) {
    if (x < 0 || x >= n || y < 0 || y >= n || ch != map[x][y] || visit[x][y])
        return 0
    visit[x][y] = 1
    //가로
    let col = 0;
    col += coldfs(x, y + dy[2], ch) + coldfs(x, y + dy[3], ch) + 1
    visit[x][y] = 0
    return col
}

for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
        for (let k = 0; k < 4; k++) {
            if (i + dx[k] >= 0 && i + dx[k] < n && j + dy[k] >= 0 && j + dy[k] < n) {
                let save = map[i][j]
                map[i][j] = map[i + dx[k]][j + dy[k]]
                map[i + dx[k]][j + dy[k]] = save
                result = Math.max(result, rowdfs(i, j, map[i][j]))
                result = Math.max(result, coldfs(i, j, map[i][j]))
                map[i + dx[k]][j + dy[k]] = map[i][j]
                map[i][j] = save
            }
        }
    }
}
console.log(result)