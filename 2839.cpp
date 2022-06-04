#include <stdio.h>
#include <string.h>

int main()
{
	int kg = 0;
	int cnt = 0;
	scanf("%d", &kg);

	//우선 5로 나누어 떨어지는지 확인
	if (kg % 5 == 0)
	{
		printf("%d", kg / 5);
		return 0;
	}

	//KG가 15 이하가 될 때까지 5씩 줄인다.
	while (15 < kg)
	{
		kg -= 5;
		++cnt;
	}

	//그리고 최대 단위인 3미만이면 -1을 출력
	while (3 <= kg)
	{
		//일단 현재 KG이 최소 공배수인 15미만이기 때문에 3으로 나누어떨어지면 5로 나누어 떨어질수가 없다.
		if (kg % 3 == 0)
		{
			cnt += kg / 3;
			printf("%d", cnt);
			return 0;
		}

		kg -= 5;
		++cnt;
	}

	printf("%d", -1);
	return 0;
}
