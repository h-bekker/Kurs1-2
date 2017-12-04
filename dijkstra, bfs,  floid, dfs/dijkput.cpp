#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n;
vector <int> m[105];
vector <int> w[105];
long long int dist[105];
set <pair<long long int,int> > s;
set <pair<long long int,int> > :: iterator it;
int parent[105];

void dijkstra(int start) {
	for (int i=1; i<=n; i++)
		dist[i]=1e11+1;
	dist[start]=0;
	parent[start]=0;
	for (int i=1; i<=n; i++)
		s.insert(make_pair(dist[i],i));
	while (!s.empty()) {
		long long int min; 
		int minpos;
		it=s.begin();
		min=(*it).first;
		minpos=(*it).second;
		if (min==1e11+1)
			break;
		s.erase(it);
		for (int i=0; i<m[minpos].size(); i++) {
			int to=m[minpos][i];
			it=s.find(make_pair(dist[to],to));
			if ((it!=s.end()) && (dist[to]>dist[minpos]+w[minpos][i])) {
				parent[to]=minpos;
				dist[to]=dist[minpos]+w[minpos][i];
				s.erase(it);
				s.insert(make_pair(dist[to],to));
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

int main() {
	ios_base::sync_with_stdio(false);
	int s,f,u,v,t,i,j;
	cin >> n >> s >> f;
	for (i=1; i<=n; i++) {
		for (j=1; j<=n; j++)
		cin >> t;
		if (i!=j && t!=-1)
		m[i].push_back(j);
		w[i].push_back(t);
		}
	ffe
	dijkstra(s);
	print(f);	
	cout << endl;
	}
