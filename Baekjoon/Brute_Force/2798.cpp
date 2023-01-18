#include <iostream>
using namespace std;

int main()
{
	//입력받음
	int cardCnt, M;
	cin >> cardCnt >> M;
	int cardNum[110];
	for (int i = 0; i < cardCnt; ++i)
	{
		cin >> cardNum[i];
	}

	//계산
	int tempMax = 0;
	int result = 0;
	int stack[2] = { 0 };
	for (int i = 0; i < cardCnt; ++i)
	{
		for (int j = 0; j < cardCnt - 1; ++j)
		{
			if (j != i)
			{
				for (int k = 0; k < cardCnt - 2; ++k)
				{
					if (j != k && i != k)
					{
						tempMax = cardNum[k] + cardNum[j] + cardNum[i];
						if (result < tempMax && tempMax <= M)
							result = tempMax;
					}
				}//3rd card
			}
		}//2nd card
	}//1th card
	printf("%d", result);
}



//※카드의 숫자는 양의 정수
//
//n장의 카드중에서 3장의 합 <= M, M과 최대한 가깝게 만들어라
//
//들어오는 값:
//1.딜러가 몇개 카드 뿌릴건가
//
//2.M의 값
//
//3.각 카드의 값
//
//출력값:
//3장의 합
///////
//먼저 값을모두 가져와야해