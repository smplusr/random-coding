#include "headref.h"

Cube cube;
Plane plane;

Uint32 start_time, frame_time;
float fps;

void render()
{	
	cube.update();
	plane.draw();
}

void FpsCalcInit()
{
	start_time = SDL_GetTicks();
}

void FpsCalc()
{
	frame_time = SDL_GetTicks() - start_time;
	fps = (frame_time > 0) ? 1000.f / frame_time : 0.f;
	std::cout << fps << std::endl;
}

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = Display::CreateWindow();
	SDL_GLContext context = SDL_GL_CreateContext(window);

	SDL_Event event;	
	const Uint8* keyState = SDL_GetKeyboardState(NULL);

	bool running = true; 
	Display::GLSettings();
	Display::GLAttributes();

	while(running)
	{
		while(SDL_PollEvent(&event))
		{
			running = event.type != SDL_QUIT;
		}

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();	
			
		Camera::Translate(keyState);
		Camera::Rotate(keyState);
		Camera::Update();
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	
		render();

		SDL_GL_SwapWindow(window);
	}
	
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}
