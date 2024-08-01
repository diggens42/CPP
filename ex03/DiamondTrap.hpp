#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

// #include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap& operator=(const DiamondTrap &other);
		~DiamondTrap();

		void	whoAmI();
		using	ScavTrap::attack;
		using	ClapTrap::takeDamage;
		using	ClapTrap::beRepaired;
		using	ClapTrap::getName;
		using	ClapTrap::getHP;
		using	ClapTrap::getEnergy;
		using	ClapTrap::getATK;
};

#endif
