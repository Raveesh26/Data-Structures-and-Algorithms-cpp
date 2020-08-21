#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007 
#define pb push_back  
 
ll power(ll x, ll y)
{  
    ll res = 1;     // Initialize result 
    
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1)
            res = (res*x)%mod;
        // y must be even now 
        y = y/2; // y = y/2 
        x = (x*x)%mod;
    } 
    return res; 
}  

int BL[100005][20], depth[100005];

void binary_lifting(int x, int p, vector <int> v[], int d)
{
	int i, j;
	depth[x] = d;
	BL[x][0] = p;
	for(i = 1; i < 19; i++)
	{
		BL[x][i] = BL[BL[x][i-1]][i-1];
	}
	for(j = 0; j < v[x].size(); j++)
	{
		if(v[x][j]!=p)
			binary_lifting(v[x][j], x, v, d + 1);
	}
}

int parent(int i, int p)
{
	int x = 0;
	while(p)
	{
		if(p&1)
			i = BL[i][x];
		p = p>>1;
		x++;
	}
	return i;
}

int LCA(int a, int b)
{
	int ans = 0, i, j;	
	if(depth[a] > depth[b])
	{
		a = parent(a, depth[a] - depth[b]);
	}
	else if(depth[a] < depth[b])
	{
		b = parent(b, depth[b] - depth[a]);
	}
	if(a==b)
		return a;	
	for(i = 19; i>=0; i--)
	{
		if(BL[a][i]!=BL[b][i])
		{
			a = BL[a][i];
			b = BL[b][i];
		}
	}
	return BL[a][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, i, j, x, y, a, b, k, q, var;
	cin>>n;
	vector <int> v[n + 5];
	for(i = 0; i < n - 1; i++)
	{
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}	
	for(i = 0; i < 20; i++)
		BL[0][i] = 0;
	binary_lifting(1, 0, v, 0);	
    return 0;   
}
