class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> freq;
        for(char x : s)
            freq[x]++;
        for(int i=0;i<s.length();++i){
            if(freq[s[i]]==1)
                return i;
        }
        return -1;
    }
};