#include <iostream>
#include <string>
#include <memory>

using namespace std;


typedef struct { int index; } token_t;

static int g_singleton_index = 0;

template<typename T>
class Singleton {
public:
    static T& instance();
    static token_t token;

    Singleton(const Singleton&) = delete;
    Singleton& operator= (const Singleton) = delete;

protected:
    Singleton() {}
};

template<typename T> token_t Singleton<T>::token = {};

template<typename T>
T& Singleton<T>::instance()
{
    static const std::unique_ptr<T> minstance {  new T{&token}};
    cout << "Singleton::instance " << minstance->token.index << endl; 
    return *minstance;
}

class Animal : public Singleton<Animal> {
private:
  string name;


public:

  Animal(token_t *token) {
    token->index = g_singleton_index++;
	name = "default";
	cout << "Animal()::Animal() set name as " << name << endl;
  }

  ~Animal() {
      cout << "[" << token.index << "] ~Animal()" << endl;
  };

  void setName(const char *aName) {
	cout << "Animal()::setName() <= " << aName << endl;
	name.clear();
	name.append(aName);
	cout << "Animal()::setName() set name as " << name << endl;
  } 

  void show() {
      cout << "[" << token.index << "]" ;
      cout << "Animal()::show() name is " << name << endl;
  } ;
};

class Zoo : public Singleton<Zoo> {
private:
  string name;

public:

  Zoo(token_t *token) {
    token->index = g_singleton_index++;
	name = "default";
	cout << "Zoo()::Zoo() set name as " << name << endl;
  }

  ~Zoo() {
      cout << "[" << token.index << "] ~Zoo()" << endl;
  }
  string &getName() {
      return name;
  }

  void setName(const char *aName) {
	cout << "Zoo()::setName() <= " << aName << endl;
	name.clear();
	name.append(aName);
	cout << "Zoo()::setName() set name as " << name << endl;
  } 

  void show() {
      cout << "[" << token.index << "]" ;
      cout << "Zoo()::show() name is " << name << endl;
  } ;
};

//template <> token_t Singleton<Animal>::token = {};
//template <> token_t Singleton<Zoo>::token = {};

#define INIT_SINGLETON(CLSNAME, varname) static CLSNAME *varname = NULL;
#define GET_SINGLETON(CLSNAME, mname) if (!mname) { CLSNAME &inner = CLSNAME::instance(); mname = &inner; }

INIT_SINGLETON(Animal, b);

int sub_func()
{
    GET_SINGLETON(Animal, b);
    b->show();
    return 0;
}

int main()
{
    Animal &a = Animal::instance();
    GET_SINGLETON(Animal, b);
    Zoo &z = Zoo::instance();
    Zoo &z2 = Zoo::instance();
    Animal &a2 = Animal::instance();

    a.setName("It is an abnormal dog.");
    z.setName("It is a the one");

    a.show();
    z.show();
    b->show();
    sub_func();
    return 0;
}
