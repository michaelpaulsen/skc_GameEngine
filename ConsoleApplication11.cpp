#include "pch.h"
#include <iostream>

#include "headers/System.h"
#include "./cpp files/common_comonents.cpp" 
#ifdef WIN32
#include <conio.h>
#else// WIN32
#include "curses.h"
#endif // !WIN32 

enum class EntityTypes {
	DEFAULT    = 000,
	character  = 100,
	player     = 105,
	npc        = 110,
	monster    = 115, 
	interacter = 200,
	book       = 300,
	sign       = 305,
};


///allows for 99 subtypes of each maintype 
/// the main Types are DEFAULT character interacter and book  
/// 1-99 are unused because if it is not default and not one of the above listed types it is malformed
char getChar() {
	/// read a single character from the console without echoing the character
#ifdef WIN32
	return _getch();
#else
	return getch();
#endif
}

int ettoi(EntityTypes x) {
	return (int)x; 
}
int main()
{
	System sys;
	auto playerUUID = sys.CreateEntity(ettoi(EntityTypes::player));
	auto playerpos = Position2d();
	auto player = sys.GetEntityByUUID(playerUUID); 
	player->components.emplace_back(playerpos); 
	
	auto c = getchar();
	while (c !='e')
	{
		printf("%d", (int)c);
		c = getchar();
	}

} 