#ifndef CMP
#define CMP
#include <cstdarg>
#include <string>
#ifndef EXIT_SUCESS
#define EXIT_SUCESS 0
#endif // !EXIT_SUCESS
class Component
{
	bool active = false;
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
	///I'm shure im not the first one to do this but I'm implementing it in my own way
	/// what making this a variadic function does is it allows you to pass in any function
	/// then in the override of run only deal with the ones that you want to
	/// this prevents you from having to pass a whole GameState object to the run function
	virtual int Run(...) {
		return EXIT_SUCESS;
	}
};
#endif // !Componet

