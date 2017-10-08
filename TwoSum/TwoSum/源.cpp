#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
	vector<int> twoSum(vector<int> &nums, int target) {
		unordered_map<int, int> my_map;

		for (unsigned int i = 0; i < nums.size(); i++)
			my_map[nums[i]] = i;

		vector<int> result;
		for (auto i : nums) {
			if (my_map.find(target - i) != my_map.end()) {
				int small = min(i, target - i);
				result.push_back(my_map[small]);
				result.push_back(my_map[target - small]);
				break;
			}
		}	
		return result;
	}

	void print(vector<int>& nums) {
		for (vector<int>::iterator iter = nums.begin(); 
			iter != nums.end(); iter++)
			cout << *iter << " ";
		cout << endl;
	}
};

int main(){
	vector<int> nums;
	nums.push_back(2); nums.push_back(7); nums.push_back(11);
	nums.push_back(15); 

	Solution s;
	s.print(s.twoSum(nums, 17));

	system("pause");
	return 0;
}