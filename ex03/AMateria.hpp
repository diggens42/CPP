#ifndef AMATERIA_H
#define AMATERIA_H

class ICharacter;

class AMateria {
	public:
		AMateria();
		AMateria(const AMateria &other);
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria& operator=(const AMateria &other);

		std::string const & getType() const;
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
	protected:
		std::string	type;
};

#endif // AMATERIA_H
