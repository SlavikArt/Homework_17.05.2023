#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(std::string a, std::string b);

class Comparer
{
public:
	bool operator()(std::string a, std::string b)
	{
		return a.length() < b.length();
	}
};

class Adder
{
	int number;
public:
	Adder(int number) : number(number) {}
	void operator()(int& elem)
	{
		elem += number;
	}
};

class Equals
{
	int number;
public:
	Equals(int number) : number(number) {}
	bool operator()(int& elem)
	{
		return elem == number;
	}
};

int main()
{
	srand(time(0));

	std::cout << "Task 1:\n\n";

    std::vector<std::string> vec;

	for (int i = 0; i < 20; i++)
	{
		std::string tmp = "";

		int randLenght = rand() % 50 + 3;
		for (int j = 0; j < randLenght; j++)
		{
			tmp += (char)(rand() % 26 + 65);
		}
		vec.push_back(tmp);
	}

	std::cout << "Before sorting:\n";

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << "\n";
	}
	std::cout << "\nAfter sorting:\n";

	std::sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << "\n";
	}

	std::cout << "\nTask 2:\n\n";

	std::vector<std::string> vec2;

	for (int i = 0; i < 20; i++)
	{
		std::string tmp = "";

		int randLenght = rand() % 50 + 3;
		for (int j = 0; j < randLenght; j++)
		{
			tmp += (char)(rand() % 26 + 65);
		}
		vec2.push_back(tmp);
	}

	std::cout << "Before sorting:\n";

	for (int i = 0; i < vec2.size(); i++)
	{
		std::cout << vec2[i] << "\n";
	}
	std::cout << "\nAfter sorting:\n";

	Comparer comparer;

	std::sort(vec2.begin(), vec2.end(), comparer);

	for (int i = 0; i < vec2.size(); i++)
	{
		std::cout << vec2[i] << "\n";
	}

	std::cout << "\nTask 3:\n\n";

	std::vector<int> vec3;

	for (int i = 0; i < 20; i++)
		vec3.push_back(rand() % 20 + 10);

	std::cout << "Before:\n";

	for (auto& elem : vec3)
		std::cout << elem << ", ";

	Adder adder(5);

	std::for_each(vec3.begin(), vec3.end(), adder);

	std::cout << "\n\nAfter (adding 5):\n";

	for (auto& elem : vec3)
		std::cout << elem << ", ";
	std::cout << "\n";

	std::cout << "\nTask 4:\n\n";

	std::vector<int> vec4;

	for (int i = 0; i < 20; i++)
		vec4.push_back(rand() % 5);

	std::cout << "Before:\n";

	for (auto& elem : vec4)
		std::cout << elem << ", ";

	int num = rand() % 5;

	Equals equals(num);

	vec4.erase(std::remove_if(vec4.begin(), vec4.end(), equals), vec4.end());

	std::cout << "\n\nAfter (deleting all " << num << "):\n";

	for (auto& elem : vec4)
		std::cout << elem << ", ";
	std::cout << "\n";
}

bool cmp(std::string a, std::string b)
{
	return a.length() < b.length();
}
