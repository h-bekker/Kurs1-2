#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n;
vector <int> m[10005];
vector <int> w1[10005];
vector <int> w2[10005];
long long int dist[10005];
set <pair<long long int,int> > s;
set <pair<long long int,int> > :: iterator it;
//int parent[10005]; 

void dijkstra(int start) {
	for (int i=1; i<=n; i++)
		dist[i]=1e11+1;
	//parent[start]=0;
	dist[start]=0;
	for (int i=1; i<=n; i++)
		s.insert(make_pair(dist[i],i));
	while (!s.empty()) {
		long long int min; 
		int minpos;
		int posl=0;
		it=s.begin();
		min=(*it).first;
		minpos=(*it).second;
		if (min==1e11+1)
			break;
		s.erase(it);
		for (int i=0; i<m[minpos].size(); i++) {
			int to=m[minpos][i];
			it=s.find(make_pair(dist[to],to));
			if ((it!=s.end()) && (dist[to]>w2[minpos][i]) && (dist[to]>dist[minpos]) && (w1[minpos][i]>=posl)) {
				//parent[to]=minpos;
				dist[to]=w2[minpos][i];
				posl=w1[minpos][i];
				s.erase(it);
				s.insert(make_pair(dist[to],to));
				}
			}
		}
	}

/*void print (int v)
{
	if (v==0)
		return;
	print(parent[v]);
	cout << v << " ";
} */

int main() {
	ios_base::sync_with_stdio(false);
	int s,f,r,d,e,t1,t2;
	cin >> n >> s >> f >> r;
	for (int i=1; i<=r; i++) {
		cin >> d >> t1 >> e >> t2;
		m[d].push_back(e);
		w1[d].push_back(t1);
		w2[d].push_back(t2);
		}
	dijkstra(s);
	if (dist[f]!=1e11+1) 
		cout << dist[f] << endl;
	else
		cout << -1 << endl;	
	}
