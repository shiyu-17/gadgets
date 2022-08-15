#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define SNAKE_NUM 500//�ߵ�������
int dead = 1;
int ifpb=0;
int nspb = 0;//��¼��
int nfpb = 0;//��¼ʳ��
enum DIR{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};//��ʾ�ߵķ���
struct Snake{
	int size;//�ߵĳ���
	int dir;//�ߵķ���
	int speed;//�ߵ��ٶ�
	int scolor;
	int grade;
	POINT coor[SNAKE_NUM];//����
}snake;//�ߵĽṹ
struct FOOD{
	int x;
	int y;
	int r;//�뾶
	bool flag;
	int  color;//ʳ�����ɫ
}food;//ʳ��ṹ
struct play{
	int pdir[200];
	int pscolor[200];
	POINT pscoor[200];
	int pfcolor[200];
	POINT pfcoor[200];
}pb;//�طŽṹ
void snakeinit(){
	initgraph(640, 480);// graph ͼ�δ���
	srand(GetTickCount());//������������ӣ���ʱ��  GetTickCount()��ȡϵͳ�ӿ����������ڵĺ�����
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
	food.y = pb.pfcoor[nfpb].y;//��ʼʳ��
	food.color = pb.pfcolor[nfpb];
	nfpb++;
	food.r = 8;
	food.flag = true;
}
void foodinit(){
	if(ifpb){ 
		foodinit2();}
	else{
		food.x = rand() % 640;//�����
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
//��ͼ
void GameDraw(){
	BeginBatchDraw();//˫�����ͼ
	setbkcolor(RGB(255,250,240));//���ñ�����ɫ
	cleardevice();//��ջ�ͼ�豸
	//������
	setfillcolor(snake.scolor);//����ɫ
	for (int i = 0; i < snake.size; i++){
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//����ʳ��
	if (food.flag){
		setfillcolor(food.color);
		solidcircle(food.x, food.y, food.r);
	}
	EndBatchDraw();
}
//���ƶ�
void SnakeMove(){
	for (int i = snake.size - 1; i > 0; i--){
		snake.coor[i] = snake.coor[i - 1];//�������ͷ�ƶ�
	}
	switch (snake.dir){
	case UP:
		snake.coor[0].y -= snake.speed;//ͷ�ƶ�
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
//��������
void keyControl(){
	if (_kbhit()){//�ж���û�а���������У��ͷ�����
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
	outtextxy(570,20, "�ɼ���");//define  ����������ָ��λ������ַ�����
	outtextxy(590, 40, eatgrade);
}
void snakeFinish(){
	for (int i = snake.size - 1; i > 0; i--){
		if (snake.coor[i].x == snake.coor[0].x&& snake.coor[i].y == snake.coor[0].y){
			dead = 0;
		}
	}
}
//�ط�
void playback(){
	nspb = 0;
	nfpb = 0;
	ifpb = 1;
	snakeinit();//��ʼ��
	foodinit();
	dead = 1;
	while (dead){
		outtextxy(320, 20, "�ط���");
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
	HWND hnd = GetHWnd();//��ȡ���ھ��
	int judge = MessageBox(hnd, "�Ƿ�ط�", "��Ϸ����", MB_OKCANCEL);
	if (judge == IDOK) {
		playback();
	}
	return 0;
}