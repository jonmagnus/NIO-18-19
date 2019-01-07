#include <cstdio>
#include <cstring>
using namespace std;

int dp[20][1 << 20];

int main_()
{
	memset(dp,-1,sizeof dp);
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < (1 << 20); j++) if (dp[i][j] != -1)
			printf("%2d %7d\n", i,j), i = 20, j = (1 << 20);

	return 0;
}

int main()
{
	printf("pre test\n");
	memset((char *)0x0, 1, 100);
	printf("post test\n");

	return 0;
}
