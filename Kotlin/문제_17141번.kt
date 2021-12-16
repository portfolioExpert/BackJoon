import java.util.*;

class Pair(
    val x : Int,
    val y : Int
)
var map : Array<IntArray> = arrayOf()
var dp : Array<IntArray> = arrayOf()
var virusPos = arrayListOf<Pair>()
var virus = arrayListOf<Pair>()
val dx = intArrayOf(1, -1, 0, 0)
val dy = intArrayOf(0, 0, 1, -1)
var result = Int.MAX_VALUE
fun bfs(n : Int){
    var q : Queue<Pair> = LinkedList()
    for(i in virus){
        q.add(i)
    }
    dp = Array(n, {IntArray(n)})
    for(i in 0 until n){
        for(j in 0 until n){
            dp[i][j] = -1
        }
    }
    for(i in q){
        dp[i.x][i.y] = 0
    }
    var time = 0
    while(!q.isEmpty()){
        var gox = q.peek().x
        var goy = q.poll().y
        for(i in 0 until 4){
            var gx = gox + dx[i]
            var gy = goy + dy[i]
            if(gx >= 0 && gx < n && gy >= 0 && gy < n && (map[gx][gy] == 0 || map[gx][gy] == 2) && dp[gx][gy] == -1){
                dp[gx][gy] = dp[gox][goy] + 1
                q.add(Pair(gx, gy))
                time = Math.max(time, dp[gx][gy])
            }
        }
    }
    for(i in 0 until n){
        for(j in 0 until n){
            if(map[i][j] == 0 && dp[i][j] == -1)
                return
        }
    }
    result = Math.min(result, time)
}
fun dfs(cnt : Int, m : Int, n: Int, index : Int){
    if(cnt == m){
        bfs(n)
        return
    }
    for(i in index until virusPos.size){
        virus.add(virusPos[i])
        dfs(cnt + 1, m, n, i + 1)
        virus.remove(virusPos[i])
    }
}
fun main(){
    var br = System.`in`.bufferedReader()
    var input = br.readLine().split(" ")
    var n = input[0].toInt()
    var m = input[1].toInt()
    map = Array(n, {IntArray(n)})
    for(i in 0 until n){
        input = br.readLine().split(" ")
        for(j in 0 until n){
            map[i][j] = input[j].toInt()
            if(map[i][j] == 2){
                virusPos.add(Pair(i, j))
            }
        }
    }

    dfs(0, m, n, 0)
    if(result == Int.MAX_VALUE)
        println(-1)
    else
        println(result)
}