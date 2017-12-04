#include <vector>
#include <iostream>
using namespace std;

int n;
vector <int> m[105];
//vector <int> w[105];
int used[105];
int dist[105];
int a[105];

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
			if (dist[to]>dist[minpos]+a[minpos])
				dist[to]=dist[minpos]+a[minpos];
			}
		}
	}

int main() 
{
	int k,v1,v2;
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	cin >> k;
	for (int i=1; i<=k; i++) {
		cin >> v1 >> v2;
		m[v1].push_back(v2);
		m[v2].push_back(v1);
		}
	dijkstra(1);
	if (dist[n]!=1000000)
		cout << dist[n] << endl;
	else
		cout << -1 << endl;
}
