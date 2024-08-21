#ifndef BRAIN_H
#define BRAIN_H
#include <string>

class Brain {
	public:
		Brain();
		Brain(const Brain &other);
		Brain& operator=(const Brain &other);
		~Brain();
	private:
		std::string ideas[100];
};

#endif // BRAIN_H
