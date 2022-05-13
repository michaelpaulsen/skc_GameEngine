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
	static uint64_t nextuuid = 0;
public: 
	uint64_t uuid; 
	Entity() {
		this->uuid = nextuuid++;
		///nothing should decrement nextuuid 
		/// it only would add overhead to the run-time to add the uuid 
		/// + that isn't cross operating system.
	}
	auto GetUUID() {
		return this->uuid; 
	}
	std::vector<Component*> components;
	Component* GetFirstComponetByName(std::string name) {
		for (const auto &x : this->components) {
			if (x->name == name) return x; 
		}
		return nullptr; 
	}
};
#endif // !ENT
