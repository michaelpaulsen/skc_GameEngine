#ifndef CMP
#define CMP
#include <cstdarg>
#include <string>
#ifndef EXIT_SUCESS
#define EXIT_SUCESS 0
#endif // !EXIT_SUCESS
class Component
{
	bool active;
public:
	std::string name; 
	virtual bool Activate() {
		this->OnActivate(); 
		this->active = true; 
	}
	virtual bool IsActive() {
		return this->active; 
	}
	virtual int OnActivate() {
		return EXIT_SUCESS;
	}
	virtual int Run(...) {
		return EXIT_SUCESS;
	}
};
#endif // !Componet

