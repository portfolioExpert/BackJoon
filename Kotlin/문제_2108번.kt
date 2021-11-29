import java.util.*;
import kotlin.math.roundToInt

fun getAverage(arrayList: ArrayList<Int>) : Int{
    return arrayList.average().roundToInt()
}
fun getMiddle(arrayList: ArrayList<Int>):Int{
    return arrayList[arrayList.size / 2]
}
fun frquency(map : MutableMap<Int,Int>):Int{
    //map에서 value중 가장 큰 값을 가지는 값
    val maxVal = map.maxOf { it.value }
    //value와 같은 값을 filter 해서 새로운 맵에 넣어 준다
    val maxFrequency = map.filter { it.value == maxVal }
    //value를 기준으로 정렬 시킨다
    val mapKeys = maxFrequency.keys.sorted()
    if(mapKeys.size == 1)
        return mapKeys.first()
    else
        return mapKeys[1]
}
fun main(){
    val br = System.`in`.bufferedReader()
    val arr = arrayListOf<Int>()
    val n : Int = br.readLine().toInt()
    val map = mutableMapOf<Int, Int>()
    for (i in 0 until n){
        val number = br.readLine().toInt()
        arr.add(number)
        if(map.containsKey(number)){
            map.put(number, map.getValue(number) + 1)
        }
        else
            map.put(number, 1)
    }
    arr.sort()//오름차순 정렬
    println(getAverage(arr))
    println(getMiddle(arr))
    println(frquency(map))
    println(arr[n-1] - arr[0])
}