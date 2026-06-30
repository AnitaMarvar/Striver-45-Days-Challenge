vector<int> stringMatch(string text, string pattern) {
	vector<int>ans;

	int n = text.length();
	int m = pattern.length();
	if(m > n)return ans;

	long long base = 31;
	long long mod = 1e9 + 7;
	long long patHash = 0, txtHash = 0;
	long long power = 1;

	for(int i=0;i<m-1;i++)
	{
		power = (power * base) % mod;  //to remove the first element of window this will be useful
	}

  //for pattern and first window of text
	for(int i=0;i<m;i++)
	{
		txtHash = (txtHash * base + (text[i] - 'a' + 1)) % mod;
		patHash = (patHash * base + (pattern[i]-'a'+1)) % mod;
	}

	for(int i=0;i<=n-m;i++)
	{
		if(txtHash == patHash)
		{
			bool match = true; 
      // hashcode may be same, therefore check again
			for(int j=0;j<m;j++)
			{
				if(text[i+j] != pattern[j])
				{
					match=false;
					break;
				}
			}
			if(match)
			{
				ans.push_back(i+1);
			}
		}

		//roll hash
		if(i < n-m)
		{
			txtHash = (txtHash - (text[i] - 'a' + 1) * power % mod + mod) % mod;  //remove the first element of the window
			txtHash = (txtHash * base + (text[i+m] - 'a' + 1)) % mod; //add the new element in the window

		}
	}
	return ans;
}
