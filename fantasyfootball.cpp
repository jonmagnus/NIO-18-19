/* Implementer en dp-løsning med bitmask for spillerene som er med på laget
 * og et heltall for hvilken runde man er i. Husk metoden for å iterere over
 * alle delmengder med en gitt kardinalitet.
 * Score 100/100*/
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_N 23
#define MAX_R 53
#define max(A,B) ((A) > (B) ? (A) : (B))
#define lsone(A) (A & -A)

int N, K, R, dp[MAX_R][(1 << 20) + 5], S[MAX_R][MAX_N];

int iter(int r, int m)
{
	if (r >= R) return 0;
	if (dp[r][m] != -1) return dp[r][m];

	int best = iter(r + 1,m);
	for (int i = 0; i < N; i++) if (m & (1 << i))	// Finn en spiller å fjerne
		for (int j = 0; j < N; j++) if (!(m & (1 << j)))	// Finn en spiller å legge til
			best = max(best, iter(r + 1, (m | (1 << j)) & ~(1 << i)));

	for (int i = 0; i < N; i++) if (m & (1 << i))
		best += S[r][i];

	return dp[r][m] = best;
}

int main()
{
	while (scanf("%d %d %d ", &N, &K, &R) != EOF)
	{
		memset(dp,-1,sizeof dp);

		for (int i = 0; i < R; i++)
			for (int j = 0; j < N; j++)
				scanf("%d ", &S[i][j]);

		int best = 0;
		// Iterer gjennom alle set med kardinalitet K
		int m = (1 << K) - 1;
		while (m < (1 << N))
		{
			best = max(best, iter(0,m));
			m = m + lsone(m) + ((m^(m + lsone(m)))/lsone(m) >> 2);
		}
		printf("%d\n", best);
	}

	return 0;
}
