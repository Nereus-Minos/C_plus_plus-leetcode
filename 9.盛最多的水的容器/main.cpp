#if 1
/*
方法二：双指针法

算法

思路：两线段之间形成的区域总是会受到其中较短那条长度的限制。此外，两线段距离越远，得到的面积就越大。所以每次将指向较短线段的指针向较长线段那端移动一步。与之前面积比较

我们在由线段长度构成的数组中使用两个指针，一个放在开始，一个置于末尾。 此外，我们会使用变量 maxarea 来持续存储到目前为止所获得的最大面积。 在每一步中，我们会找出指针所指向的两条线段形成的区域，更新 maxarea，并将指向较短线段的指针向较长线段那端移动一步。
*/
class Solution {
    
    public:
    int maxArea(vector<int>& height) {
        //特殊情况
        if(height.size() < 2)
            return 0;
        
        //使用双指针法
        int start = 0;
        int end = height.size()-1;
        int maxarea = min(height[start], height[end])*(end-start);
        
        while((end-1) > start)
        {
            if(height[end] > height[start])
            {
                maxarea = max(min(height[start+1], height[end])*(end-start-1), maxarea);
                start++;
            }
            else
            {
                maxarea = max(min(height[start], height[end-1])*(end-start-1), maxarea);
                end--;
            }
        }
        return maxarea;
    }
};
#endif


#if 0
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        //特殊情况
        if(height.size() < 2)
            return 0;
        
        //使用冒泡排序思想,但是超出时间限制
        int ret = 0;
        int i,j;
        int temp = 0;
        for(i = 0; i<height.size()-1; i++)
            for(j = i+1; j<height.size(); j++)
            {
                if(height[i]<=height[j])
                    temp = height[i] * (j-i);
                else
                    temp = height[j] * (j-i);
                if(temp > ret)
                    ret = temp;
            }
        return ret;
    }
};
#endif