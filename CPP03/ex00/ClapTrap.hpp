#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <string>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_energy;
		unsigned int	_atk;
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap &other);
		ClapTrap& operator=(const ClapTrap &other);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string		getName() const;
		unsigned int	getHP() const;
		unsigned int	getEnergy() const;
		unsigned int	getATK() const;

		void			setName(const std::string& set_name);
		void			setHP(unsigned int set_hp);
		void			setEnergy(unsigned int set_energy);
		void			setATK(unsigned int set_atk);

};

#endif
