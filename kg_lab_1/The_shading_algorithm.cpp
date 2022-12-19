#include "Draw_figure.h"

void Draw_figure::Line_by_line(SDL_Renderer* ren, float A[9], int RGBA[4]) {
	float a[3][3] = {{ A[0], A[1], A[2] },
		{ A[3], A[4], A[5] },
		{ A[6], A[7], A[8] }};
	float* ptr[3];
	ptr[0] = a[0]; ptr[1] = a[1]; ptr[2] = a[2];

	for (int i = 0; i < 2; i++) {
		if (ptr[i][1] > ptr[i + 1][1]) {
			float* temp = ptr[i];
			ptr[i] = ptr[i + 1];
			ptr[i + 1] = temp;
			i = -1;
		}
	}

	float y_min = ptr[0][1];
	float y_sr = ptr[1][1];
	float y_max = ptr[2][1];

	Shading(ren, y_min, y_sr, ptr[0], ptr[1], ptr[0], ptr[2], RGBA);
	Shading(ren, y_sr, y_max, ptr[1], ptr[2], ptr[0], ptr[2], RGBA);
}

void Draw_figure::Shading(SDL_Renderer* ren, float ymin, float ymax, float a1[3], float a2[3], float a3[3], float a4[3], int RGBA[4]) {
	for (int i = ymin; i < ymax; i++) {
		//x = A.x+(y-A.y)*(B.x-A.x)/(B.y-A.y)
		float x1 = ReturnX(a1[0], a1[1], a2[0], a2[1], i);
		float x2 = ReturnX(a3[0], a3[1], a4[0], a4[1], i);
		SDL_SetRenderDrawColor(ren, RGBA[0], RGBA[1], RGBA[2], RGBA[3]);
		bresline(ren, x1, i, x2, i);
	}
}

float Draw_figure::ReturnX(float Ax, float Ay, float Bx, float By, float y) {
	//x = A.x+(y-A.y)*(B.x-A.x)/(B.y-A.y)
	return Ax + (y - Ay) * (Bx - Ax) / (By - Ay);
}