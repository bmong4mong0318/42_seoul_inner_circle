#ifndef AMateria_HPP
#define AMateria_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
  protected:
    /* data */
    std::string _type;

  public:
    /*
    * A default constructor
    */
    AMateria();
    explicit AMateria(std::string const& type);

    /*
    * A copy constructor
    */
    AMateria(const AMateria& ref);

    /*
    * A assignment operator overload
    */
    AMateria&	operator=(const AMateria& ref);

    /*
    * A destructor
    */
    virtual ~AMateria();

    /*
    * Add it if you feel necessary additional member functions.
    */
    std::string const& getType() const; // Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

/*
* Add it if you feel necessary additional functions.
*/

#endif  //AMateria_HPP
