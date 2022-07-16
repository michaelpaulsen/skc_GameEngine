#ifndef ECS
#define ECS 
#include <vector>
#include <stdint.h>
//not nessiary for msvs but put it in here so that other compilers have it 
///custom files
#include "Entity.h"
class System {
	std::vector<Entity> entities;
	/// this will hold other things like the renderer and input systems but for now it just holds the suff for the entity
public: 
	uint64_t CreateEntity(int type = 0) {
		/// this should be from your entity_type struct*/
		/// this should be the main way that you create entities if you want to keep the uuid 
		auto e = Entity(type);
		auto GUID = e.GetUUID(); 
		this->entities.push_back(e);
		return GUID; 
	}
	Entity GetEntityByUUID(uint64_t uuid) {
		for ( const auto &x : this->entities) {
			if (x.GetUUID() == uuid)return x;
			///it is up to the end-user to keep track of the uuids. 
			/// they might want to put the uuid for the player(s) in thier own vars... 
		}
		return NULL; 
	}
	std::vector<Entity> GetEntitiesByType(int type) {
		std::vector< Entity> ent;
		for (const auto x : this->entities) {
			if (x.GetType() == type) {
				ent.push_back(x);
			}
		}
		return ent;
		///this should be the list of all of the entities of a given type. 
	}
	void AddEntity(Entity ent) {
		entities.push_back(ent);
	}
};
#endif // !ECS
