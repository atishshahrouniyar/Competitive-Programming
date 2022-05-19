class Solution {
public:
    bool isPalindrome(int x) {
        string temp1=to_string(x), temp2=temp1;
        reverse(temp2.begin(), temp2.end());
        return temp1==temp2;
    }
};