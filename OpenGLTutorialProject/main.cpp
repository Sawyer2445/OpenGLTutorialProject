#include "iostream"
#include <GL/glew.h>
#include "display.h"


int wmain()
{
	display* dis = new display(800, 600, "Hello OpenGL!");
	while (!dis->IsClosed())
	{
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		dis->Update();
	}
	delete dis;
	system("pause");
	return 0;
}