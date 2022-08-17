class Solution {
public:
    vector<string> morseCodes{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> morseCodeWords;
        for(string word : words){
            string morseCodeWord = "";
            for(char character : word){
                morseCodeWord += morseCodes[character-'a'];
            }
            morseCodeWords.insert(morseCodeWord);
        }
        return morseCodeWords.size();
    }
};