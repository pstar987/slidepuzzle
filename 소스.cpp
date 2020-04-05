#include<Bangtal.h>
#pragma comment(lib, "Bangtal.lib")
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

SceneID  scene1, scene2;
ObjectID board[3][3];
ObjectID start, p11, p12, p13, p21, p22, p23, p31, p32, blank, restart, giveup;
TimerID timer1;


ObjectID createObject(const char* name, const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(name, image);
	locateObject(object, scene, x, y);
	if (shown) {
		showObject(object);
	}
	return object;
}

int boardX[3] = {
	305, 525, 745
};

int boardY[3] = {
	480, 260, 40
};


void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	int t;
	int flag=0;
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
		if (flag == 1) {
			break;
		}
		for (int j = 0; j < 3; j++) {


			if (object == board[i][j]) {
				if (p11 == board[0][0] && p12 == board[0][1] && p13 == board[0][2] && p21 == board[1][0] && p22 == board[1][1] && p23 == board[1][2] && p31 == board[2][0] && p32 == board[2][1] && blank == board[2][2]) {
					endGame();
				}
				if (i == 0 && j == 0) {
					if (board[i][j + 1] == blank) {

						locateObject(object, scene2, boardX[j] + 220, boardY[i]);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i][j + 1];
						board[i][j + 1] = t;
						flag = 1;
						break;


					}
					else if (board[i + 1][j] == blank) {

						locateObject(object, scene2, boardX[j], boardY[i] - 220);

						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i + 1][j];
						board[i + 1][j] = t;
						flag = 1;
						break;
					}
				}
				else if (i == 0 && j == 1) {
					if (board[i][j - 1] == blank) {

						locateObject(object, scene2, boardX[j] - 220, boardY[i]);

						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i][j - 1];
						board[i][j - 1] = t;
						flag = 1;
						break;
					}
					else if (board[i][j + 1] == blank) {

						locateObject(object, scene2, boardX[j] + 220, boardY[i]);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i][j + 1];
						board[i][j + 1] = t;
						flag = 1;
						break;
					}
					else if (board[i + 1][j] == blank) {

						locateObject(object, scene2, boardX[j], boardY[i] - 220);

						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i + 1][j];
						board[i + 1][j] = t;
						flag = 1;
						break;

					}
				}
				else if (i == 0 && j == 2) {
					if (board[i][j - 1] == blank) {

						locateObject(object, scene2, boardX[j] - 220, boardY[i]);

						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i][j - 1];
						board[i][j - 1] = t;
						flag = 1;
						break;
					}

					else if (board[i + 1][j] == blank) {

						locateObject(object, scene2, boardX[j], boardY[i] - 220);

						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i + 1][j];
						board[i + 1][j] = t;
						flag = 1;
						break;
					}

				}
				else if (i == 1 && j == 0) {
					if (board[i - 1][j] == blank) {
						locateObject(object, scene2, boardX[j], boardY[i] + 220);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i - 1][j];
						board[i - 1][j] = t;
						flag = 1;
						break;
					}
					else if (board[i][j + 1] == blank) {
						locateObject(object, scene2, boardX[j] + 220, boardY[i]);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i][j + 1];
						board[i][j + 1] = t;
						flag = 1;
						break;
					}
					else if (board[i + 1][j] == blank) {
						locateObject(object, scene2, boardX[j], boardY[i] - 220);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i+1][j];
						board[i+1][j] = t;
						flag = 1;
						break;
					}
				}
				else if (i == 1 && j == 1) {
					if (board[i - 1][j] == blank) {
						locateObject(object, scene2, boardX[j], boardY[i] + 220);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i - 1][j];
						board[i - 1][j] = t;
						flag = 1;
						break;
					}
					else if (board[i][j + 1] == blank) {
						locateObject(object, scene2, boardX[j] + 220, boardY[i]);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i][j + 1];
						board[i][j + 1] = t; 
						flag = 1;
						break;
					}
					else if (board[i + 1][j] == blank) {
						locateObject(object, scene2, boardX[j], boardY[i] - 220);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i + 1][j];
						board[i + 1][j] = t;
						flag = 1;
						break;
					}
					else if (board[i][j - 1] == blank) {
						locateObject(object, scene2, boardX[j] - 220, boardY[i]);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i][j - 1];
						board[i][j - 1] = t;
						flag = 1;
						break;
					}
				}
				else if (i == 1 && j == 2) {
					if (board[i - 1][j] == blank) {
						locateObject(object, scene2, boardX[j], boardY[i] + 220);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i - 1][j];
						board[i - 1][j] = t;
						flag = 1;
						break;
					}
					else if (board[i + 1][j] == blank) {
						locateObject(object, scene2, boardX[j], boardY[i] - 220);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i + 1][j];
						board[i + 1][j] = t;
						flag = 1;
						break;
					
					}
					else if (board[i][j - 1] == blank) {
						locateObject(object, scene2, boardX[j] - 220, boardY[i]);
						locateObject(blank, scene2, boardX[j], boardY[i]);
						t = board[i][j];
						board[i][j] = board[i][j - 1];
						board[i][j - 1] = t;
						flag = 1;
						break;
						
					}
				}
				else if (i == 2 && j == 0) {
						if (board[i - 1][j] == blank) {
							locateObject(object, scene2, boardX[j], boardY[i] + 220);
							locateObject(blank, scene2, boardX[j], boardY[i]);
							t = board[i][j];
							board[i][j] = board[i - 1][j];
							board[i - 1][j] = t;
							flag = 1;
							break;
						
						}
						else if (board[i][j + 1] == blank) {
							locateObject(object, scene2, boardX[j] + 220, boardY[i]);
							locateObject(blank, scene2, boardX[j], boardY[i]);
							t = board[i][j];
							board[i][j] = board[i][j + 1];
							board[i][j + 1] = t;
							flag = 1;
							break;
						
						}
				}
				else if (i == 2 && j == 1) {
						if (board[i - 1][j] == blank) {

							locateObject(object, scene2, boardX[j], boardY[i] + 220);

							locateObject(blank, scene2, boardX[j], boardY[i]);
							t = board[i][j];
							board[i][j] = board[i - 1][j];
							board[i - 1][j] = t;
							flag = 1;
							break;
						
						}
						else if (board[i][j + 1] == blank) {

							locateObject(object, scene2, boardX[j] + 220, boardY[i]);

							locateObject(blank, scene2, boardX[j], boardY[i]);
							t = board[i][j];
							board[i][j] = board[i][j + 1];
							board[i][j + 1] = t;
							flag = 1;
							break;
						

						}
						else if (board[i][j - 1] == blank) {

							locateObject(object, scene2, boardX[j] - 220, boardY[i]);

							locateObject(blank, scene2, boardX[j], boardY[i]);
							t = board[i][j];
							board[i][j] = board[i][j - 1];
							board[i][j - 1] = t;
							flag = 1;
							break;
						
						}
					}
					else if (i == 2 && j == 2) {
						if (board[i - 1][j] == blank) {

							locateObject(object, scene2, boardX[j], boardY[i] + 220);

							locateObject(blank, scene2, boardX[j], boardY[i]);

							t = board[i][j];
							board[i][j] = board[i - 1][j];
							board[i - 1][j] = t;
							flag = 1;
							break;
							
						}
						else if (board[i][j - 1] == blank) {

							locateObject(object, scene2, boardX[j] - 220, boardY[i]);

							locateObject(blank, scene2, boardX[j], boardY[i]);
							t = board[i][j];
							board[i][j] = board[i][j - 1];
							board[i][j - 1] = t;
							flag = 1;
							break;
							
						}
					}

				}
			}
		}
		
	}



int main() {
	


	std::vector<int> v = { 305, 525, 745 };
	std::vector<int> k = { 480, 260, 40 };
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(v.begin(), v.end(), g);
	std::shuffle(k.begin(), k.end(), g);


	scene1 = createScene("3x3퍼즐", "background.png");
	scene2 = createScene("3x3퍼즐", "산타2.png");

	start = createObject("start", "start.png", scene1, 590, 70, true);

	p11 = createObject("p11", "그림1.png", scene2, v[0], k[0], true);
	
	p12 = createObject("p12", "그림4.png", scene2, v[1], k[0], true);
	
	p13 = createObject("p13", "그림7.png", scene2, v[2], k[0], true);
	
	p21 = createObject("p21", "그림2.png", scene2, v[0], k[1], true);
	
	p22 = createObject("p22", "그림5.png", scene2, v[1], k[1], true);
	
	p23 = createObject("p23", "그림8.png", scene2, v[2], k[1], true);
	
	p31 = createObject("p31", "그림3.png", scene2, v[0], k[2], true);
	
	p32 = createObject("p32", "그림6.png", scene2, v[1], k[2], true);
	
	blank = createObject("blank", "그림10.png", scene2, v[2], k[2], true);


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (v[0] == boardX[i] && k[0] == boardY[j]) {
				board[j][i] = p11;
			}
			else if (v[1] == boardX[i] && k[0] == boardY[j]) {
				board[j][i] = p12;
			}
			else if (v[2] == boardX[i] && k[0] == boardY[j]) {
				board[j][i] = p13;
			}
			else if (v[0] == boardX[i] && k[1] == boardY[j]) {
				board[j][i] = p21;
			}
			else if (v[1] == boardX[i] && k[1] == boardY[j]) {
				board[j][i] = p22;
			}
			else if (v[2] == boardX[i] && k[1] == boardY[j]) {
				board[j][i] = p23;
			}
			else if (v[0] == boardX[i] && k[2] == boardY[j]) {
				board[j][i] = p31;
			}
			else if (v[1] == boardX[i] && k[2] == boardY[j]) {
				board[j][i] = p32;
			}
			else if (v[2] == boardX[i] && k[2] == boardY[j]) {
				board[j][i] = blank;
			}

		}
	}



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
	timer1 = createTimer(120.0f);
	showTimer(timer1);

	startGame(scene1);
	

	
}
