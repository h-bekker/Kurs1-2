#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n;
vector <int> m[10005];
vector <int> w[10005];
int dist[10005],gor[10005];
set <pair<int,int> > s;
set <pair<int,int> > ros;
set <pair<int,int> > :: iterator it;

void dijkstra(int start) {
	for (int i=1; i<=n; i++)
		dist[i]=1e6+1;
	dist[start]=0;
	for (int i=1; i<=n; i++)
		s.insert(make_pair(dist[i],i));
	while (!s.empty()) {
		long long int min; 
		int minpos;
		it=s.begin();
		min=(*it).first;
		minpos=(*it).second;
		if (min==1e6+1)
			break;
		s.erase(it);
		for (int i=0; i<m[minpos].size(); i++) {
			int to=m[minpos][i];
			it=s.find(make_pair(dist[to],to));
			if ((it!=s.end()) && (dist[to]>dist[minpos]+w[minpos][i])) {
				dist[to]=dist[minpos]+w[minpos][i];
				s.erase(it);
				s.insert(make_pair(dist[to],to));
				}
			}
		}
	}

int main() {
	int k,d,c,u,v,t;
	cin >> n >> d >> k >> c;
	for (int i=1; i<=k; i++)
		cin >> gor[i];
	for (int i=1; i<=d; i++) {
		cin >> u >> v >> t;
		m[u].push_back(v);
		m[v].push_back(u);
		w[u].push_back(t);
		w[v].push_back(t);
		}
	dijkstra(c);
	for (int i=1; i<=k; i++)
		ros.insert(make_pair(dist[gor[i]],gor[i]));
	while (!ros.empty()) {
		it=ros.begin();
		cout << (*it).second << " " << (*it).first << endl;
		ros.erase(it);
		}
	}
