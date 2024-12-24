#include "Application.h"
#include "globals.h"

Application::Application():
	window{g_width, g_height, g_title}
{

}

void Application::Run()
{
	while (!window.shouldClose()) {
		BeginDrawing();

		ClearBackground(GRAY);
		DrawFPS(10, 10);

		EndDrawing();
	}
}
