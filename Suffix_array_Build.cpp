#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
#define pb push_back  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin>>s;
    int i, j, n, k, x, chk;
    n = s.length();

    pair <int, int> p[n + 5];
    int rev_p[n + 5];
    for(i = 0; i < n; i++)
    	p[i] = make_pair(s[i], i);
	sort(p, p + n);
	
	// p.first contains the integers (equivalence classes) and p.second contains the order of indexes, 
	// i.e it will be storing the final answer
	
	// rev_p stores the value of integer (equivalence class) corresponding to each index 
	//(Considering it as starting index of suffix)
	
	x = 0;
	//Assigning string to integer (Equivalence class)
	for(i = 0; i < n; x++)
	{
		chk = p[i].first;
		for(j = i; j < n && chk == p[j].first; j++)
		{
			p[j].first = x;
			rev_p[p[j].second] = x;
		}
		i = j;
	}
	
	pair <pair <int, int>, int> temp[n + 5];
	
	//temp stores pair of integers which is mapping to string of length k along with its index
	
	for(k = 1; k < n; k*=2)
	{
		for(i = 0; i < n; i++)
		{
			if(i + k < n)
				temp[i] = {{rev_p[i], rev_p[i + k]}, i};
			else 
				temp[i] = {{rev_p[i], -1}, i};	
		}
		sort(temp, temp + n);
		
		x = 0;
		
		// Again making p with help of temp
		// Now p.first is redundant and not required
		
		for(i = 0; i < n; x++)
		{
			for(j = i; j < n; j++)
			{
				if(temp[j].first == temp[i].first)
				{
				//	p[j].first = x;
					p[j].second = temp[j].second;
					rev_p[p[j].second] = x;
				}
				else 
					break;
			}
			i = j;
		}
	}
	
//	cout<<n<<" ";
	
	//Print the strings only for clarity on small inputs
	for(i = 0; i < n; i++)
		cout<<p[i].second<<" "<<s.substr(p[i].second)<<"\n";
    return 0;   
}



 
