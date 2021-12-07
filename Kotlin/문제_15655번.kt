import java.util.*;

fun dfs(n: Int, m : Int, index: Int, result: ArrayList<Int>, arr : ArrayList<Int>){
    if(result.size == m){
        for(i in result)
            print("${i} ")
        println()
        return
    }
    for(i in index + 1 until n){
        result.add(arr[i])
        dfs(n, m, i, result, arr)
        result.remove(arr[i])
    }
}
fun main(){
    var br = System.`in`.bufferedReader()
    var input = br.readLine().split(" ")
    var n = input[0].toInt()
    var m = input[1].toInt()
    var result = arrayListOf<Int>()
    var arr = arrayListOf<Int>()
    input = br.readLine().split(" ")
    for(i in 0 until n){
        arr.add(input[i].toInt())
    }
    arr.sort()
    dfs(n, m, -1, result, arr)
}