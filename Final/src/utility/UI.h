#ifndef UI_H
#define UI_H

#include "raylib.h"

namespace MyGame {
namespace UI {
	
	struct Button {
		Rectangle rec;
		float thick;
		Color color;
	};

	static void createButton(const char* title, Button button, Color generalColor, float fontSize);

}
}

#endif
