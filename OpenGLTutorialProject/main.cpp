#include "iostream"
#include "display.h"
#include <GL/glew.h>

int main(int argc, char** argv)
{
	
	display* dis = new display(800, 600, "Title");
	delete dis;
	system("pause");
	return 0;
}