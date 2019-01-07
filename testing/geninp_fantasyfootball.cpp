#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

#define MAX_S 1000
int N,K,R;

int main()
{
	srand(time(NULL));

	while (scanf("%d %d %d ", &N,&K,&R) != EOF)
	{
		printf("%d %d %d\n", N,K,R);
		while (R--)
		{
			for (int i = 0; i < N; i++)
				printf("%d ", rand() % MAX_S);
			printf("\n");
		}
	}

	return 0;
}
