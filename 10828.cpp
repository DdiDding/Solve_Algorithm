#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#define INIT_STACK_SIZE 10'001

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
	void Print()
	{
		for (int i = 0; i <= topIndex; ++i)
		{
			cout << data[i] << " ";
		}
		cout << '\n';
	}

private:
	T * data;
	int topIndex;
	int capacity;
};

int main()
{
	Stack<int> stack;

	int N;
	cin >> N;

	vector<int> result;
	result.reserve(INIT_STACK_SIZE);

	string command;
	int temp = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> command;
		if (command == "push")
		{
			cin >> temp;
			stack.Push(temp);
		}
		else if (command == "top")
		{
			result.push_back(stack.Top());
		}
		else if (command == "pop")
		{
			result.push_back(stack.Pop());
		}
		else if (command == "size")
		{
			result.push_back(stack.Size());
		}
		else if (command == "empty")
		{
			result.push_back(stack.IsEmpty());
		}
	}

	for (const auto & data : result)
	{
		cout << data<<"\n";
	}
}