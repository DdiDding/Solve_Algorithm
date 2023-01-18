//Alice and Bob
vector<int> compareTriplets(vector<int> a, vector<int> b) {

	vector<int> result(2, 0);
	const int challengesNum = a.size();

	for (int i = 0; i < challengesNum; ++i)
	{
		a.at(i) > b.at(i) ? ++result[0] : a.at(i) == b.at(i) ? : ++result[1];
	}

	return result;
}