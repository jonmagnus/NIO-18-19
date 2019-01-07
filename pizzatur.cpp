/* Gå nedover listen og regn ut manhatten-avstanden mellom punktene. Legg
 * så til 15*N.
 * Score 100/100*/
#include <cstdio>
using namespace std;

#define MAX_N 100005
#define abs(A) ((A) < 0 ? -(A) : (A))
typedef long long ll;

int N,x[MAX_N],y[MAX_N];

int main()
{
	while (scanf("%d ", &N) != EOF)
	{
		ll sum = 15*N;
		for (int i = 0; i < N; i++)
		{
			scanf("%d %d ", &x[i], &y[i]);
			sum += (i ? abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]) : 0);
		}

		printf("%lld\n", sum);
	}

	return 0;
}
