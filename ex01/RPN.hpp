#ifndef RPN_H
#define RPN_H

#define	GREY  "\033[38;5;246m"
#define	RESET "\033[0m"

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

class RPN
{
	public:
		static const std::string ops;

		RPN();
		RPN(const RPN &other);
		RPN& operator=(const RPN &other);
		~RPN();

		int	parseInput(const std::string& str);

		class NotEnoughNumbersException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
	private:
		std::stack<int>	_nums;
};

#endif // RPN_H
