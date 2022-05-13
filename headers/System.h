#ifndef ECS
#define ECS 
#include "Entity.h"
#include <vector>
class System {
	std::vector<Entity*> entities;
	/// this will hold other things like the renderer and input systems but for now it just holds the suff for the entity
	Entity* GetEntityByUUID(uint64_t uuid) {
		for (const auto &x : this->entities) {
			if (x->GetUUID() == uuid)return x;
			///it is up to the end-user to keep track of the uuids. 
			/// they might want to put the uuid for the player(s) in thier own vars... 
		}
	}
};
#endif // !ECS
