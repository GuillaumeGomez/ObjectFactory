#include "ObjectFactory.hpp"
#include <string>
#include <vector>
#include <iostream>

class MotherClass
{
public:
  MotherClass(){}
  virtual ~MotherClass(){}
  virtual std::string	className(){
    return std::string("MotherClass");
  }
};

class DaughterClass1 : public MotherClass
{
public:
  DaughterClass1(int t) : MotherClass(), m_t(t){}
  virtual ~DaughterClass1(){}
  virtual std::string	className(){
    return std::string("DaughterClass1");
  }

private:
  int	m_t;
};

class DaughterClass2 : public MotherClass
{
public:
  DaughterClass2(const char *s, float t) : MotherClass(), m_s(s), m_t(t){}
  virtual ~DaughterClass2(){}
  virtual std::string	className(){
    return std::string("DaughterClass2");
  }

private:
  std::string	m_s;
  float		m_t;
};

int	main()
{
  std::vector<ObjectFactory*>	vec;
  std::vector<MotherClass*>	datas;

  vec.push_back(ObjectFactory::createNewObject<DaughterClass1, int>(18));
  vec.push_back(ObjectFactory::createNewObject<MotherClass>());
  vec.push_back(ObjectFactory::createNewObject<DaughterClass2, const char*, float>("test", 4.f));

  for (auto it = vec.begin(); it != vec.end(); ++it) {
      datas.push_back((*it)->createObject());
      delete *it;
    }
  vec.clear();
  for (auto it = datas.begin(); it != datas.end(); ++it) {
      std::cout << (*it)->className() << std::endl;
      delete *it;
    }
  datas.clear();
  return 0;
}
