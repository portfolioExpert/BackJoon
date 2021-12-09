import java.util.*;

fun main(){
    var br = System.`in`.bufferedReader()
    val first = br.readLine()
    var result = arrayListOf<String>()
    for (i in 0 until first.length){
        result.add(first.substring(i.. first.length - 1))
    }
    result.sort()
    for(i in result)
        println(i)
}