#include "Draw_figure.h"

void Draw_figure::TheArtistAlgorithm(SDL_Renderer* ren, float** A) {

	float pl[4][9] = { { A[0][0], A[0][1], A[0][2], //a1
		A[1][0], A[1][1], A[1][2], //a2
		A[3][0], A[3][1], A[3][2] }, //a4

		{ A[0][0], A[0][1], A[0][2], //a1
		A[1][0], A[1][1], A[1][2], //a2
		A[2][0], A[2][1], A[2][2] }, // a3

		{ A[0][0], A[0][1], A[0][2], //a1
		A[2][0], A[2][1], A[2][2], //a3
		A[3][0], A[3][1], A[3][2] }, //a4

		{ A[1][0], A[1][1], A[1][2], //a2
		A[2][0], A[2][1], A[2][2], //a3
		A[3][0], A[3][1], A[3][2] } // a4
	};

	float z1 = (A[0][2] + A[1][2] + A[3][2]) / 3;
	float z2 = (A[0][2] + A[1][2] + A[2][2]) / 3;
	float z3 = (A[0][2] + A[2][2] + A[3][2]) / 3;
	float z4 = (A[1][2] + A[2][2] + A[3][2]) / 3;
	float z[4] = { z1, z2, z3, z4 };

	float* ptr[4];
	for (int i = 0; i < 4; i++) ptr[i] = pl[i];

	for (int i = 0; i < 3; i++) {
		if (z[i] > z[i + 1]) {
			float tempz = z[i];
			z[i] = z[i + 1];
			z[i + 1] = tempz;
			float *tempptr = ptr[i];
			ptr[i] = ptr[i+1];
			ptr[i + 1] = tempptr;
			i = -1;
		}
	}

	for (int i = 0; i < 4; i++) { 
		Line_by_line(ren, ptr[i], RGBA[i]);
	}
}