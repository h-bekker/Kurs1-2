#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> v[100005];
int used[100005];
int dist[100005];
queue <int> q;
int a[100005];

void bfs(int start)
{
	//parent[start]=0;
	dist[start]=-1;
	used[start]=1;
	q.push(start);
	//cout << start;
	while (!q.empty()) 
	{
		int from=q.front();
		q.pop();
		//cout << from << endl;
		for (int i=0; i<v[from].size(); i++)
		{
			int to=v[from][i];
			if (used[to]==0) 
			{
				//parent[to]=from;
				dist[to]=dist[from]+1;
				used[to]=1;
				q.push(to);
			}
		}
	}
}

int main()
{
	int n,k,m,i,j,s,t;
	cin >> n >> k;
	for (int i=1; i<=k; i++)
		cin >> a[i];
	cin >> m;
	//for (int i=1; i<=n; i++)
	//	v[i].push_back(0);
	for (int i=1; i<=m; i++)
	{	
		cin >> s >> t;
	//	v[s][0]++;
	//	v[t][0]++;
		v[t].push_back(s);
		v[s].push_back(t);
	}	
	//v[n+1].push_back(k);
	for (int i=1; i<=k; i++)
		v[n+1].push_back(a[i]);	
	bfs(n+1);
	for (int i=1; i<=n; i++)
		cout << dist[i] << " ";
	cout << endl;
}	 
