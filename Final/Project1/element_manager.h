#ifndef ELEMENT_MANAGER_H
#define ELEMENT_MANAGER_H

namespace MyGame {
namespace ElementManager {
	
	enum ElementSelection {
		Water,
		Earth,
		Fire,
		Air
	};

	extern ElementSelection actualElement;

	void init();
	void update();
	void draw();
}
}

#endif