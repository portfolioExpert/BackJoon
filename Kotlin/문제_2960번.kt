import java.util.*;

fun main(){
    var br = System.`in`.bufferedReader()
    var input = br.readLine().split(" ")
    var n = input[0].toInt()
    var k = input[1].toInt()
    var visit = booleanArrayOf()
    visit = BooleanArray(n + 1)
    visit[1] = true
    var cnt = 0
    var result = 0
    for(i in 2..n){
        if(visit[i] == true)
            continue
        cnt++
        if(cnt == k) {
            println(i)
            return
        }
        for(j in i+i..n step i){
            if(visit[j] == true)
                continue
            visit[j] = true
            cnt++
            if(cnt == k) {
                println(j)
                return
            }
        }
    }
}