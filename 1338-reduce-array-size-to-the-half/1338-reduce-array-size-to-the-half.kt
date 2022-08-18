class Solution {
    fun minSetSize(arr: IntArray): Int {
    val freq = mutableMapOf<Int, Int>()
    for (number in arr) {
        if (number !in freq)
            freq[number] = 1
        else
            freq[number] = freq[number]!! + 1
    }
    val frequencies = freq.values.sortedDescending()
    var halfArraySize = (arr.size + 1) / 2
    for (i in frequencies.indices) {
        halfArraySize -= frequencies.elementAt(i)
        if (halfArraySize <= 0)
            return i + 1
    }
    return frequencies.size
}
}