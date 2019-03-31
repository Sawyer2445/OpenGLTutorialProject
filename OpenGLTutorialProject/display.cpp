#include "display.h"
#include <Gl/glew.h>
#include <iostream>

display::display(int width, int height, const std::string & title)
{
	//init SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//set some properties 
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	//create SDL window
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	//create OpenGL context
	m_glContext = SDL_GL_CreateContext(m_window);

	GLenum status = glewInit();

	if (status != GLEW_OK)
	{
		std::cerr << "GLEW failed to init !!!" << std::endl;
	}

	m_isClosed = false;
}

void display::Update()
{
	SDL_GL_SwapWindow(m_window);

	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			m_isClosed = true;
		}
	}
}

bool display::IsClosed()
{
	return m_isClosed;
}

display::~display()
{
	SDL_GL_DeleteContext(m_glContext);	//delete OpenGL context
	SDL_DestroyWindow(m_window);		//delete SDL window 
	SDL_Quit();							//uninit SDL 
}
