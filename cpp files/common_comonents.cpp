#include "..\headers\Component.h"
class Position2d: public Component {
	int x, y; 
	virtual int Run(char* action ...) override{
		va_list val;
		va_start(val, action); 
		auto targetX = va_arg(val, int);
		auto targetY = va_arg(val, int);
		if (action == "move") {
			while (x != targetX && y != targetY) {
				if (targetX < x) {
					x--; 
				}
				else if(targetX > x){
					x++; 
				}
				if (targetY < y) {
					y--;
				}
				else if (targetY > y) {
					y++;
				}
				printf("\x1b[31m moved to (%d,%d)", x,y);
			}
			/// if you moved print moved and the x and y in red 
		}
		else {
			x = targetX;
			y = targetY; 
			printf("\x1b[34m teleported to (%d,%d)",x,y); /// if you didn't move print te
		}
		printf("\x1b[37m");
		va_end(val);
		return EXIT_SUCESS;
	}
	
};