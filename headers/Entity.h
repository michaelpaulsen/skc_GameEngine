#ifndef ENT
#define ENT 
#include <vector>
#include <string>
#include <stdarg.h>
#include ".\Component.h"

class Entity {
public: 
	std::vector<Component*> components;
	Component* GetFirstComponetByName() {
		for (auto &x : this->components) {
			if (x.name = name) return x; 
		}
	}
};
#endif // !ENT
