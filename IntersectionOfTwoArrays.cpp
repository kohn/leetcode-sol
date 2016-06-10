class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]){
                i++;
                while(nums1[i] == nums1[i-1])
                    i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
                while(nums2[j] == nums2[j-1])
                    j++;
            }
            else{
                res.push_back(nums1[i]);
                i++;
                while(nums1[i] == nums1[i-1])
                    i++;
                j++;
                while(nums2[j] == nums2[j-1])
                    j++;
            }
        }
        return res;
    }
};
