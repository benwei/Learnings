#include <iostream>
#include <string>

using namespace std;

class Animal {
private:
  static Animal *instance;
  string name;

public:
  static Animal *getSingleton() {
		if (!instance)
		    instance = new Animal();
		return instance;
	}

  Animal() {
	name = "default";
	cout << "Animal()::Animal() set name as " << name << endl;
  }

  void setName(const char *aName) {
	cout << "Animal()::setName() <= " << aName << endl;
	name.clear();
	name.append(aName);
	cout << "Animal()::setName() set name as " << name << endl;
  } 

  void show() {
  } ;
};

Animal* Animal::instance = NULL;

static Animal *_cat;

Animal *public_cat = _cat;

int main()
{
	Animal *dog = Animal::getSingleton();
        if (dog) {
		dog->setName("dog");
	}

	return 0;
}
