#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


class JakesCodeChallengeOne{
public:
		void FizzBuzz() {
		int i;
		for (i = 0; i <= 100; i++) {
			if (i % 5 == 0 && i % 3 == 0)
				printf("%s", "FizzBuzz\n");
			else if (i % 5 == 0)
				printf("%s", "Buzz\n");
			else if (i % 3 == 0)
				printf("%s", "Fizz\n");
			else
				printf("%d\n", i);
			}
	};
		float FibCruncher(float n) {
			if (n == 0)
				return 0;
			else if (n == 1)
				return 1;
			else
				return FibCruncher(n - 1) + FibCruncher(n - 2);
	};
		bool Delimiter(string in) {
			int s = in.length();
			char c;
			vector<char> str;
			for (int i = 0; i < in.length(); i++) {
				scanf("%c", &c);
				str.push_back(c);
			}
			int chck = 0;
			if (in.at(0) == '{' || in.at(0) == '[' || in.at(0) == '(')
				chck = 1; 
			if (in.at(in.length()) == '}' || in.at(in.length()) == ']' || in.at(in.length()) == ')')
				chck = 1;
			int half = in.length() / 2;
			if (str[0] == str[in.length() - 1]) {
				chck = 0;
				return false;
			}
			if (chck == 0) {
				if (in.length() % 2 == 0)
					return false;
				else if (str[half] == '(') {
					if (str[half-1] == ')')
						return true;
					if (str[half + 1] == ')')
						return true;
				}
				else if (str[half] == ')') {
					if (str[half + 1] == '(')
						return true;
					if (str[half - 1] == '(')
						return true;
				}
				else if (str[half] == '{') {
					if (str[half + 1] == '}')
						return true;
					if (str[half - 1] == '}')
						return true;
				}
				else if (str[half] == '}') {
					if (str[half + 1] == '{')
						return true;
					if (str[half - 1] == '{')
						return true;
				}
				else if (str[half] == ']') {
					if (str[half + 1] == '[')
						return true;
					if (str[half - 1] == '[')
						return true;
				}
				else if (str[half] == '[') {
					if (str[half + 1] == ']')
						return true;
					if (str[half - 1] == ']')
						return true;
				}
			}
			else
				return false;
			return false;
	};
};


int main() {
	JakesCodeChallengeOne chal;
	printf("%s \n", "Test Delimiter Cruncher and enter 0 to exit...");	
	string usr_in;
	scanf("%s \n", &usr_in);
	while (usr_in != "0") {
		printf("%B \n", chal.Delimiter(usr_in));
		scanf("%s \n", &usr_in);
	}
	printf("%s \n", "Test Fibonacci Cruncher and enter 0 to exit...");
	int num;
	scanf("%d \n", &num);
	while (num != 0) {
		printf("%d \n", chal.FibCruncher(num));
		scanf("%d \n", &num);
	}
	printf("%s \n", "Enter 0 to start FizzBuzz...");
	int num_two;
	scanf("%d \n", &num_two);
	if (num_two == 0) {
		chal.FizzBuzz();
	}
	else {
		printf("%s \n", "Thanks!");
	}
	return 0;
}