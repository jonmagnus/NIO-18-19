#include <cstdio>
using namespace std;

#define MAX_N 21
#define MAX_R 51

int N,K,R,S[MAX_R][MAX_N];

int main()
{
	while (scanf("%d %d %d ", &N,&K,&R) != EOF)
	{
		//printf("N=%2d K=%2d R=%2d\n", N,K,R);
		if (N > K + 1) 
		{
			printf("0\n");
			for (int i = 0; i < N*R; i++) scanf("%*d ");
			continue;
		}

		if (N == K)
		{
			int sum = 0, a;
			for (int i = 0; i < R*N; i++)
				scanf("%d ", &a), sum += a;

			printf("%d\n", sum);
		}
		else
		{
			int sum = 0;
			while (R--)
			{
				int a, min_val = 1005;
				for (int i = 0; i < N; i++)
				{
					scanf("%d ", &a);
					sum += a;
					min_val = a < min_val ? a : min_val;
				}
				sum -= min_val;
			}

			printf("%d\n", sum);
		}
	}
	return 0;
}
