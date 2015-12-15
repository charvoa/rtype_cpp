//
// BonusIG.hpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Dec  9 13:32:20 2015 Nicolas Charvoz
// Last update Sat Dec 19 14:08:29 2015 Nicolas Charvoz
//

#ifndef BONUSIG_HPP_
# define BONUSIG_HPP_

# include <AEntity.hh>
# include <string>
# include <iostream>

class BonusIG : public AEntity {

private:

  std::string _name;

public:

  BonusIG() : AEntity(id) {
    _name = "11";
    this->addSystem(C_POSITION);
    this->setInnerEntity();
  }
  ~BonusIG() {}
  void addSystem(E_Component type) {
    _systemManager->addSystemByTupe(type);
  }
  void setInnerEntity()
  {
    Random random(0, 3);
    int randNb = random.generate<int>();

    if (randNb == 0 || randNb == 3)
      {
	std::cout << "I won't have any bonus inside me ..." << std::endl;
      }
    else if (randNb == 1)
      {
	std::cout << "I will have Missile inside me ... " << std::endl;
	this->addSystem(C_MISSILE);
      }
    else if (randNb == 2)
      {
	std::cout << "I will have Laser inside me ... " << std::endl;
	this->addSystem(C_LASER);
      }
  }


};

#endif
