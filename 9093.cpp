#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#define INIT_STACK_SIZE 1001

using namespace std;

template<typename T>
class Stack
{
public:

	Stack()
	{
		data = new T[INIT_STACK_SIZE];
		capacity = INIT_STACK_SIZE;
		topIndex = -1;
	}
	~Stack()
	{
		delete[] data;
		data = nullptr;
	}

	void Push(T input)
	{
		++topIndex;
		if (capacity <= topIndex)
		{
			T * temp = new T[capacity * 2];
			memcpy(temp, data, capacity);
			delete[] data;
			data = temp;
		}
		data[topIndex] = input;
	}

	T Pop()
	{
		if (IsEmpty() == true) return NULL;
		--topIndex;
		return data[topIndex + 1];
	}

	bool IsEmpty()
	{
		return topIndex == -1;
	}

	T Top()
	{
		if (IsEmpty() == true) return -1;
		return data[topIndex];
	}

	int Size()
	{
		return topIndex + 1;
	}

	void Print(const bool & isReverse)
	{
		if (isReverse == false)
		{
			for (int i = 0; i <= topIndex; ++i)
			{
				cout << data[i] << "||";
			}
		}
		else
		{
			while (IsEmpty() == false)
			{
				cout << Pop();
			}
		}
	}



private:
	T * data;
	int topIndex;
	int capacity;
};

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#define INIT_STACK_SIZE 1001

using namespace std;

template<typename T>
class Stack
{
public:

	Stack()
	{
		data = new T[INIT_STACK_SIZE];
		capacity = INIT_STACK_SIZE;
		topIndex = -1;
	}
	~Stack()
	{
		delete[] data;
		data = nullptr;
	}

	void Push(T input)
	{
		++topIndex;
		if (capacity <= topIndex)
		{
			T * temp = new T[capacity * 2];
			memcpy(temp, data, capacity);
			delete[] data;
			data = temp;
		}
		data[topIndex] = input;
	}

	T Pop()
	{
		if (IsEmpty() == true) return -1;
		--topIndex;
		return data[topIndex + 1];
	}

	bool IsEmpty()
	{
		return topIndex == -1;
	}

	T Top()
	{
		if (IsEmpty() == true) return -1;
		return data[topIndex];
	}

	int Size()
	{
		return topIndex + 1;
	}

	void Print(const bool & isReverse)
	{
		if (isReverse == false)
		{
			for (int i = 0; i <= topIndex; ++i)
			{
				cout << data[i] << " ";
			}
			cout << '\n';
		}
		else
		{
			while (IsEmpty() == false)
			{
				cout << Pop();
			}
		}
	}



private:
	T * data;
	int topIndex;
	int capacity;
};

int main()
{
	int N;
	scanf("%d ",&N);

	Stack<char> stack;
	vector<char> result;
	result.reserve(INIT_STACK_SIZE);

	char temp;

	for (int i = 0; i < N; )
	{
		temp = getchar();

		if (temp == '\n')
		{
			while (stack.IsEmpty() == false)
			{
				result.push_back(stack.Pop());
			}
			result.push_back('\n');
			++i;
		}
		else if (temp == ' ')
		{
			while (stack.IsEmpty() == false)
			{
				result.push_back(stack.Pop());
			}
			result.push_back(' ');
		}
		else
		{
			stack.Push(temp);
		}
	}

	for (const auto & data : result)
	{
		cout << data;
	}
}