/*
 * Complete the 'staircase' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void staircase(int n) {

	for (int i = n - 1; 0 <= i; --i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i <= j)cout << '#';
			else cout << ' ';
		}
		cout << endl;
	}
}
