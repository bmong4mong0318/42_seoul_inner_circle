#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void prevMainTest()
{
  std::string str;
  Animal *meta[10];

  for (size_t i = 0; i < 4; i++)
  {
    (i % 2) ? meta[i] = new Dog() : meta[i] = new Cat();
    std::cout << std::endl;
  }
  std::cout << std::endl;

  for (size_t i = 0; i < 4; i++)
  {
    delete meta[i];
    std::cout << std::endl;
  }
  std::cout << std::endl;

  Dog *d = new Dog();
  Dog *d2 = new Dog();
  std::cout << std::endl;
  str = d->getBrain()->getIdeas(0);
  std::cout << "Dog1's first idea is " << str << std::endl;

  d->getBrain()->setIdeas("something", 0);
  str = d->getBrain()->getIdeas(0);
  std::cout << "Dog1's first idea is " << str << std::endl;

  *d2 = *d;
  str = d2->getBrain()->getIdeas(0);
  std::cout << "Dog2's first idea is " << str << std::endl;

  std::cout << std::endl;
  delete d;
  d = NULL;
  delete d2;
  d2 = NULL;
}

int main()
{
  /*
   * Can not use an Abstract class
   */
  // const Animal* meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // will output the cat sound!
  j->makeSound();
  // ...

  delete i;
  i = NULL;

  delete j;
  j = NULL;

  std::cout << std::endl
            << "prevMainTest" << std::endl
            << std::endl;
  prevMainTest();
  system("leaks a.out");
  return 0;
}