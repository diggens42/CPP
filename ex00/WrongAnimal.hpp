#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <string>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal& operator=(const WrongAnimal &other);
		~WrongAnimal();

		void makeSound() const;
		std::string getType() const;
		void	setType(std::string type);

	protected:
		std::string _type;
};

#endif // WRONGANIMAL_H
