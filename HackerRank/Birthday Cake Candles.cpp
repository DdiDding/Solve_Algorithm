//You are in charge of the cake for a child's birthday.
//당신은 아이의 생일에 케이크를 담당했습니다.

//You have decided the cake will have one candle for each year of their total age.
//당신은 총 나이의 각 해마다 하나의 초를 케익에 넣기로 결정했습니다. 

//They will only be able to blow out the tallest of the candles. 
//그들은 가장큰 초를 불수있습니다.

//Count how many candles are tallest.
//가장 큰 초들이 얼마나 많은지 카운트하세요

//Returns
//int: the number of candles that are tallest
//가장 높은 촛불의 개수


//Input Format
//The first line contains a single integer, n , the size of candles.
//The second line contains  space - separated integers, where each integer i describes the height of  candles[i].
//첫번째 라인의 단일 int가 들어있다. = n, 이는 캔들의 개수이다.
//두번째 라인에는 공백으로 구분된 정수가 들어있다, 각 i번째 int는  candles[i]의 높이를 나타냅니다.


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
