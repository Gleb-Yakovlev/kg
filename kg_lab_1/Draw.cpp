#include "Draw_figure.h"

void Draw_figure::Draw() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
	}
	else
	{
		cout << "SDL initialization succeeded!" << endl;
	}

	PyramidL = Isometric_rearrangement(PyramidL);
	PyramidR = Isometric_rearrangement(PyramidR);

	char order = ' ';
	while (1) {
		cout << "pyramidL:" << endl;
		for (int i = 0; i < 4;i++) {
			cout << PyramidL[i][0] << " " << PyramidL[i][1] << " " << PyramidL[i][2] << " " << PyramidL[i][3] << endl;
		}
		cout << "pyramidR:" << endl;
		for (int i = 0; i < 4;i++) {
			cout << PyramidR[i][0] << " " << PyramidR[i][1] << " " << PyramidR[i][2] << " " << PyramidR[i][3] << endl;
		}
		cout << endl;
		DrawFigure();

		cout << "w, s, d, a, e, q +, -, >, <, r, f, y, t, 0" << endl;
		cin >> order;
		switch (order)
		{
		case 's': {move(PyramidL, order, 50); move(PyramidR, order, 50); break;}
		case 'a': {move(PyramidL, order, 50); move(PyramidR, order, 50); break;}
		case 'w': {move(PyramidL, order, 50); move(PyramidR, order, 50); break;}
		case 'd': {move(PyramidL, order, 50); move(PyramidR, order, 50); break;}
		case 'e': {move(PyramidL, order, 50); move(PyramidR, order, 50); break;}
		case 'q': {move(PyramidL, order, 50); move(PyramidR, order, 50); break;}
		case '+': {Size(sizeUP); break;}
		case '-': {Size(sizeDOWN); break;}
		case '>': {spinCloc('y'); break;}
		case '<': {spinContCloc('y'); break;}
		case 'r': {spinCloc('x'); break;}
		case 'f': {spinContCloc('x'); break;}
		case 'y': {spinCloc('z'); break;}
		case 't': {spinContCloc('z'); break;}
		case '0': return;
		}


	}
}