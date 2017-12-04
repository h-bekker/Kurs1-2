#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n;
vector <int> m[100005];
vector <int> w[100005];
long long int dist[100005];
set <pair<long long int,int> > s;
set <pair<long long int,int> > :: iterator it;
int parent[100005]; 

void dijkstra(int start) {
	for (int i=1; i<=n; i++)
		dist[i]=1e11+1;
	parent[start]=0;
	dist[start]=0;
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
	int k,s,f,t;
	cin >> n >> s >> f;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) {
			cin >> t;
			if (t>0) {
				m[i].push_back(j);
				w[i].push_back(t);
				}
			}
	dijkstra(s);
	if (dist[f]!=1e11+1) {
		print(f);
		cout << endl;
		}
	else
		cout << -1 << endl;	
	}
