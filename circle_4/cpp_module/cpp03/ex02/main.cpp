#include "FragTrap.hpp"

int main(void)
{
  std::string s1 = "dayun";
  std::string s2 = "bcho";
  std::string s3 = "yback";

  FragTrap t1(s1);
  FragTrap t2(s2);
  ClapTrap t3(s3);

  std::cout << std::endl;
  t1.attack(s3);
  t3.takeDamage(t1.getAttackDamage());
  std::cout << std::endl;

  std::cout << std::endl;
  t1.attack(s2);
  t2.takeDamage(t1.getAttackDamage());
  t2.beRepaired(t1.getAttackDamage() / 2);
  t2.beRepaired(t1.getAttackDamage() / 2);
  t2.beRepaired(t1.getAttackDamage() / 2);
  std::cout << std::endl;

  std::cout << std::endl;
  t1.attack(s3);
  t2.takeDamage(t1.getAttackDamage());
  t1.attack(s3);
  t2.takeDamage(t1.getAttackDamage());
  t1.attack(s3);
  t2.takeDamage(t1.getAttackDamage());
  std::cout << std::endl;

  std::cout << std::endl;
  t2.highFivesGuys();
  std::cout << std::endl;
  return 0;
}