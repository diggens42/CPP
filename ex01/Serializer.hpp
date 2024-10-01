#ifndef SERIALIZER_H
#define SERIALIZER_H

#define	GREY  "\033[38;5;246m"
#define	RESET "\033[0m"

#include <iostream>

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer &other);
		Serializer& operator=(const Serializer &other);
		~Serializer();

	private:

};

#endif // SERIALIZER_H
