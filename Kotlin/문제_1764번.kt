import java.util.*;

fun main(){
    val br = System.`in`.bufferedReader()
    var input = br.readLine().split(" ")
    var n = input[0].toInt()
    var m = input[1].toInt()
    val map = mutableMapOf<String, Int>()
    var result = 0
    for(i in 0 until n){
        var str = br.readLine()
        map.put(str, 1)
    }
    for(i in 0 until m){
        var str = br.readLine()
        if(map.containsKey(str)) {
            map.put(str, map.getValue(str) + 1)
            result++
        }
        else
            map.put(str, 1)
    }
    var ChangeMap = map.keys.sorted()
    println(result)
    for(i in ChangeMap)
        if(map[i] == 2)
            println(i)
}