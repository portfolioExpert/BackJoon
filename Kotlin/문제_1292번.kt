import java.util.*;

fun main(){
    var arr = arrayListOf<Int>()
    var br = System.`in`.bufferedReader()
    var input = br.readLine().split(" ")
    var a = input[0].toInt()
    var b = input[1].toInt()
    var result = 0
    for(i in 1..1000){
        for(j in 0 until i){
            arr.add(i)
        }
    }
    for(i in a-1..b-1){
        result+=arr[i]
    }
    println(result)
}