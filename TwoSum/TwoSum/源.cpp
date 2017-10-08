//Two Sum
//ÃèÊö
//Given an array of integers, find two numbers such that they add up to a specific target number.
//The function twoSum should return indices of the two numbers such that they add up to the target, where
//index1 must be less than index2.Please note that your returned answers(both index1 and index2) are
//not zero - based.
//You may assume that each input would have exactly one solution.
//Input: numbers = { 2, 7, 11, 15 }, target = 9
//Output : index1 = 1, index2 = 2

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