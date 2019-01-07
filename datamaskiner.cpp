/* Vanldig dfs-søk som returnerer antall noder den har utforsket.
 * Score 77/100
 * Wrong answer*/
#include <cstdio>
#include <string>
#include <map>
#include <vector>
using namespace std;

typedef vector<string> vs;
typedef vector<vs> vvs;

int N;
map<string,bool> vis;
map<string,vs> adj_list;

int dfs(string u)
{
	//printf("dfs(%s)\n", u.c_str());
	vis[u] = 1;
	int sum = 1;
	vs &neigh = adj_list[u];
	for (int i = 0; i < (int)neigh.size(); i++)
	{
		string v = neigh[i];
		if (vis[v]) continue;
		sum += dfs(v);
	}
	return sum;
}

int main()
{
	while (scanf("%d ", &N) != EOF)
	{
		while (N--)
		{
			int A;
			char name[15];
			scanf("%s %d ", name, &A);
			string u(name);
			vs &neigh = adj_list[u] = vs();
			vis[u] = 0;
			
			while (A--)
			{
				scanf("%s ", name);
				neigh.push_back(string(name));
			}
		}

		int ans = dfs("datamaskiner");
		printf("%d\n", ans);
	}

	return 0;
}
