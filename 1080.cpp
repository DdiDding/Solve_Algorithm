#include<stdio.h>
using namespace std;
typedef char integer;
static const int MAX_SIZE = 50;

int main()
{
	int i, j;
	integer N, M;
	scanf("%hu %hu", &N, &M);

	//사이즈확인하기
	if (N < 3 || M < 3)
	{
		printf("-1");
		return 0;
	}

	unsigned short result = 0;
	integer a[MAX_SIZE];
	integer b[MAX_SIZE];

	
	integer size = N * M;
	for (i = 0; i < size; ++i)
	{
		scanf(" %c", &a[i]);
		a[i] -= 48;
	}
	for (i = 0; i < size; ++i)
	{
		scanf(" %c", &b[i]);
		b[i] -= 48;
	}
	

	for (i = 0; i <= N - 3; ++i)	
	{
		for (j = 0; j <= M - 3; ++j)
		{
			if (a[j] != b[i])
			{
				a[j] = !a[j]; a[j + 1] = !a[j + 1]; a[j + 2] = !a[j + 2];
				a[j + 4] = !a[j + 4]; a[j + 4 + 1] = !a[j + 4 + 1]; a[j + 4 + 2] = !a[j + 4 + 2];
				a[j + 8] = !a[j + 8]; a[j + 8 + 1] = !a[j + 8 + 1]; a[j + 8 + 2] = !a[j + 8 + 2];
			}
			++result;
		}

		if (a[M - 2] != b[M - 2] || a[M - 1] != b[M - 1])
		{
			result = -1;
			break;
		}
	}

	printf("%hu", &result);
	return 0;
}