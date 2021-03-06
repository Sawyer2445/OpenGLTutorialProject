#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <string>

class display
{
public:
	display(int width, int height, const std::string& title);
	void Update();
	bool IsClosed();
	virtual ~display();
private:
	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;
};

#endif // !DISPLAY_H


