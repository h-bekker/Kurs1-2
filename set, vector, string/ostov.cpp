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

void ostov(int start) {
	for (int i=1; i<=n; i++)
		dist[i]=1e15+1;
	dist[start]=0;
	for (int i=1; i<=n; i++)
		s.insert(make_pair(dist[i],i));
	while (!s.empty()) {
		long long int min; 
		int minpos;
		it=s.begin();
		min=(*it).first;
		minpos=(*it).second;
		if (min==1e15+1)
			break;
		s.erase(it);
		for (int i=0; i<m[minpos].size(); i++) {
			int to=m[minpos][i];
			it=s.find(make_pair(dist[to],to));
			if ((it!=s.end()) && (dist[to]>w[minpos][i])) {
				dist[to]=w[minpos][i];
				s.erase(it);
				s.insert(make_pair(dist[to],to));
				}
			}
		}
	}

int main() {
	int k,u,v,t;
	cin >> n >> k;
	for (int i=1; i<=k; i++) {
		cin >> u >> v >> t;
		m[u].push_back(v);
		m[v].push_back(u);
		w[u].push_back(t);
		w[v].push_back(t);
		}
	ostov(1);
	int ans=0;
	for (int i=1; i<=n; i++)
		if (dist[i]!=1e15+1)
			ans+=dist[i];
	cout << ans << endl;
	}
