//
// Created by 12132 on 2022/3/21.
//

#ifndef INPUT_H_
#define INPUT_H_
#include "utility.h"
#include "math.hpp"
#include "render_types.h"
#include "SoftRenderer.h"

enum MouseButtonType {
	BUTTON_LEFT,
	BUTTON_RIGHT,
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_MIDDLE,
	MAX,
};

struct MouseButton {
	b32 isDown = false;
	b32 changed = false;
};

struct Mouse {
	i32 x, y;

	MouseButton buttons[MouseButtonType::MAX];
	Mouse(i32 x, i32 y) : x(x), y(y), buttons{0} {}

	void process(vec2f& player, RenderTarget& target){
		SoftRenderer::ClearScreen(target, 0xFF0000);
		if (IsPressed(BUTTON_LEFT))  player.x -=20;
		if (IsPressed(BUTTON_RIGHT)) player.x +=20;
		if (IsPressed(BUTTON_UP))    player.y += 20;
		if (IsPressed(BUTTON_DOWN))  player.y -= 20;
	}
private:
	b32 IsPressed(MouseButtonType type)
	{ return buttons[type].isDown &&
			buttons[type].changed; }
};


struct Button {

};


#endif // INPUT_H_
