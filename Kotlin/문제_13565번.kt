import java.util.*;

class Pair(
    val x : Int,
    val y : Int
)

var map : Array<IntArray> = arrayOf()
var visit : Array<BooleanArray> = arrayOf()
var dx = intArrayOf(1, -1, 0, 0)
var dy = intArrayOf(0, 0, 1, -1)
fun bfs(q : Queue<Pair>, m : Int, n : Int){
    while(!q.isEmpty()){
        var gox = q.peek().x
        var goy = q.poll().y
        for(i in 0 until 4){
            var gx = gox + dx[i]
            var gy = goy + dy[i]
            if(gx >= 0 && gx < m && gy >= 0 && gy < n && map[gx][gy] == 0 && visit[gx][gy] == false){
                visit[gx][gy] = true
                q.add(Pair(gx, gy))
            }
        }
    }
}
fun main(){
    var br = System.`in`.bufferedReader()
    var input = br.readLine().split(" ")
    var m = input[0].toInt()
    var n = input[1].toInt()
    var q : Queue<Pair> = LinkedList()
    map = Array(m, { IntArray(n) })
    visit = Array(m, {BooleanArray(n)})
    for(i in 0 until m){
        var str = br.readLine()
        for(j in 0 until n){
            map[i][j] = (str[j] - 48).toInt()
            if(i == 0 && map[i][j] == 0){
                q.add(Pair(i,j))
            }
        }
    }
    bfs(q, m, n)
    for(i in 0 until n){
        if(visit[m-1][i] == true){
            println("YES")
            return
        }
    }
    println("NO")
}