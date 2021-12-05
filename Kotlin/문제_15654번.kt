import java.util.*;

var visit = booleanArrayOf()
var arr = arrayListOf<Int>()
fun dfs(num : ArrayList<Int>, cnt : Int, n : Int){
    if(cnt == n){
        for(i in arr)
            print("${i } ")
        println()
        return
    }
    for(i in num){
        if(visit[i] == false){
            visit[i] = true
            arr.add(i)
            dfs(num,cnt+1, n)
            arr.remove(i)
            visit[i] = false
        }
    }
}
fun main(){
    var br = System.`in`.bufferedReader()
    var input = br.readLine().split(" ")
    var n = input[0].toInt()
    var m = input[1].toInt()
    var num = arrayListOf<Int>()
    input = br.readLine().split(" ")
    for(i in 0 until n){
        num.add(input[i].toInt())
    }
    visit = BooleanArray(10001)
    num.sort()
    dfs(num,0, m)
}