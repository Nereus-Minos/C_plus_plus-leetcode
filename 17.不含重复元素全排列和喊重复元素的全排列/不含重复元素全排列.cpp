bool IsSwap(vector<int>&a, int start, int end)
{
    for(int i = start; i<end; i++)
        if(a[i] == a[end])
            return false;
    
    return true;
}
void swap(vector<int>&a, int i, int j)
{
    int temp;
    temp = a[j];
    a[j] = a[i];
    a[i] = temp;
}

void de_prem(vector<int>&a, int start, int end, vector<vector<int>>&ret)
{
    if(start == end)
    {
        vector<int>::iterator iter;
        for(iter=a.begin(); iter<a.end(); iter++)
        {
            cout << (*iter) << "   ";
        }
        cout<<endl;
        
        ret.push_back(a);
        return ;
    }
    else
    {
        for(int i = start; i <= end; i++)
        {
			//去重的全排列就是与头元素i交换的元素j不能与i~j之间的元素一样，这样才能保证前缀不一样！！！
            if(IsSwap(a, start, i))
            {
                swap(a, start, i);
                de_prem(a, start+1, end, ret);  //每次选择子后一个元素为开始第一个元素
                swap(a, i, start);
            }
            
        }
    }
}