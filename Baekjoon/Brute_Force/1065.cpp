#include <stdio.h>

using namespace std;
//X들어오면  각 자리수를 따로 생각해서 그차이가 일정한 수열일거아니야
//그럼 자리수도 똑같겟네
//
//0)N의 각자리의 차이를 계산해야해
//= > 이 차이를 어떻게 저장할것인가 ?
//
//ex) 123
//1, 1
//배열의 사이즈로 자리수 체크하고
//차이를 담으면 될거같은데 ?
//
//1)자리수만큼 for문 돌리면서 카운팅
//
//2)어떤걸 ? N의 한수인지 아닌지 = > if사용
//
//////
//함수는 배열 생성하는걸로 하자
//벡터 ?
//=>문제를 잘 이해하지 못함 ㅠㅠ

bool IsHansu(int n)
{
	int min100_10;
	int min10_1;

	//100의자리에서 10의자리 빼기
	min100_10 = n / 100 - (n - (n / 100)*100) / 10;
	n = (n - (n / 100) * 100);

	//10의자리에서 1의자리 빼기
	min10_1 = n / 10 - n % 10;
	
	if (min100_10 == min10_1)
		return true;

	return false;
}

int main()
{
	int n = 0;
	scanf("%d", &n);

	int cnt = 0;
	if (n != 0)
	{
		if (n < 100)
			printf("%d", n);

		if (100 <= n)
		{
			for (int i = 100; i <= n; ++i)
			{
				if (IsHansu(i) == true)
					++cnt;
			}
			printf("%d", 99 + cnt);
		}
	}
	else 
	{
		printf("%d", 0);
	}
}


//shot 코딩ㅋㅋㅋ
//int a, b;
//main() 
//{ 
//	for (std::cin >> a;a;a--)
//		a < 100 ? (b++ : a/100 + a%10 - a/10%10*2 ? 0 : b++;std::cout << b;) 
//}


//각 자리수 뽑아내기
//
//1의자리		: n % 10
//10의자리		: n /10 % 10
//100의자리	: n/ 100 % 100
//
//ㄷㄷㄷ