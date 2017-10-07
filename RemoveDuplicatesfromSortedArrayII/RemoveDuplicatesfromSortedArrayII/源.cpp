#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;

		int index = 1, count = 1;
		for (unsigned int i = 1; i < nums.size(); i++) {
			if (nums[i] != nums[index - 1]) {
				nums[index++] = nums[i];
				count = 1;
			}
			else {
				count++;
				if (count <= 2)
					index++;
			}
		}
		return index;
	}

	void print(vector<int>& nums, unsigned int length) {
		for (unsigned int i = 0; i < length; i++)
			cout << nums.at(i) << " ";
		cout << endl;
	}
};

int main(int argc, char *argv[]) {
	vector<int> nums;
	nums.push_back(1); nums.push_back(1); nums.push_back(1);
	nums.push_back(2); nums.push_back(2); nums.push_back(3);
	nums.push_back(3); nums.push_back(3); nums.push_back(4);

	Solution s;

	s.print(nums, 9);
	s.print(nums, s.removeDuplicates(nums));
	
	system("pause");
	return 0;
}