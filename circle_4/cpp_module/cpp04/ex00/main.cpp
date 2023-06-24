#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // will output the cat sound!
  j->makeSound();
  meta->makeSound();
  // ...

  const WrongAnimal *wrongMeta = new WrongAnimal();
  const WrongAnimal *wrongCat = new WrongCat();
  wrongMeta->makeSound();
  wrongCat->makeSound();

  delete meta;
  meta = NULL;

  delete i;
  i = NULL;

  delete j;
  j = NULL;

  delete wrongMeta;
  wrongMeta = NULL;

  delete wrongCat;
  wrongCat = NULL;

  // system("leaks a.out");
  return 0;
}