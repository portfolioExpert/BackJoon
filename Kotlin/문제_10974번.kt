import java.util.*;

var visit = booleanArrayOf()
var arr = arrayListOf<Int>()
fun dfs(cnt : Int, n : Int){
    if(cnt == n){
        for(i in arr)
            print("${i } ")
        println()
        return
    }
    for(i in 1..n){
        if(visit[i] == false){
            visit[i] = true
            arr.add(i)
            dfs(cnt+1, n)
            arr.remove(i)
            visit[i] = false
        }
    }
}
fun main(){
    var br = System.`in`.bufferedReader()
    var n = br.readLine().toInt()
    visit = BooleanArray(n + 1)
    dfs(0, n)
}