#pragma once
#include "MazePerson.h"
#include "stdafx.h"

/*******************人类的析构函数以及构造函数***********************/
MazePerson::MazePerson()
{
}


MazePerson::~MazePerson()
{
}


/**************************向不同方向行走的函数*************************************/

/*向上边行走*/
void MazePerson::GotoTop()
{
	this->beforeCoord = this->cuurentCoord;
	this->cuurentCoord.x--;

}

/*向右边行走*/
void MazePerson::GotoRight()
{
	this->beforeCoord = this->cuurentCoord;
	this->cuurentCoord.y++;
}

/*向下边行走*/
void MazePerson::GotoButtom()
{
	this->beforeCoord = this->cuurentCoord;
	this->cuurentCoord.x++;
}
/*向左边行走*/
void MazePerson::GotoLeft()
{
	this->beforeCoord = this->cuurentCoord;
	this->cuurentCoord.y--;
}

/*
	函数功能：向主观方向上的前方走一步
 */
void MazePerson::GoAheadOne()
{
	switch (this->direction)
	{
	case Direction::top:
		this->GotoTop();
		break;
	case Direction::right:
		this->GotoRight();
		break;
	case Direction::buttom:
		this->GotoButtom();
		break;
	case Direction::left:
		this->GotoLeft();
		break;
	}
}
/*
	函数功能：向右转弯
 */
void MazePerson::TurnRight()
{
	switch (this->direction)
	{
	case Direction::top:
		this->direction = Direction::right;
		break;
	case Direction::right:
		this->direction = Direction::buttom;
		break;
	case Direction::buttom:
		this->direction = Direction::left;
		break;
	case Direction::left:
		this->direction = Direction::top;
		break;
	}
}
/*
函数功能：向左转弯
*/
void MazePerson::TurnLeft()
{
	switch (this->direction)
	{
	case Direction::top:
		this->direction = Direction::left;
		break;
	case Direction::right:
		this->direction = Direction::top;
		break;
	case Direction::buttom:
		this->direction = Direction::right;
		break;
	case Direction::left:
		this->direction = Direction::buttom;
		break;
	}
}


/*函数功能：实现人物行走时的动画效果
 * cuurentCoord   人物当前位置
 * beforeCoord    人物的上一个位置
 */
void MazePerson::Animation(Coordinate cuurentCoord,Coordinate beforeCoord)
{
	//定位输出焦点
	this->Gotoxy(this->cuurentCoord);
	//绘制人物
	char person = this->person;
	cout << person;

	//清楚上一个坐标的人物,如果坐标相同，则不清除
	if (!(this->cuurentCoord.x == this->beforeCoord.x && this->cuurentCoord.y == this->beforeCoord.y))
	{

		//定位输出焦点
		this->Gotoxy(this->beforeCoord);
		//清楚人物,以空格替换
		cout << ' ';
	}

	//根据不同的移动速度的枚举来延迟
	switch (this->velocity)
	{
	case Velocity::fast:
		Sleep(800);
		break;
	case Velocity::horotelic:
		Sleep(2000);
		break;
	case Velocity::SLOW:
		Sleep(3000);
		break;
	}
}

/*
 函数名称：gotoxy
 函数功能：确定控制台中字符的输出位置,即将输入焦点移动到指定的坐标位置上
 函数列表：
			x：横坐标
			y：纵坐标
*/
void MazePerson::Gotoxy(Coordinate xy)
{
	COORD cd;
	cd.X = xy.y;
	cd.Y = xy.x;
	//cout << "[" << xy.x << "," << xy.y << "]";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
};


/*****************************数据成员的封装函数**************************************/

Direction MazePerson::GetDirection()
{
	return this->direction;
;
}

void MazePerson::SetDirection(Direction direction)
{
	this->direction = direction;
}

char MazePerson::GetPerson()
{
	return this->person;
}

void MazePerson::SetPerson(char person)
{
	this->person = person;
}

Coordinate MazePerson::GetCuurentCoord()
{
	return this->cuurentCoord;
}

void MazePerson::SetCuurentCoord(Coordinate coor)
{
	this->cuurentCoord = coor;
}

Coordinate MazePerson::GetBeforeCoord()
{
	return this->beforeCoord;
}

void MazePerson::SetBeforeCoord(Coordinate coor)
{
	this->beforeCoord = coor;
}

Velocity MazePerson::GetVelocity()
{
	return this->velocity;
}

void MazePerson::SetVelocity(Velocity velocity)
{
	this->velocity = velocity;
}

/*
 *  函数功能：启动摸墙算法，控制人物开始走动
 *	参数列表：maze = 迷宫类对象
 *
 */
void MazePerson::Start(Maze maze)
{
	//是否到达出口
	while (!(this->cuurentCoord.x == maze.destination.x && this->cuurentCoord.y == maze.destination.y))
	{
		//根据行进方向的不同执行不同的判断语句
		switch (this->direction)
		{		
			//****************************客观向上走时*****************************************
		case Direction::top:
			//判断左侧是否有障碍
			if (maze.map[cuurentCoord.x][cuurentCoord.y -1] == maze.wall || (cuurentCoord.x == beforeCoord.x && cuurentCoord.y -1 == beforeCoord.y))
			{
				//判断前方是否有障碍
				if (maze.map[cuurentCoord.x - 1][cuurentCoord.y] == maze.wall)
				{
					//右转90度
					TurnRight();

				}
				else
				{
					//前进
					GoAheadOne();
				}
			}
			else
			{
				//左转90度
				TurnLeft();
			}
			break;

			//****************************客观向右走时*****************************************
		case Direction::right:
			//判断左侧是否有障碍
			if (maze.map[cuurentCoord.x -1][cuurentCoord.y] == maze.wall || (cuurentCoord.x - 1 == beforeCoord.x && cuurentCoord.y == beforeCoord.y))
			{
				//判断前方是否有障碍
				if (maze.map[cuurentCoord.x][cuurentCoord.y +1] == maze.wall)
				{
					//右转90度
					TurnRight();
				}
				else
				{
					//前进
					GoAheadOne();
				}
			}
			else
			{
				//左转90度
				TurnLeft();
			}
			break;

			//****************************客观向下走时*****************************************
		case Direction::buttom:
			//判断左侧是否有障碍
			if (maze.map[cuurentCoord.x][cuurentCoord.y + 1] == maze.wall || (cuurentCoord.x == beforeCoord.x && cuurentCoord.y + 1 == beforeCoord.y))
			{
				//判断前方是否有障碍
				if (maze.map[cuurentCoord.x + 1][cuurentCoord.y] == maze.wall)
				{
					//右转90度
					TurnRight();
				}
				else
				{
					//前进
					GoAheadOne();
				}
			}
			else
			{
				//左转90度
				TurnLeft();
			}
			break;

			//****************************客观向左走时*****************************************
		case Direction::left:
			//判断左侧是否有障碍
			if (maze.map[cuurentCoord.x + 1][cuurentCoord.y] == maze.wall || (cuurentCoord.x +1 == beforeCoord.x && cuurentCoord.y == beforeCoord.y))
			{
				//判断前方是否有障碍
				if (maze.map[cuurentCoord.x][cuurentCoord.y -1] == maze.wall)
				{
					//右转90度
					TurnRight();
					//前进
				}
				else
				{
					//前进
					GoAheadOne();
				}
			}
			else
			{
				//左转90度
				TurnLeft();
			}
			break;
		}

		//绘制人物动画
		Animation(this->cuurentCoord,this->beforeCoord);
	}

}
