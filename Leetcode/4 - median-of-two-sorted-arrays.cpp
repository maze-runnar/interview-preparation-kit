class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i, key, j;  
        for(int i=0;i < nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
        if(nums1.size() % 2 != 0){
            int a =nums1.size()/2;
            return nums1[a];
        }else{
            int x = nums1.size() /2;
            int y = x - 1;
            double z = (nums1[x] + nums1[y] );
            double e = (float) z/2.0;
            return e;
        }
    }
};
