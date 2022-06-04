#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int intcmp(const void *a, const void *b)
{
	//b < a = 1 // a < b = -1 // a == b = 0
	return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int *)b ? -1 : 0);
}

void main()
{
	int people = 0;
	scanf("%d", &people);
	int result = 0;
	int * time = (int*)malloc(sizeof(int) * people);
	for (int i = 0; i < people; ++i)
	{
		scanf("%d", &time[i]);
	}

	qsort(time, people, sizeof(int), intcmp);

	result = time[0];
	for (int i = 1; i < people; ++i)
	{
		time[i] += time[i - 1];
		result += time[i];
	}

	printf("%d", result);
	return;
}