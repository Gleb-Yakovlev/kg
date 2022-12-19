#include "Draw_figure.h"

void Draw_figure::Shadow(SDL_Renderer* ren) {

	float** a = new float* [4];
	for (int i = 0; i < 4; i++) *a = new float[2];
	a = Find_the_int_point(PyramidL);

	float b1[9] = { a[0][0], a[0][1], 1,
		a[1][0], a[1][1], 1,
		a[3][0], a[3][1], 1
	};
	int rgba[4] = { 125,125,125,125 };
	Line_by_line(ren, b1, rgba);
	SDL_RenderPresent(ren);
	SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);

	float b2[9] = { a[0][0], a[0][1], 1,
	a[1][0], a[1][1], 1,
	a[2][0], a[2][1], 1
	};
	Line_by_line(ren, b2, rgba);
	SDL_RenderPresent(ren);
	SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);

	float b3[9] = { a[2][0], a[2][1], 1,
	a[3][0], a[3][1], 1,
	a[0][0], a[0][1], 1
	};
	Line_by_line(ren, b3, rgba);
	SDL_RenderPresent(ren);
	SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);


	a = Find_the_int_point(PyramidR);
	float c1[9] = { a[0][0], a[0][1], 1,
		a[1][0], a[1][1], 1,
		a[3][0], a[3][1], 1
	};
	Line_by_line(ren, c1, rgba);
	SDL_RenderPresent(ren);
	SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);

	float c2[9] = { a[0][0], a[0][1], 1,
	a[1][0], a[1][1], 1,
	a[2][0], a[2][1], 1
	};
	Line_by_line(ren, c2, rgba);
	SDL_RenderPresent(ren);
	SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);

	float c3[9] = { a[2][0], a[2][1], 1,
	a[3][0], a[3][1], 1,
	a[0][0], a[0][1], 1
	};
	Line_by_line(ren, c3, rgba);
	SDL_RenderPresent(ren);
	SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
}

float** Draw_figure::Find_the_int_point(float** Figure) {

	float** matrix = new float* [4];
	for (int i = 0; i < 4; i++) matrix[i] = new float[4];

	for (int i = 0; i < 4; i++) {
		matrix[i][0] = Figure[i][0];
		matrix[i][1] = floor;
		matrix[i][2] = Figure[i][2];
		matrix[i][3] = 1;
	}

	float** b = new float* [4];
	for (int i = 0; i < 4; i++) b[i] = new float[2];
	float zm = 350;

	for (int i = 0; i < 4; i++) {
		b[i][0] = matrix[i][0] * (zm)/(matrix[i][2]);
		b[i][1] = matrix[i][1] * (zm) / (matrix[i][2]);
	}

	return b;
}