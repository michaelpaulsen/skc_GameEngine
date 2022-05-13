#ifndef ENT
#define ENT 
#include <vector>
#include <string>
#include <stdarg.h>
#include <stdint.h>
//not nessiary for msvs but put it in here so that other compilers have it 
/// custom files. 
#include "Component.h"

class Entity {
	static inline uint64_t nextuuid = 0;
		   uint64_t uuid;
		   uint64_t type;
	///this is the type of the entity
	///the end user should define an enum that has all of the types that they use
	///this can be used by the system to return a vector of all of the entities of that type
public: 
	Entity(int t = 0) : uuid(nextuuid++), type(t) {
		///nothing should decrement nextuuid 
		/// it only would add overhead to the run-time to add the uuid using the os dependent function calls
		/// + that isn't cross operating system.
	}
	auto GetType() {
		return this->type; 
	}
	auto GetUUID() {
		return this->uuid; 
	}
	std::vector<Component*> components;
	Component* GetFirstComponetByName(std::string name) {
		/// gets the first component of type name then returns it 
		for (const auto &x : this->components) {
			if (x->name == name) return x; 
		}
		return nullptr; 
	}
	Component* GetFirstActiveComponetByName(std::string name) {
		///gets the first component that has its active bit set to true of type name then returns it 
		for (const auto &x : this->components) {
			if (x->name == name && x->IsActive()) return x;
		}
		return nullptr;
	}
	void AddComponent(Component* comp) {
		this->components.push_back(comp); 
	}
};
#endif // !ENT