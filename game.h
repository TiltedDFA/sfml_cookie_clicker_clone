#pragma once
#include "cookie.h"
#define cookie_file "assets/cookie.png"
#define bground_file "assets/back_ground.png"

class game
{
public:
	game()=default;
	~game();
	void run();
private:
	back_ground* m_back_ground = new back_ground(bground_file);
	cookie* m_cookie = new cookie(cookie_file);
};

