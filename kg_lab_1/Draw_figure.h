#pragma once
#include <iostream>
#include <math.h>
#include <SDL.h>

#define _CRT_SECURE_NO_WARNINGS
#define SPIN 30
using namespace std;

class Draw_figure {
public:

	float** PyramidL = new float* [4];
	float** PyramidR = new float* [4];
	float floor = 500;

	Draw_figure() {
		for (int i = 0; i < 4; i++) PyramidL[i] = new float[4];
		for (int i = 0; i < 4; i++) PyramidR[i] = new float[4];

		PyramidL[0][0] = 300-50; PyramidL[0][1] = 300 - 50; PyramidL[0][2] = 100+300; PyramidL[0][3] = 1;//b1
		PyramidL[1][0] = 200 - 50; PyramidL[1][1] = 300 - 50; PyramidL[1][2] = 150 + 300; PyramidL[1][3] = 1;//b2
		PyramidL[2][0] = 100 - 50; PyramidL[2][1] = 300 - 50; PyramidL[2][2] = 100 + 300; PyramidL[2][3] = 1;//b3
		PyramidL[3][0] = 200 - 50; PyramidL[3][1] = 100 - 50; PyramidL[3][2] = 125 + 300; PyramidL[3][3] = 1;//b4

		PyramidR[0][0] = 600 - 50; PyramidR[0][1] = 300 - 50; PyramidR[0][2] = 100 + 300; PyramidR[0][3] = 1;//a1
		PyramidR[1][0] = 500 - 50; PyramidR[1][1] = 300 - 50; PyramidR[1][2] = 150 + 300; PyramidR[1][3] = 1;//a2
		PyramidR[2][0] = 400 - 50; PyramidR[2][1] = 300 - 50; PyramidR[2][2] = 100 + 300; PyramidR[2][3] = 1;//a3
		PyramidR[3][0] = 500 - 50; PyramidR[3][1] = 100 - 50; PyramidR[3][2] = 125 + 300; PyramidR[3][3] = 1;//a4
	};

	float sizeUP = 1.5;
	float sizeDOWN = 1 / 1.5;

	int RGBA[4][4] = {
		{255, 255, 0, 255},
		{0, 255, 255, 255},
		{255, 0, 255, 255 },
		{0, 0, 255, 255}
	};

	void Draw();
	void DrawFigure();

	void Shadow(SDL_Renderer*);
	float** Find_the_int_point(float**);

	void TheArtistAlgorithm(SDL_Renderer*, float**);

	void spinContCloc(char);
	void spinCloc(char);
	void move(float**, char, float);
	void Size(float);

	void Line_by_line(SDL_Renderer*,float[9], int[4]);
	void Shading(SDL_Renderer*, float, float, float[3], float[3], float[3], float[3], int [4]);
	float ReturnX(float, float, float, float, float);

	void bresline(SDL_Renderer*, float, float, float, float);

	float** multiplication(float **, float [4][4]);

	float* Center(float**);

	float** Isometric_rearrangement(float**);
};