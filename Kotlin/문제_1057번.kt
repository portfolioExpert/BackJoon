import java.util.*;

fun main(){
    var br = System.`in`.bufferedReader()
    var before = arrayListOf<Int>()
    var after = arrayListOf<Int>()
    var input = br.readLine().split(" ")
    var round = 1
    var n = input[0].toInt()
    var jimin = input[1].toInt()
    var han = input[2].toInt()
    for(i in 1..n)
        before.add(i)
    while(true){
        if(after.size == 1) {
            println(-1)
            return
        }
        for(i in 0 until before.size step 2){
            if(i >= before.size - 1) {
                after.add(before[i])
                continue
            }
            if(before[i] == jimin && before[i+1] == han) {
                println(round)
                return
            }
            if(before[i+1] == jimin && before[i] == han) {
                println(round)
                return
            }
            if(before[i+1] == jimin || before[i+1] == han)
                after.add(before[i+1])
            else
                after.add(before[i])
        }
        before.clear()
        for(i in 0 until after.size)
            before.add(after[i])
        after.clear()
        round++
    }
}