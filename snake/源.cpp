#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define SNAKE_NUM 500//蛇的最大节数
int dead = 1;
int ifpb=0;
int nspb = 0;//记录蛇
int nfpb = 0;//记录食物
enum DIR{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};//表示蛇的方向
struct Snake{
	int size;//蛇的长度
	int dir;//蛇的方向
	int speed;//蛇的速度
	int scolor;
	int grade;
	POINT coor[SNAKE_NUM];//坐标
}snake;//蛇的结构
struct FOOD{
	int x;
	int y;
	int r;//半径
	bool flag;
	int  color;//食物的颜色
}food;//食物结构
struct play{
	int pdir[200];
	int pscolor[200];
	POINT pscoor[200];
	int pfcolor[200];
	POINT pfcoor[200];
}pb;//回放结构
void snakeinit(){
	initgraph(640, 480);// graph 图形窗口
	srand(GetTickCount());//设置随机数种子，以时间  GetTickCount()获取系统从开机，到现在的毫秒数
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	snake.scolor = (BLUE);
	snake.grade = 0;
	for (int i = 0; i < snake.size; i++){
		snake.coor[i].x = 40 - 10 * i;
		snake.coor[i].y = 10;
	}
}
void foodinit2(){
	food.x = pb.pfcoor[nfpb].x;
	food.y = pb.pfcoor[nfpb].y;//初始食物
	food.color = pb.pfcolor[nfpb];
	nfpb++;
	food.r = 8;
	food.flag = true;
}
void foodinit(){
	if(ifpb){ 
		foodinit2();}
	else{
		food.x = rand() % 640;//随机数
		food.y = rand() % 480;
		pb.pfcoor[nfpb].x = food.x;
		pb.pfcoor[nfpb].y = food.y;
		switch (rand() % 2){
		case 1:
			food.color = (RED);
			pb.pfcolor[nfpb] = (RED);
			break;
		case 2:
			food.color = (BLUE);
			pb.pfcolor[nfpb] = (BLUE);
			break;
		default:
			food.color = (GREEN);
			pb.pfcolor[nfpb] = (GREEN);
		}
		food.r = 8;
		food.flag = true;
		nfpb++;
	}
}
//画图
void GameDraw(){
	BeginBatchDraw();//双缓冲绘图
	setbkcolor(RGB(255,250,240));//设置背景颜色
	cleardevice();//清空绘图设备
	//绘制蛇
	setfillcolor(snake.scolor);//蛇颜色
	for (int i = 0; i < snake.size; i++){
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//绘制食物
	if (food.flag){
		setfillcolor(food.color);
		solidcircle(food.x, food.y, food.r);
	}
	EndBatchDraw();
}
//蛇移动
void SnakeMove(){
	for (int i = snake.size - 1; i > 0; i--){
		snake.coor[i] = snake.coor[i - 1];//让身体跟头移动
	}
	switch (snake.dir){
	case UP:
		snake.coor[0].y -= snake.speed;//头移动
		if (snake.coor[0].y <= 0){
			snake.coor[0].y = 480;
		}
		break;
	case DOWN:
		snake.coor[0].y += snake.speed;
		if (snake.coor[0].y + 5 >= 480){
			snake.coor[0].y = 0;
		}
		break;
	case LEFT:
		snake.coor[0].x -= snake.speed;
		if (snake.coor[0].x <= 0){
			snake.coor[0].x = 640;
		}
		break;
	case RIGHT:
		snake.coor[0].x += snake.speed;
		if (snake.coor[0].x >= 640){
			snake.coor[0].x = 0;
		}
		break;
	}
}
//按键控制
void keyControl(){
	if (_kbhit()){//判断有没有按键，如果有，就返回真
		switch (_getch()){
		case 'w':case 'W':case 72:
			if (snake.dir != DOWN){
				snake.dir = UP;
				pb.pdir[nspb] = snake.dir;
				pb.pscoor[nspb] = snake.coor[0];
				nspb++;
			}
			break;
		case 's':case 'S':case 80:
			if (snake.dir != UP){
				snake.dir = DOWN;
				pb.pdir[nspb] = snake.dir;
				pb.pscoor[nspb] = snake.coor[0];
				nspb++;
			}
			break;
		case 'a':case 'A':case 75:
			if (snake.dir != RIGHT){
				snake.dir = LEFT;
				pb.pdir[nspb] = snake.dir;
				pb.pscoor[nspb] = snake.coor[0];
				nspb++;
			}
			break;
		case 'd':case 'D':case 77:
			if (snake.dir != LEFT){
				snake.dir = RIGHT;
				pb.pdir[nspb] = snake.dir;
				pb.pscoor[nspb] = snake.coor[0];
				nspb++;
			}
			break;
		}
	}
}
void keyControl2(){
	if (snake.coor[0].x == pb.pscoor[nspb].x && snake.coor[0].y == pb.pscoor[nspb].y){
		snake.dir = pb.pdir[nspb];
		nspb++;
	}
};
void eatFood(){
	if (snake.coor[0].x >= food.x - food.r && snake.coor[0].x <= food.x + food.r && snake.coor[0].y <= food.y + food.r
		&& snake.coor[0].y >= food.y - food.r && food.flag){
		food.flag = false;
		snake.size++;
		snake.grade += 10;
		snake.scolor = food.color;
	}
	if (food.flag == false){
		foodinit();
	}
}
void showGrade(){
	char eatgrade[100] = "";
	sprintf_s(eatgrade, "%d", snake.grade);
	setbkmode(TRANSPARENT);
	settextcolor(LIGHTBLUE);
	outtextxy(570,20, "成绩：");//define  函数用于在指定位置输出字符串。
	outtextxy(590, 40, eatgrade);
}
void snakeFinish(){
	for (int i = snake.size - 1; i > 0; i--){
		if (snake.coor[i].x == snake.coor[0].x&& snake.coor[i].y == snake.coor[0].y){
			dead = 0;
		}
	}
}
//回放
void playback(){
	nspb = 0;
	nfpb = 0;
	ifpb = 1;
	snakeinit();//初始蛇
	foodinit();
	dead = 1;
	while (dead){
		outtextxy(320, 20, "回放中");
		SnakeMove();
		snakeFinish();
		GameDraw();
		keyControl2();
		eatFood();
		showGrade();
		Sleep(100);
	}
}
int main(){
	snakeinit();
	foodinit();
	while (dead){
		SnakeMove();
		snakeFinish();
		GameDraw();
		keyControl();
		eatFood();
		showGrade();
		Sleep(100);
	}
	HWND hnd = GetHWnd();//获取窗口句柄
	int judge = MessageBox(hnd, "是否回放", "游戏结束", MB_OKCANCEL);
	if (judge == IDOK) {
		playback();
	}
	return 0;
}