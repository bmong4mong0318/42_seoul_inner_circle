#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap("ScavTrap")
{
  std::cout << "ScavTrap ScavTrap is created." << std::endl;
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name)
{
  std::cout << "ScavTrap " << name << " is created." << std::endl;
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
  std::cout << "ScavTrap copy constructor called." << std::endl;
  this->_name = scavTrap.getName();
  this->_hitPoints = scavTrap.getHitPoints();
  this->_energyPoints = scavTrap.getEnergyPoints();
  this->_attackDamage = scavTrap.getAttackDamage();
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
  std::cout << "ScavTrap operator= " << scavTrap.getName() << " called." << std::endl;
  if (this != &scavTrap)
  {
    this->_name = scavTrap.getName();
    this->_hitPoints = scavTrap.getHitPoints();
    this->_energyPoints = scavTrap.getEnergyPoints();
    this->_attackDamage = scavTrap.getAttackDamage();
  }
  return *this;
}

ScavTrap::~ScavTrap()
{
  std::cout << "ScavTrap " << this->_name << " destructor called." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
  if (this->_energyPoints == 0 || this->_hitPoints == 0)
  {
    (this->_energyPoints == 0) ? std::cout << "ScavTrap is not enough energy." << std::endl : std::cout << "ScavTrap " << this->_name << "'s HP is 0. Please repair !" << std::endl;
    return;
  }

  std::cout << "ScavTrap " << this->_name << " attacks "
            << target << ", causing " << this->_attackDamage
            << " points of damage!" << std::endl;
  this->_energyPoints--;
}

void ScavTrap::guardGate()
{
  if (this->_hitPoints == 0 || this->_energyPoints == 0)
  {
    (this->_energyPoints == 0) ? std::cout << "ScavTrap is not enough energy." << std::endl : std::cout << "ScavTrap " << this->_name << "'s HP is 0. Please repair !" << std::endl;
    return;
  }
  std::cout << "ScavTrap " << this->_name << " has entered Gatekeeper mode." << std::endl;
  this->_energyPoints--;
}