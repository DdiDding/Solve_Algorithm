#include <iostream>
using namespace std;

int main()
{
	//�Է¹���
	int cardCnt, M;
	cin >> cardCnt >> M;
	int cardNum[110];
	for (int i = 0; i < cardCnt; ++i)
	{
		cin >> cardNum[i];
	}

	//���
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



//��ī���� ���ڴ� ���� ����
//
//n���� ī���߿��� 3���� �� <= M, M�� �ִ��� ������ ������
//
//������ ��:
//1.������ � ī�� �Ѹ��ǰ�
//
//2.M�� ��
//
//3.�� ī���� ��
//
//��°�:
//3���� ��
///////
//���� ������� �����;���