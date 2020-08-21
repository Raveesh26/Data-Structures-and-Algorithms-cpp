void z_func(string s, ll *arr)    //arr initialised with 0
{
	ll n = s.length(), i, j, k, l, r;
	l = r = 0;
	for(i = 1; i < n; i++)
	{
		if(i >= r)
		{
			for(j = 0, k = i; k < n; j++, k++)
			{
				if(s[j] != s[k])
					break;
				arr[i]++;
			}
			l = i;
			r = i + arr[i] - 1;
		}
		else
		{
			arr[i] = min(arr[i - l], r - i + 1);
			for(j = arr[i], k = i + arr[i]; k < n; j++, k++)
			{
				if(s[j] != s[k])
					break;
				arr[i]++;
			}
			if(i + arr[i] - 1 > r)
			{
				l = i;
				r = i + arr[i] - 1;
			}
		}
	}
}
