#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // assume nums[lo] <= value;
    // nums[ret] < value <= nums[ret+1]
    // or ret ==  hi if value > nums[hi]
    // or ret == lo-1 if value<= nums[lo];
    int binarySearch(vector<int>& nums, int lo, int hi, int value){
	if(lo > hi)
	    return -1;
        int left = lo;
        int right = hi;
	if(nums[hi] < value)
	    return hi;
	if(nums[lo] >= value)
	    return lo-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid] < value && nums[mid+1]>=value)
                return mid;
            if(nums[mid] >= value)
                right = mid;
            else if(nums[mid] < value)
                left = mid;
        }
        return hi;
    }

    int findKthElement(vector<int>& nums1, vector<int>& nums2, int lo1, int hi1, int lo2, int hi2, int k){
	if(hi1 < lo1)
	    return nums2[lo2+k-1];
	if(hi2 < lo2)
	    return nums1[lo1+k-1];

        int mid = lo1+(hi1-lo1)/2;
        int mid_in_nums2 = binarySearch(nums2, lo2, hi2, nums1[mid]);
	int count = (mid-lo1) + (mid_in_nums2-lo2) +2;
        if(count == k)
            return nums1[mid];
	else if(count < k){
	    return findKthElement(nums2, nums1, mid_in_nums2+1, hi2, mid+1, hi1, k-count);
	} else if (count > k){
	    return findKthElement(nums2, nums1, lo2, mid_in_nums2, lo1, mid-1, k);
	}
	return 0;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        if(size == 0)
            return 0;
        if(size%2 == 1){
            return findKthElement(nums1, nums2, 0, nums1.size()-1, 0, nums2.size()-1, size/2+1);
        } else{
            int lo_median = findKthElement(nums1, nums2, 0, nums1.size()-1, 0, nums2.size()-1, size/2);
            int hi_median = findKthElement(nums1, nums2, 0, nums1.size()-1, 0, nums2.size()-1, size/2+1);
            return (lo_median+hi_median)/2.0;
        }
	return 0;
    }
};


int main(int argc, char *argv[])
{
    vector<int> nums1 = {3,4,5};
    vector<int> nums2 = {1,2};
    Solution sol;
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
