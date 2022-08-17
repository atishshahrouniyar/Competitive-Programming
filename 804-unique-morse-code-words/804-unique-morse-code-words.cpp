class Solution {
public:
    vector<string> morseCodes{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> uniqueMorseCodeWords;
        for(string word : words){
            string morseCodeWord = "";
            for(char character : word){
                morseCodeWord += morseCodes[character-'a'];
            }
            uniqueMorseCodeWords.insert(morseCodeWord);
        }
        return uniqueMorseCodeWords.size();
    }
};