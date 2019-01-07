/* Score 100/100*/
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_N 503
#define INF 10000000000000LL
#define max(A,B) ((A) > (B) ? (A) : (B))
#define min(A,B) ((A) < (B) ? (A) : (B))
typedef long long ll;

int N;
ll dp[MAX_N][MAX_N], L[MAX_N];

inline ll val(ll l) {return (l*311) % 104729;}
inline int len(int a, int b) {return L[b] - (a ? L[a - 1] : 0);}

int main()
{
	while (scanf("%d ", &N) != EOF)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				dp[i][j] = INF;
	
		for (int i = 0; i < N; i++) scanf("%lld ", &L[i]), dp[i][0] = 0;
		for (int i = 1; i < N; i++) L[i] += L[i-1];

		for (int l = 1; l < N; l++)
			for (int i = 0; i < N - l; i++)
				for (int k = 0; k < l; k++)
					dp[i][l] = min(dp[i][l], 
							dp[i][k] + dp[i + k + 1][l - k - 1] + val(len(i,i + l)));

		printf("%lld\n", dp[0][N - 1]);
	}

	return 0;
}
