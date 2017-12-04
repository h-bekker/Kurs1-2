#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int used[1005];
int dist[1005];
queue <int> q;
int parent[1005];

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
		int t1=from+3, t2=from*4;
		if (t1<=1000) {
			if (used[t1]==0) {
				parent[t1]=from;
				dist[t1]=dist[from]+1;
				used[t1]=1;
				q.push(t1);
				}
			}
		if (t2<=1000) {
			if (used[t2]==0) {
				parent[t2]=from;
				dist[t2]=dist[from]+1;
				used[t2]=1;
				q.push(t2);
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
	int n,m;
	cin >> n >> m;	
	bfs(n);
	if (dist[m] == 0) {
		if (n!=m)
			cout << -1 << endl;
		else
			cout << 0 <<endl;
		}
	else
		cout << dist[m] << endl;
}	 
