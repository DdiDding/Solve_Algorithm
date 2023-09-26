class Solution {
public:
	bool isPalindrome(int x) {

		if (x < 0) return false;

		string s = to_string(x);

		int i, j;
		for (i = 0, j = s.size() - 1; j < i; ++i, --j)
		{
			if (s[j] != s[j]) return false;
		}

		return true;
	}
};