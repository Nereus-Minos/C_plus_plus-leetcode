#if 0
//思路一：从头开始循环，每次找到<=height[i]的数（没找到，则使用次高点计算），去掉中间的高度，剩下的就是这块区域（i~next）的大小，然后i=next继续
class Solution {
public:
    int trap(vector<int>& height) {
        
        int i = 0, j = 0, second_h = 0;
        int next;
        int ret = 0;
        
        int len = height.size();  //不能直接用height.size()-2因为当长度为0时，这个值不为-2
        
        while(i < len-2)
        {
            if(height[i] == 0)
            {
                i++;
                continue;
            }
            
            second_h = i+1;
            //不能用函数lower_bound，因为无序
            next = my_next(height, i+1, height.size(), height[i], second_h);
            cout<<i<<"   "<<next<<"  "<<second_h<<endl;
            if(next == height.size())  //说明没有比这个高的了，则用次高位计算
            {
                ret += (second_h - i-1)*height[second_h];
                for(j = i + 1; j < second_h; j++)
                    ret -= height[j];
                i = second_h;
            }
            else
            {
                ret += (next - i-1)*height[i];
                for(j = i + 1; j < next; j++)
                    ret -= height[j];
                i = next;
            }
        }
        
        return ret;
    }
    
private:
    int my_next(vector<int>& height, int begin, int end, int target, int& second_h){
        
        for(int i = begin; i < end; i++)
        {
            if(height[second_h] <= height[i])
                second_h = i;
            
            if(height[i] >= target)
                return i;
        }
        
        return end;  //表明未找到
    }
};
#endif

#if 1
//双指针法：因为积水总是受到叫低的一端影响，所以可以每次将较低的指针朝着较高的一方移动，会到更高的就停止，将较低的指针移动，每次统计当前块的积水量
class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size() < 3)
            return 0;
        
        int temp1 = 0, temp2 = 0, i=0, j = height.size()-1, count = 0;
        while(i < j)
        {
            if(height[i] < height[j])
            {
                if(temp1 < height[i])
                    temp1 = height[i];
                else
                    count += temp1 - height[i];
                i++;
            }
            else
            {
               if(temp2 < height[j])
                    temp2 = height[j];
                else
                    count += temp2 - height[j];
                j--;
            }
        }
        return count;
    }
};
#endif