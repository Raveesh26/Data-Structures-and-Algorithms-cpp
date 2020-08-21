vector<int> g[N];
vector<int> order; //Stores the Topological Order
 
bool toposort(int n) //Returns 1 if there exists a toposort, 0 if there is a cycle
{	
	order.clear();
	queue<int> q;
	vector<int> indeg(n + 1, 0);
	for(int i = 1; i <= n; i++)
		for(auto &it:g[i])
			indeg[it]++;
	for(int i = 1; i <= n; i++)
	{
		if(!indeg[i])
			q.push(i);
	}
	int idx = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		order.push_back(u);
		idx++;
		pos[u] = idx;
		for(auto &v:g[u])
		{
			indeg[v]--;
			if(!indeg[v])
				q.push(v);
		}
	}
	return (order.size() == n);
}
 
 
//Call this func in for loop of n size 
void topo_sort(int i, stack <int> &s, int *visited)  //Stack s will store topological order
{
	int j, x;
	visited[i] = 1;
	for(j = 0; j < v[i].size(); j++)
	{
		x = v[i][j];
		if(visited[x] == 0)
			topo_sort(x, s, visited);
	}
	s.push(i);
} 
 
