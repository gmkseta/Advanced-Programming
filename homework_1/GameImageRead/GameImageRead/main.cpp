#pragma comment (lib,"SDL2")
#pragma comment (lib,"SDL2main")
#pragma comment (lib,"SDL2_image")
#pragma comment (lib,"opengl32.lib")

#include <cstdio>
#include <SDL2\SDL.h>
#include <SDL2\SDL_opengl.h>
#include <SDL_image.h>

using namespace std;


SDL_Renderer *renderer;


int main(int argc, char **argv) {
	int winWidth = 800;
	int winHeight = 600;

	SDL_Window *win = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Surface *image;
	SDL_RWops *rwop;
	rwop = SDL_RWFromFile("../res/img.png", "rb");
	image = IMG_LoadPNG_RW(rwop);
	GLubyte *map = (GLubyte*)image->pixels;

	int w, h;
	w = image->w;
	h = image->h;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return 1;

	win = SDL_CreateWindow("gl", 100, 100, winWidth, winHeight, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	SDL_GLContext context;
	context = SDL_GL_CreateContext(win);


	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);

	GLuint texId;
	glGenTextures(1, &texId);
	glBindTexture(GL_TEXTURE_2D, texId);
	glTexImage2D(
		GL_TEXTURE_2D, 0, GL_RGBA,
		w, h, 0,
		GL_RGBA, GL_UNSIGNED_BYTE,
		map
	);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);


	while (1) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				break;
			else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
				break;
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glOrtho(0, winWidth, winHeight, 0, -1, 1);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glBindTexture(GL_TEXTURE_2D, texId);

		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(0, 0);
		glTexCoord2f(1.0, 0.0); glVertex2f(w, 0);
		glTexCoord2f(1.0, 1.0); glVertex2f(w, h);
		glTexCoord2f(0.0, 1.0); glVertex2f(0, h);
		glEnd();

		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(0 + 30, 0 + 30);
		glTexCoord2f(1.0, 0.0); glVertex2f(w + 30, 0 + 30);
		glTexCoord2f(1.0, 1.0); glVertex2f(w + 30, h + 30);
		glTexCoord2f(0.0, 1.0); glVertex2f(0 + 30, h + 30);
		glEnd();


		SDL_GL_SwapWindow(win);
		SDL_Delay(21);

	}

	SDL_GL_DeleteContext(context);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);

	return 0;

}




출처: http://tibyte.kr/232 [티바이트]