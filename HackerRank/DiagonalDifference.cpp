//Given a square matrix,
//��������� �ش�ϴ�.

//calculate the absolute difference between the sums of its diagonals.
//�밢���� ���� ������ �������� ���̸� ����ض�

//The first line contains a single integer,n, the number of rows and columns in the square matrix .
//Input�� ù °�ٿ��� �ϳ��� int�� ���ϴ�. = n, �� ���ڴ� ����� �� ��, �� �� ũ�⸦ �ǹ��մϴ�.

//Each of the next  lines describes a row,arr[i] , and consists of  space - separated integers arr[i][j].
//�� �������� ���� �� ���� ���� ���ϰ�,arr[i], �������� ���е� ������ ���������ֽ��ϴ�.

//Output Format
//Return the absolute difference between the sums of the matrix's two diagonals as a single integer
//����� �� �밢�� �� ������ �������� ���� ���� ������ ��ȯ�մϴ�

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