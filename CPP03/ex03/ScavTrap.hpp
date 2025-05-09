#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap &other);
		ScavTrap& operator=(const ScavTrap &other);
		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();
	private:
		void	init(void);
};

#endif
