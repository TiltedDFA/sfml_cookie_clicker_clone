#pragma once
#include "cookie.h"
#define cookie_file "assets/cookie.png"
#define bground_file "assets/back_ground.png"

class game
{
public:
	game();
	void run();
private:
	back_ground m_back_ground;
	cookie m_cookie;
};

