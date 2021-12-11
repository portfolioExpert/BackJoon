import java.util.*;

fun getGCD(num1 : Int, num2: Int): Int{
    var maxVal = Math.max(num1, num2)
    var minVal = Math.min(num1, num2)
    while(minVal > 0){
        val div = maxVal % minVal
        maxVal = minVal
        minVal = div
    }
    return maxVal
}
fun main(){
    var br = System.`in`.bufferedReader()
    var t = br.readLine().toInt()
    for(i in 0 until t){
        var input = br.readLine().split(" ")
        var n = input[0].toInt()
        var arr = arrayListOf<Int>()
        for(i in 1..n){
            arr.add(input[i].toInt())
        }
        var result : Long = 0
        for(i in 0 until n){
            for(j in i+1 until n){
                result+=getGCD(arr[i], arr[j])
            }
        }
        println(result)
    }
}