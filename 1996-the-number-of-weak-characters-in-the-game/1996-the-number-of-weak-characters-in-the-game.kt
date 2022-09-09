import java.lang.Integer.max

class Solution {
fun numberOfWeakCharacters(properties: Array<IntArray>): Int {
    Arrays.sort(properties) { a, b -> if (a[0] == b[0]) a[1] - b[1] else b[0] - a[0] }
    var maxValue = Int.MIN_VALUE
    var answer = 0
    for (x in properties) {
        if (x[1] < maxValue)
            answer++
        maxValue = max(maxValue, x[1])
    }
    return answer
}
}