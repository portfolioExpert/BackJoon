import java.util.*;

fun main(){
    val br = System.`in`.bufferedReader()
    val str : String = br.readLine()
    val s = Stack<Char>()
    var sum = 0
    var i = 0
    while(i < str.length - 1){
        if(str.get(i) == '(' && str.get(i+1) == ')'){
            sum+=s.size
            i+=2
            continue
        }
        if(str.get(i) == '(') {
            s.push(str.get(i))
            sum++
        }
        else
            s.pop()
        i++
    }
    println(sum)
}