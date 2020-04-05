#include<Bangtal.h>
#pragma comment(lib, "Bangtal.lib")
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
SceneID  scene1, scene2;
ObjectID board[3][3];
ObjectID start, p11, p12, p13, p21, p22, p23, p31, p32, blank, restart, giveup;


ObjectID createObject(const char* name, const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(name, image);
	locateObject(object, scene, x, y);
	if (shown) {
		showObject(object);
	}
	return object;
}

int boardX[3] = {
	304, 524, 744
};

int boardY[3] = {
	480, 260, 40
};



void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	int t;
	if (object == start) {
		enterScene(scene2);
	}
	if (object == giveup) {
		hideObject(giveup);
		showObject(restart);

	}


	if (object == restart) {
		enterScene(scene1);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {


			if (object == board[i][j]) {
				if (i == 0 && j == 0) {
					if (board[i][j + 1] == blank) {

						locateObject(object, scene2, boardX[j] + 220, boardY[i]);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i][j + 1];
						board[i][j + 1] = t;


					}
					else if (board[i + 1][j] == blank) {

						locateObject(object, scene2, boardX[j], boardY[i] - 220);

						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i + 1][j];
						board[i + 1][j] = t;
					}
				}
				else if (i == 0 && j == 1) {
					if (board[i][j - 1] == blank) {

						locateObject(object, scene2, boardX[j] - 220, boardY[i]);

						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i][j - 1];
						board[i][j - 1] = t;
					}
					else if (board[i][j + 1] == blank) {

						locateObject(object, scene2, boardX[j] + 220, boardY[i]);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i][j + 1];
						board[i][j + 1] = t;
					}
					else if (board[i + 1][j] == blank) {

						locateObject(object, scene2, boardX[j], boardY[i] - 220);

						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i + 1][j];
						board[i + 1][j] = t;

					}
				}
				else if (i == 0 && j == 2) {
					if (board[i][j - 1] == blank) {

						locateObject(object, scene2, boardX[j] - 220, boardY[i]);

						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i][j - 1];
						board[i][j - 1] = t;
					}

					else if (board[i + 1][j] == blank) {

						locateObject(object, scene2, boardX[j], boardY[i] - 220);

						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i + 1][j];
						board[i + 1][j] = t;
					}

				}
				else if (i == 1 && j == 0) {
					if (board[i - 1][j] == blank) {
						locateObject(object, scene2, boardX[j], boardY[i] + 220);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i - 1][j];
						board[i - 1][j] = t;
					}
					else if (board[i][j + 1] == blank) {
						locateObject(object, scene2, boardX[j] + 220, boardY[i]);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i][j + 1];
						board[i][j + 1] = t;
					}
					else if (board[i + 1][j] == blank) {
						locateObject(object, scene2, boardX[j], boardY[i] - 220);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i][j + 1];
						board[i][j + 1] = t;
					}
				}
				else if (i == 1 && j == 1) {
					if (board[i - 1][j] == blank) {
						locateObject(object, scene2, boardX[j], boardY[i] + 220);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i - 1][j];
						board[i - 1][j] = t;
					}
					else if (board[i][j + 1] == blank) {
						locateObject(object, scene2, boardX[j] + 220, boardY[i]);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i][j + 1];
						board[i][j + 1] = t;
					}
					else if (board[i + 1][j] == blank) {
						locateObject(object, scene2, boardX[j], boardY[i] - 220);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i + 1][j];
						board[i + 1][j] = t;
					}
					else if (board[i][j - 1] == blank) {
						locateObject(object, scene2, boardX[j] - 220, boardY[i]);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i][j - 1];
						board[i][j - 1] = t;
					}
				}
				else if (i == 1 && j == 2) {
					if (board[i - 1][j] == blank) {
						locateObject(object, scene2, boardX[j], boardY[i] + 220);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i - 1][j];
						board[i - 1][j] = t;
					}
					else if (board[i + 1][j] == blank) {
						locateObject(object, scene2, boardX[j], boardY[i] - 220);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i + 1][j];
						board[i + 1][j] = t;
					}
					else if (board[i][j - 1] == blank) {
						locateObject(object, scene2, boardX[j] - 220, boardY[i]);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i][j - 1];
						board[i][j - 1] = t;
					}
					else if (i == 2 && j == 0) {
						if (board[i - 1][j] == blank) {
							locateObject(object, scene2, boardX[j], boardY[i] + 220);
							locateObject(blank, scene2, boardX[j], boardY[i]);
							t = board[i][j];
							board[i][j] = board[i - 1][j];
							board[i - 1][j] = t;
						}
						else if (board[i][j + 1] == blank) {
							locateObject(object, scene2, boardX[j] + 220, boardY[i]);
							locateObject(blank, scene2, boardX[j], boardY[i]);
							t = board[i][j];
							board[i][j] = board[i][j + 1];
							board[i][j + 1] = t;
						}
					}
					else if (i == 2 && j == 1) {
						if (board[i - 1][j] == blank) {

							locateObject(object, scene2, boardX[j], boardY[i] + 220);

							locateObject(blank, scene2, boardX[j], boardY[i]);
							t = board[i][j];
							board[i][j] = board[i - 1][j];
							board[i - 1][j] = t;

						}
						else if (board[i][j + 1] == blank) {

							locateObject(blank, scene2, boardX[j] + 220, boardY[i]);

							locateObject(object, scene2, boardX[j], boardY[i]);
							t = board[i][j];
							board[i][j] = board[i][j + 1];
							board[i][j + 1] = t;


						}
						else if (board[i][j - 1] == blank) {

							locateObject(object, scene2, boardX[j] - 220, boardY[i]);

							locateObject(blank, scene2, boardX[j], boardY[i]);
							t = board[i][j];
							board[i][j] = board[i][j - 1];
							board[i][j - 1] = t;
						}
					}
					else if (i == 2 && j == 2) {
						if (board[i - 1][j] == blank) {

							locateObject(object, scene2, boardX[j], boardY[i] + 220);

							locateObject(blank, scene2, boardX[j], boardY[i]);

							t = board[i][j];
							board[i][j] = board[i - 1][j];
							board[i - 1][j] = t;
						}
						else if (board[i][j - 1] == blank) {

							locateObject(object, scene2, boardX[j] - 220, boardY[i]);

							locateObject(blank, scene2, boardX[j], boardY[i]);
							t = board[i][j];
							board[i][j] = board[i][j - 1];
							board[i][j - 1] = t;
						}
					}

				}
			}
		}
	}
}


int main() {


	scene1 = createScene("3x3퍼즐", "background.png");
	scene2 = createScene("3x3퍼즐", "산타2.png");

	start = createObject("start", "start.png", scene1, 590, 70, true);

	p11 = createObject("p11", "그림1.png", scene2, 304, 480, true);
	board[0][0] = p11;
	p12 = createObject("p12", "그림4.png", scene2, 524, 480, true);
	board[0][1] = p12;
	p13 = createObject("p13", "그림7.png", scene2, 744, 480, true);
	board[0][2] = p13;
	p21 = createObject("p21", "그림2.png", scene2, 304, 260, true);
	board[1][0] = p21;
	p22 = createObject("p22", "그림5.png", scene2, 524, 260, true);
	board[1][1] = p22;
	p23 = createObject("p23", "그림8.png", scene2, 744, 260, true);
	board[1][2] = p23;
	p31 = createObject("p31", "그림3.png", scene2, 304, 40, true);
	board[2][0] = p31;
	p32 = createObject("p32", "그림6.png", scene2, 524, 40, true);
	board[2][1] = p32;
	blank = createObject("blank", "그림10.png", scene2, 744, 40, true);
	board[2][2] = blank;

	scaleObject(p11, 1.3f);
	scaleObject(p12, 1.3f);
	scaleObject(p13, 1.3f);
	scaleObject(p21, 1.3f);
	scaleObject(p22, 1.3f);
	scaleObject(p23, 1.3f);
	scaleObject(p31, 1.3f);
	scaleObject(p32, 1.3f);
	scaleObject(blank, 0.63f);

	restart = createObject("restart", "restart.png", scene2, 200, 40, false);
	giveup = createObject("give up", "giveup.png", scene2, 180, 40, true);
	scaleObject(giveup, 0.2f);


	setMouseCallback(mouseCallback);


	startGame(scene1);

}
