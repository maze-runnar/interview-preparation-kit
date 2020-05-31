class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int x;
        int y;
        vector<int> m;
        for(int i =0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int res;
                res = nums[i] + nums[j];
                if(res == target){
                    m.push_back(i);
                    m.push_back(j);
                    break;
                }
            }
        }
        return m;
        
    }
};
