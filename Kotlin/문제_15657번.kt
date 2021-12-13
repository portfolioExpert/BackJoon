import java.util.*;

fun dfs(index : Int, result : ArrayList<Int>, n : Int, arr : ArrayList<Int>, m : Int){
    if(result.size == m){
        for(i in result){
            print("${i} ")
        }
        println()
        return
    }
    for(i in index until n){
        result.add(arr[i])
        dfs(i, result, n, arr, m)
        result.remove(arr[i])
    }
}
fun main(){
    var br = System.`in`.bufferedReader()
    var input = br.readLine().split(" ")
    var n = input[0].toInt()
    var m = input[1].toInt()
    input = br.readLine().split(" ")
    val arr = arrayListOf<Int>()
    val result = arrayListOf<Int>()
    for(i in 0 until n){
        arr.add(input[i].toInt())
    }
    arr.sort()
    dfs(0, result, n, arr, m)
}