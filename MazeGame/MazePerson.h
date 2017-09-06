#pragma once
#include "stdafx.h"
#include "Public.h"
//走迷宫的人
class MazePerson
{
public:
	MazePerson();
	~MazePerson();
	//上下左右走动的函数
	void GotoTop();
	void GotoRight();
	void GotoButtom();
	void GotoLeft();

	//人走动动画的函数
	void Animation(Coordinate cuurentCoord, Coordinate beforeCoord);

	
	//函数功能：确定控制台中字符的输出位置
	void MazePerson::Gotoxy(Coordinate XY);

	//人物开始运动的函数
	void Start(Maze maze);

	//向主观方向的前走一步
	void GoAheadOne();

	//该变人物逻辑方向的函数
	void TurnRight();    //向右转
	void TurnLeft();	//向左转

	//**********************************数据封装函数***************************
	Direction GetDirection();
	void SetDirection(Direction direction);

	char GetPerson();
	void SetPerson(char person);

	Coordinate GetCuurentCoord();
	void SetCuurentCoord(Coordinate coor);

	Coordinate GetBeforeCoord();
	void SetBeforeCoord(Coordinate coor);

	Velocity GetVelocity();
	void SetVelocity(Velocity velocity);

private://数据成员
	
	Direction direction;		//当前人物的行进方向
	int pace;					//当前以走的步数
	char person;				//代表人物的字符
	Coordinate cuurentCoord;	//当前人物的坐标
	Coordinate beforeCoord;		//上一个位置的坐标
	Velocity velocity;			//行走的速度

};

