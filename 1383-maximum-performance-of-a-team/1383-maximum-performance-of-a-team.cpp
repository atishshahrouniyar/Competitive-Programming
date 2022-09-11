class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<pair<int, int>> efficiencySpeed(n);
    for (int i = 0; i < n; ++i) {
        efficiencySpeed[i] = { efficiency[i], speed[i] };
    }
    sort(efficiencySpeed.rbegin(), efficiencySpeed.rend());
    long long sum = 0, answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto& x : efficiencySpeed) {
        pq.push(x.second);
        sum += x.second;
        if (pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }
        answer = max(answer, sum * x.first);
    }
    return answer % (1000000007);
}
};