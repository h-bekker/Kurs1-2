#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> v[100005];
int used[100005];
int dist[100005];
queue <int> q;
int parent[100005];

void bfs(int start)
{
	parent[start]=0;
	dist[start]=0;
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
				parent[to]=from;
				dist[to]=dist[from]+1;
				used[to]=1;
				q.push(to);
			}
		}
	}
}

void print (int v)
{
	if (v==0)
		return;
	print(parent[v]);
	cout << v << " ";
}

int main()
{
	int n,k,m,i,j,s,t;
	cin >> n;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		{	
			cin >> t;
			if (t==1)
				v[i].push_back(j);
		}	
	cin >> m >> k;
	bfs(m);
	if (dist[k] == 0) {
		if (m != k)
			cout << -1 << endl;
		else
			cout << 0 << endl;
		}
	else {
		cout << dist[k] << endl;
		print(k);
		cout << endl;
	}
}	 
