#include <stdio.h>
#include <stdlib.h>

void main()
{
	int n, k, cnt = 0;
	scanf("%d %d", &n, &k);
	int * value = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &value[i]);
	}
	
	for (int i = n - 1; 0 <= i; --i)
	{
		if (value[i] <= k)
		{
			printf("value[i] : %d 에서 %d를 나눕니다. \n", value[i], k);
			cnt += k / value[i];
			printf("카운트는 %d증가합니다. \n", k / value[i]);
			k = k % value[i];
			printf("현재의 K값 %d. \n", k );
		}

		if (k < 0) break;
	}
	
	printf("%d",cnt);
	return;
}