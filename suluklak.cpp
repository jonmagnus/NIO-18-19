/* Implementer DF-UnionFind og test hele tiden for om veiene kommer til 
 * å forårsake at 0 og 1 havner i samme set.
 * Score 100/100*/
#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;

class UnionFind
{
private:
	vi p, rank;
public:
	UnionFind(int n)
	{
		p = vi(n), rank = vi(n,0);
		for (int i = 0; i < n; i++) p[i] = i;
	}
	int get_p(int u) {return p[u] == u ? u : p[u] = get_p(p[u]);}
	bool is_same_set(int u, int v) {return get_p(u) == get_p(v);}
	void unite_set(int u, int v)
	{
		if (is_same_set(u,v)) return;
		u = get_p(u), v = get_p(v);
		if (rank[u] > rank[v]) p[v] = u;
		else
		{
			p[u] = v;
			if (rank[u] == rank[v]) rank[v]++;
		}
	}
};

int N,M;

int main()
{
	while (scanf("%d %d ", &N,&M) != EOF)
	{
		UnionFind UF(N);
		while (M--)
		{
			int u,v;
			scanf("%d %d ", &u,&v);
			if ((UF.get_p(0) == UF.get_p(u) && UF.get_p(1) == UF.get_p(v)) ||
					(UF.get_p(0) == UF.get_p(v) && UF.get_p(1) == UF.get_p(u)))
				printf("nei\n");
			else
			{
				printf("ja\n");
				UF.unite_set(u,v);
			}
		}
	}

	return 0;
}
