//Given a square matrix,
//정방행렬을 준답니다.

//calculate the absolute difference between the sums of its diagonals.
//대각선의 합의 사이의 절대적인 차이를 계산해라

//The first line contains a single integer,n, the number of rows and columns in the square matrix .
//Input의 첫 째줄에는 하나의 int가 들어갑니다. = n, 이 숫자는 행렬의 각 행, 열 의 크기를 의미합니다.

//Each of the next  lines describes a row,arr[i] , and consists of  space - separated integers arr[i][j].
//그 다음으로 오는 각 줄은 행을 뜻하고,arr[i], 공백으로 구분된 정수로 나누어져있습니다.

//Output Format
//Return the absolute difference between the sums of the matrix's two diagonals as a single integer
//행렬의 두 대각선 합 사이의 절대적인 차를 단일 정수로 반환합니다

int diagonalDifference(vector<vector<int>> arr) {

	int maxCnt = arr.size() - 1;
	printf("Cnt : %d", maxCnt);
	int sum_LtoR = 0, sum_RtoL = 0;

	for (int i = 0; i <= maxCnt; ++i)
	{
		sum_LtoR += arr[i][i];
		printf("LtoR : [%d][%d]\n", i, i);
		sum_RtoL += arr[i][maxCnt - i];
		printf("RtoL : [%d][%d]\n", i, maxCnt - i);
	}
	printf("LtoR : %d", sum_LtoR);
	printf("RtoL : %d", sum_RtoL);

	return abs(sum_LtoR - sum_RtoL);;
}