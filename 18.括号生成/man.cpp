 void match_huishu(int N, vector<string>&ret, string temp, int left, int right)
	{
		if(temp.length() == 2*N)
		{
			ret.push_back(temp);
		}
		
		if(left < N)
		{
			match_huishu(N, ret, temp+'(', left+1, right);
		}
		if(right < left)
		{
			match_huishu(N, ret, temp+')', left, right+1);
		}
	}