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

	enum Ability {
		none,
		first,
		second,
		third
	};


	extern ElementSelection actualElement;
	extern Ability currentAbility;

	void init();
	void update();
	void draw();
}
}

#endif