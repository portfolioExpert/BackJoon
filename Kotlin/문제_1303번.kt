import java.util.*;

class Pair(
    val x : Int,
    val y : Int
)
var map : Array<CharArray> = arrayOf()
var visit : Array<BooleanArray> = arrayOf()
val dx = intArrayOf(1, -1, 0, 0)
val dy = intArrayOf(0, 0, 1, -1)
fun bfs(x : Int , y : Int, m : Int, n : Int): Int{
    var q : Queue<Pair> = LinkedList()
    q.add(Pair(x, y))
    visit[x][y] = true
    var sum = 1
    while(!q.isEmpty()){
        val gox = q.peek().x
        val goy = q.poll().y
        for(i in 0 until 4){
            var gx = gox + dx[i]
            var gy = goy + dy[i]
            if(gx >= 0 && gx < m && gy >= 0 && gy < n && map[gx][gy] == map[x][y] && visit[gx][gy] == false){
                visit[gx][gy] = true
                q.add(Pair(gx,gy))
                sum++
            }
        }
    }
    return sum
}
fun main(){
    var br = System.`in`.bufferedReader()
    var input = br.readLine().split(" ")
    var n = input[0].toInt()
    var m = input[1].toInt()
    map = Array(m, {CharArray(n + 1)})
    visit = Array(m, {BooleanArray(n + 1)})
    for(i in 0 until m){
        var input2 = br.readLine()
        for(j in 0 until n){
            map[i][j] = input2[j]
        }
    }
    var myScore = 0
    var enemy = 0
    for(i in 0 until m){
        for(j in 0 until n){
            if(visit[i][j] == false){
                var total = bfs(i, j, m, n)
                if(map[i][j] == 'W')
                    myScore+=total * total
                else
                    enemy+=total * total
            }
        }
    }
    println("${myScore} ${enemy}")
}