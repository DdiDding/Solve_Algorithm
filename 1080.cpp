#include<stdio.h>
typedef unsigned char uc;
typedef unsigned short us;
static const int MAX_SIZE = 2501;

int main()
{
	int i, j, k;
	us N, M;
	scanf("%hu %hu", &N, &M);
	short size = N * M;

	int result = 0;
	uc a[MAX_SIZE];
	uc b[MAX_SIZE];


	for (i = 0; i < size; ++i)
	{
		scanf("%1d", &a[i]);
		/*scanf(" %c", &a[i]);
		a[i] -= 48;*/
	}
	for (i = 0; i < size; ++i)
	{
		scanf("%1d", &b[i]);
		/*scanf(" %c", &b[i]);
		b[i] -= 48;*/
	}
	

	if (N < 3 || M < 3)
	{
		for (i = 0; i < size; ++i)
		{
			if (a[i] != b[i])
			{
				printf("-1");
				return 0;
			}
		}
		printf("0");
		return 0;
	}


	for (i = 0; i <= N - 3; ++i)	
	{
		for (j = M * i; j <= M * (i + 1) - 3; ++j)
		{
			if (a[j] != b[j])
			{
				a[j + (M * 0)] = !a[j + (M * 0)]; a[j + (M * 0) + 1] = !a[j + (M * 0) + 1]; a[j + (M * 0) + 2] = !a[j + (M * 0) + 2];
				a[j + (M * 1)] = !a[j + (M * 1)]; a[j + (M * 1) + 1] = !a[j + (M * 1) + 1]; a[j + (M * 1) + 2] = !a[j + (M * 1) + 2];
				a[j + (M * 2)] = !a[j + (M * 2)]; a[j + (M * 2) + 1] = !a[j + (M * 2) + 1]; a[j + (M * 2) + 2] = !a[j + (M * 2) + 2];
				++result;
			}
		}

		if (a[M - 2] != b[M - 2] || a[M - 1] != b[M - 1])
		{
			result = -1;
			break;
		}
	}

	for (i = size - 1; size - (M * 2) < i; --i)
	{
		if (a[i] != b[i])
		{
			result = -1;
			break;
		}
	}

	printf("%d", result);
	return 0;
}