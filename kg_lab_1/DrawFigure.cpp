#include "Draw_figure.h"

void Draw_figure::DrawFigure() {
	SDL_Window* win = SDL_CreateWindow("window", 20, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	if (win == NULL) std::cout << "Error with window";
	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL) std::cout << "Error with renderer";
	SDL_RenderClear(ren);

	Shadow(ren);

	TheArtistAlgorithm(ren, PyramidL);
	SDL_RenderPresent(ren);
	SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);

	TheArtistAlgorithm(ren, PyramidR);
	SDL_RenderPresent(ren);
	SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	SDL_Delay(5000);

	SDL_DestroyWindow(win);
	SDL_Quit();
	return;
}

void Draw_figure::bresline(SDL_Renderer* ren, float x0, float y0, float x1, float y1)
{
	SDL_RenderDrawLine(ren, x0, y0, x1, y0);
}

void Draw_figure::Size(float def) {
	float* centerL = new float[3];
	centerL = Center(PyramidL);
	float sizeL[4][4] = { {def,0,0,0},
						 {0,def,0,0},
						 {0,0,def,0},
						 {centerL[0] * (1 - def),centerL[1] * (1 - def),centerL[2] * (1 - def),1} };
	PyramidL = multiplication(PyramidL, sizeL);

	float* centerR = new float[3];
	centerR = Center(PyramidR);
	float sizeR[4][4] = { {def,0,0,0},
						 {0,def,0,0},
						 {0,0,def,0},
						 {centerR[0] * (1 - def),centerR[1] * (1 - def),centerR[2] * (1 - def),1} };
	PyramidR = multiplication(PyramidR, sizeR);
}

void Draw_figure::move(float** Figure, char o, float def) {
	if (o == 'w')	for (int i = 0; i < 4; i++) Figure[i][1] -= def;
	if (o == 'a')	for (int i = 0; i < 4; i++) Figure[i][0] -= def;
	if (o == 'e')	for (int i = 0; i < 4; i++) Figure[i][2] -= def;
	if (o == 's')	for (int i = 0; i < 4; i++) Figure[i][1] += def;
	if (o == 'd')	for (int i = 0; i < 4; i++) Figure[i][0] += def;
	if (o == 'q')	for (int i = 0; i < 4; i++) Figure[i][2] += def;
}

void Draw_figure::spinCloc(char o) {
	float* centerL = new float[3];
	centerL = Center(PyramidL);

	float* centerR = new float[3];
	centerR = Center(PyramidR);
	float def = SPIN * M_PI / 180;
	if (o == 'x') {
		float spin[4][4] = { {1,   0,		  0,     0},
							{0,  cos(def), sin(def), 0},
							{0, -sin(def), cos(def), 0},
							{0,	  0,		  0		,1} };
		move(PyramidL, 'a', centerL[0]);
		move(PyramidL, 'w', centerL[1]);
		move(PyramidL, 'e', centerL[2]);
		PyramidL = multiplication(PyramidL, spin);
		move(PyramidL, 'd', centerL[0]);
		move(PyramidL, 's', centerL[1]);
		move(PyramidL, 'q', centerL[2]);

		move(PyramidR, 'a', centerR[0]);
		move(PyramidR, 'w', centerR[1]);
		move(PyramidR, 'e', centerR[2]);
		PyramidR = multiplication(PyramidR, spin);
		move(PyramidR, 'd', centerR[0]);
		move(PyramidR, 's', centerR[1]);
		move(PyramidR, 'q', centerR[2]);
	}
	if (o == 'y') {

		float spin[4][4] = { {cos(def),  0, sin(def), 0},
							{	0,		    1,	  0,	 0},
							{-sin(def), 0, cos(def), 0},
							{	0  ,	0,	  0,	1} };
		move(PyramidL, 'a', centerL[0]);
		move(PyramidL, 'w', centerL[1]);
		move(PyramidL, 'e', centerL[2]);
		PyramidL = multiplication(PyramidL, spin);
		move(PyramidL, 'd', centerL[0]);
		move(PyramidL, 's', centerL[1]);
		move(PyramidL, 'q', centerL[2]);

		move(PyramidR, 'a', centerR[0]);
		move(PyramidR, 'w', centerR[1]);
		move(PyramidR, 'e', centerR[2]);
		PyramidR = multiplication(PyramidR, spin);
		move(PyramidR, 'd', centerR[0]);
		move(PyramidR, 's', centerR[1]);
		move(PyramidR, 'q', centerR[2]);
	}

	if (o == 'z') {
		float spin[4][4] = { { cos(def), sin(def), 0, 0},
							{-sin(def), cos(def), 0, 0},
							{	 0,		   0,	  1, 0},
							{	0  ,	0,	  0,	1} };
		move(PyramidL, 'a', centerL[0]);
		move(PyramidL, 'w', centerL[1]);
		move(PyramidL, 'e', centerL[2]);
		PyramidL = multiplication(PyramidL, spin);
		move(PyramidL, 'd', centerL[0]);
		move(PyramidL, 's', centerL[1]);
		move(PyramidL, 'q', centerL[2]);

		move(PyramidR, 'a', centerR[0]);
		move(PyramidR, 'w', centerR[1]);
		move(PyramidR, 'e', centerR[2]);
		PyramidR = multiplication(PyramidR, spin);
		move(PyramidR, 'd', centerR[0]);
		move(PyramidR, 's', centerR[1]);
		move(PyramidR, 'q', centerR[2]);
	}
}


void Draw_figure::spinContCloc(char o) {

	float* centerL = new float[3];
	centerL = Center(PyramidL);

	float* centerR = new float[3];
	centerR = Center(PyramidR);
	float def = SPIN * M_PI / 180;
	if (o == 'x') {
		float spin[4][4] = { {1,    0,		  0,     0},
							{0,  cos(def), -sin(def), 0},
							{0,  sin(def),  cos(def), 0},
							{	0  ,	0,	  0,	1} };
		move(PyramidL, 'a', centerL[0]);
		move(PyramidL, 'w', centerL[1]);
		move(PyramidL, 'e', centerL[2]);
		PyramidL = multiplication(PyramidL, spin);
		move(PyramidL, 'd', centerL[0]);
		move(PyramidL, 's', centerL[1]);
		move(PyramidL, 'q', centerL[2]);

		move(PyramidR, 'a', centerR[0]);
		move(PyramidR, 'w', centerR[1]);
		move(PyramidR, 'e', centerR[2]);
		PyramidR = multiplication(PyramidR, spin);
		move(PyramidR, 'd', centerR[0]);
		move(PyramidR, 's', centerR[1]);
		move(PyramidR, 'q', centerR[2]);
	}
	if (o == 'y') {

		float spin[4][4] = { {cos(def), 0, -sin(def), 0},
							{	0,	   1,     0,	 0},
							{sin(def), 0, cos(def),  0},
							{	0  ,	0,	  0,	1} };
		move(PyramidL, 'a', centerL[0]);
		move(PyramidL, 'w', centerL[1]);
		move(PyramidL, 'e', centerL[2]);
		PyramidL = multiplication(PyramidL, spin);
		move(PyramidL, 'd', centerL[0]);
		move(PyramidL, 's', centerL[1]);
		move(PyramidL, 'q', centerL[2]);

		move(PyramidR, 'a', centerR[0]);
		move(PyramidR, 'w', centerR[1]);
		move(PyramidR, 'e', centerR[2]);
		PyramidR = multiplication(PyramidR, spin);
		move(PyramidR, 'd', centerR[0]);
		move(PyramidR, 's', centerR[1]);
		move(PyramidR, 'q', centerR[2]);
	}

	if (o == 'z') {
		float spin[4][4] = { {cos(def), -sin(def), 0, 0},
							{sin(def),  cos(def), 0, 0},
							{	0,			0,	  1, 0},
							{	0  ,	0,	  0,	1} };
		move(PyramidL, 'a', centerL[0]);
		move(PyramidL, 'w', centerL[1]);
		move(PyramidL, 'e', centerL[2]);
		PyramidL = multiplication(PyramidL, spin);
		move(PyramidL, 'd', centerL[0]);
		move(PyramidL, 's', centerL[1]);
		move(PyramidL, 'q', centerL[2]);

		move(PyramidR, 'a', centerR[0]);
		move(PyramidR, 'w', centerR[1]);
		move(PyramidR, 'e', centerR[2]);
		PyramidR = multiplication(PyramidR, spin);
		move(PyramidR, 'd', centerR[0]);
		move(PyramidR, 's', centerR[1]);
		move(PyramidR, 'q', centerR[2]);
	}
}

float** Draw_figure::multiplication(float** A, float B[4][4]) {
	float** res = new float*[4];
	for (int i = 0; i < 4; i++) res[i] = new float[4];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) res[i][j] = 0;

	for (int k = 0; k < 4; k++)
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				res[k][i] += A[k][j] * B[j][i];
	return res;
}

float* Draw_figure::Center(float** A) {
	float* center = new float[3];
	center[0] = (A[0][0] + A[1][0] + A[2][0] + A[3][0]) / 4;
	center[1] = (A[0][1] + A[1][1] + A[2][1] + A[3][1]) / 4;
	center[2] = (A[0][2] + A[1][2] + A[2][2] + A[3][2]) / 4;
	return center;
}

float** Draw_figure::Isometric_rearrangement(float** A) {
	double theta = (double)15 / 180 * M_PI;
	double fi = (double)20 / 180 * M_PI;
	float matrixArray[4][4] = { {cos(theta), sin(theta) * sin(fi), -sin(theta) * cos(fi), 0},
								{0, cos(fi), sin(fi), 0},
								{sin(theta),  -cos(theta) * sin(fi), cos(theta) * cos(fi), 0},
								{0, 0, 0, 1} };
	float* center = new float[3];
	center = Center(A);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4;j++) A[j][i] -= center[i];

	A = multiplication(A, matrixArray);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4;j++) A[j][i] += center[i];

	return A;
}