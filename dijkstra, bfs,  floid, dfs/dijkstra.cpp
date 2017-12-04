#include <vector>
#include <iostream>
using namespace std;

int n;
vector <int> m[105];
vector <int> w[105];
int used[105];
int dist[105];

void dijkstra(int start) {
	for (int i=1; i<=n; i++)
		dist[i]=1000000;
	dist[start]=0;
	for ( ; ; ) {
		int min=1000000, minpos=0;
		for (int i=1; i<=n; i++)
			if (used[i]==0 && dist[i]<min) {
				min=dist[i];
				minpos=i;
			}
		if (minpos == 0)
			break;
		used[minpos]=1;
		for (int i=0; i<m[minpos].size(); i++) {
			int to=m[minpos][i];
			if (dist[to]>dist[minpos]+w[minpos][i])
				dist[to]=dist[minpos]+w[minpos][i];
			}
		}
	}

int main() {
	int s,f,t;
	cin >> n >> s >> f;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		{	
			cin >> t;
			if (t>0) {
				m[i].push_back(j);
				w[i].push_back(t);
			}
		}
	dijkstra(s);
	/*for (int i=1; i<=n; i++)
	{	
		cout << i << ": ";
		for (int j=0; j<m[i].size(); j++)
			cout << m[i][j] << " ";
		cout << endl;
	} 
	for (int i=1; i<=n; i++)
	{	
		cout << i << ": ";
		for (int j=0; j<w[i].size(); j++)
			cout << w[i][j] << " ";
		cout << endl;
	} */
	if (dist[f]!=1000000)
		cout << dist[f] << endl;
	else 
		cout << -1 << endl;
	}
	
