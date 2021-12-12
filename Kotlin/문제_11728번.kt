import java.util.*;

fun main(){
    var br = System.`in`.bufferedReader()
    var bw = System.`out`.bufferedWriter()
    var input = br.readLine().split(" ")
    var n = input[0].toInt()
    var m = input[1].toInt()
    val total = arrayListOf<Int>()
    input = br.readLine().split(" ")
    for(i in 0 until n){
        total.add(input[i].toInt())
    }
    input = br.readLine().split(" ")
    for(i in 0 until m){
        total.add(input[i].toInt())
    }
    var result = total.sorted()
    for(i in 0 until result.size) {
        bw.write(result[i].toString())
        if(i == result.size-1)break
        bw.write(" ")
    }
    bw.flush()
    bw.close()
}