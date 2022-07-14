class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
	int n = nums.size();
	sort(nums.begin(), nums.end());
	int i = 0;
	vector<vector<int>> ans;
	while (i < n)
	{
		int fin = 0 - nums[i];
		int low = i + 1, high = n - 1;
		while (low < high)
		{
			if (nums[low] + nums[high] == fin)
			{
				ans.push_back({ nums[i],nums[low],nums[high] });
				while (low < high && nums[low] == nums[low + 1])
					low++;
				while (low < high && nums[high] == nums[high - 1])
					high--;
				high--;
				++low;
			}
			else if (nums[low] + nums[high] > fin)
				high--;
			else ++low;

		}
		while (i+1<n && nums[i] == nums[i + 1])
			++i;
		++i;
	}
	return ans;
}
};