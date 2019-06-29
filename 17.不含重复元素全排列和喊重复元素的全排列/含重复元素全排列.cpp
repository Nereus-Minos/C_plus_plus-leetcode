void swap(vector<int>&a, int i, int j)
{
    int temp;
    temp = a[j];
    a[j] = a[i];
    a[i] = temp;
}

void prem(vector<int>&a, int start, int end, vector<vector<int>>&ret)
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
            swap(a, start, i);
            prem(a, start+1, end, ret);  //每次选择子后一个元素为开始第一个元素
            swap(a, i, start);
        }
    }
}