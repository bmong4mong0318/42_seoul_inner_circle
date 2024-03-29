#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
  for (int i = 0; i < 4; i++)
    this->_amateria[i] = NULL;
  std::cout << std::setw(15) << "[MateriaSource] "
            << "create!!" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &ref)
{
  const AMateria *tmpAMateria;

  for (int i = 0; i < 4; i++)
  {
    if (this->_amateria[i])
      delete this->_amateria[i];

    tmpAMateria = ref.getAMateria(i);
    if (tmpAMateria)
      this->_amateria[i] = tmpAMateria->clone();
  }
  std::cout << std::setw(15) << "[MateriaSource] "
            << "copy!!" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &ref)
{
  const AMateria *tmpAMateria;

  std::cout << std::setw(15) << "[MateriaSource] "
            << "operator=!!" << std::endl;
  if (this != &ref)
  {
    for (int i = 0; i < 4; i++)
    {
      if (this->_amateria[i])
      {
        delete this->_amateria[i];
        this->_amateria[i] = NULL;
      }

      tmpAMateria = ref.getAMateria(i);
      if (tmpAMateria)
        this->_amateria[i] = tmpAMateria->clone();
    }
  }
  return *this;
}

MateriaSource::~MateriaSource()
{
  std::cout << std::setw(15) << "[MateriaSource] "
            << "delete!!" << std::endl;
  for (int i = 0; i < 4; i++)
  {
    if (this->_amateria[i])
      delete this->_amateria[i];
    this->_amateria[i] = NULL;
  }
}

const AMateria *MateriaSource::getAMateria(int idx) const
{
  if (idx < 0 || idx > 3)
  {
    std::cout << std::setw(15) << "[AMateria] "
              << "getAMateria - out of range" << std::endl;
    return NULL;
  }
  return this->_amateria[idx];
}

void MateriaSource::learnMateria(AMateria *amateria)
{
  for (int i = 0; i < 4; i++)
  {
    if (this->_amateria[i] == NULL)
    {
      this->_amateria[i] = amateria->clone();
      std::cout << std::setw(15) << "[MateriaSource] "
                << "learnMateria success!!" << std::endl;
      return;
    }
  }
  std::cout << std::setw(15) << "[MateriaSource] "
            << "learnMateria failure!!" << std::endl;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
  for (int i = 0; i < 4; i++)
  {
    if (this->_amateria[i] && this->_amateria[i]->getType() == type)
    {
      std::cout << std::setw(15) << "[MateriaSource] "
                << "createMateria " << type << " success!!" << std::endl;

      return this->_amateria[i]->clone();
    }
  }
  std::cout << std::setw(15) << "[MateriaSource] "
            << "createMateria " << type << " failure!!" << std::endl;
  return NULL;
}
