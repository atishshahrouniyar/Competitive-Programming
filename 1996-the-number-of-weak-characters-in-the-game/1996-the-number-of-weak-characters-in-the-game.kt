import java.lang.Integer.max

class Solution {
fun numberOfWeakCharacters(properties: Array<IntArray>): Int {
    properties.sortBy { it[1] }
    properties.sortByDescending { it[0] }
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