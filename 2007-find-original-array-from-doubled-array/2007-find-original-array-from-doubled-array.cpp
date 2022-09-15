class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() & 1)
            return {};
        map<int, int> freq;
        for(int x : changed)
            freq[x]++;
        vector<int> keys;
        for(auto& x : freq)
            keys.push_back(x.first);
        sort(keys.begin(), keys.end());
        vector<int> answer;
        for(int x : keys){
            if(freq[x] > freq[2*x])
                return {};
            for(int i=0;i<freq[x];++i, freq[2*x]--)
                answer.push_back(x);
        }
        return answer;
    }
};