class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int index = 0;
        while (true) {
            if (nums[index] == -1) {
                return index;
            }
            
            int next = nums[index];
            nums[index] = -1;
            index = next;
        }
    }
};

