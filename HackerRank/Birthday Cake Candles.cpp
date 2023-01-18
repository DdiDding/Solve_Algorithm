//You are in charge of the cake for a child's birthday.
//����� ������ ���Ͽ� ����ũ�� ����߽��ϴ�.

//You have decided the cake will have one candle for each year of their total age.
//����� �� ������ �� �ظ��� �ϳ��� �ʸ� ���Ϳ� �ֱ�� �����߽��ϴ�. 

//They will only be able to blow out the tallest of the candles. 
//�׵��� ����ū �ʸ� �Ҽ��ֽ��ϴ�.

//Count how many candles are tallest.
//���� ū �ʵ��� �󸶳� ������ ī��Ʈ�ϼ���

//Returns
//int: the number of candles that are tallest
//���� ���� �к��� ����


//Input Format
//The first line contains a single integer, n , the size of candles.
//The second line contains  space - separated integers, where each integer i describes the height of  candles[i].
//ù��° ������ ���� int�� ����ִ�. = n, �̴� ĵ���� �����̴�.
//�ι�° ���ο��� �������� ���е� ������ ����ִ�, �� i��° int��  candles[i]�� ���̸� ��Ÿ���ϴ�.


int birthdayCakeCandles(vector<int> candles) {

	int maximum = 0;
	int cnt = 0;

	for (const auto & data : candles)
	{
		if (maximum < data)
		{
			maximum = data;
			cnt = 1;
		}
		else if (maximum == data)
		{
			++cnt;
		}
	}

	return cnt;
}
