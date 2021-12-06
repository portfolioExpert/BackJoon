import java.util.*;

fun main(){
    var br = System.`in`.bufferedReader()
    var n = br.readLine().toInt()
    var input = br.readLine().split(" ")
    var dis = longArrayOf()
    dis = LongArray(n)
    for(i in 0 until n - 1){
        dis[i] = input[i].toLong()
    }
    input = br.readLine().split(" ")
    var cost = longArrayOf()
    cost = LongArray(n)
    for(i in 0 until n){
        cost[i] = input[i].toLong()
    }

    var weight = cost[0]
    var result : Long = dis[0] * cost[0]
    for(i in 1 until n - 1){
        if(weight < cost[i]){
            result += weight * dis[i]
        }
        else{
            result += cost[i] * dis[i]
            weight = cost[i]
        }
    }
    println(result)
}