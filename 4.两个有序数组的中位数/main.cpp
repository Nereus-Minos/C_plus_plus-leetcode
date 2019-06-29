class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //如果输入是一个有序序列，找到其中位数，应该是一个很简单的问题。但现在的输入是两个有序序列。 所以，要解决的第一个问题就是如何将两个有序序列合并成一个有序序列。 在考虑要求的时间复杂度的为O(log(m+n))的情况下，应考虑使用归并排序。归并排序的时间复杂度恰为O(log(m+n))。 所以，本题的解题思路为，先利用归并排序将两个有序序列合并为一个有序序列。然后求其中位数。
    
        //情况一：有一个为空
        if(nums2.empty())
        {
            if(nums1.size() % 2 == 0)
                return ((nums1[nums1.size()/2 - 1] + nums1[nums1.size()/2]) / 2.0);
            return nums1[(nums1.size()-1)/2];
        }
        if(nums1.empty())
        {
            if(nums2.size() % 2 == 0)
                return ((nums2[nums2.size()/2 - 1] + nums2[nums2.size()/2]) / 2.0);
            return nums2[(nums2.size()-1)/2];
        }
        
        //情况二：都不为空。使用归并排序, nums2，nums1归并到temp
        int i, j, k;  // i是nums1下标, j是nums2下标，k为temp下标
        vector<int> temp;  
        for(i = 0, k = 0, j = 0; i < nums1.size() && j < nums2.size(); k++)
        {
            if(nums1[i] < nums2[j])
                temp.push_back(nums1[i++]);
            else
                temp.push_back(nums2[j++]); 
        }
        //当num1.size() > nums2.size()
        while(i<nums1.size())
        {
            temp.push_back(nums1[i++]);
        }
        //当num1.size() < nums2.size()
        while(j<nums2.size())
        {
            temp.push_back(nums2[j++]);
        }
        
        //计算temp的中位数
        if(temp.size() % 2 == 0)
                return (temp[temp.size()/2 - 1] + temp[temp.size()/2]) / 2.0;
            return temp[(temp.size()-1)/2];
    }

};