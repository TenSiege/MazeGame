#pragma once
#include "MazePerson.h"
#include "stdafx.h"

/*******************��������������Լ����캯��***********************/
MazePerson::MazePerson()
{
}


MazePerson::~MazePerson()
{
}


/**************************��ͬ�������ߵĺ���*************************************/

/*���ϱ�����*/
void MazePerson::GotoTop()
{
	this->beforeCoord = this->cuurentCoord;
	this->cuurentCoord.x--;

}

/*���ұ�����*/
void MazePerson::GotoRight()
{
	this->beforeCoord = this->cuurentCoord;
	this->cuurentCoord.y++;
}

/*���±�����*/
void MazePerson::GotoButtom()
{
	this->beforeCoord = this->cuurentCoord;
	this->cuurentCoord.x++;
}
/*���������*/
void MazePerson::GotoLeft()
{
	this->beforeCoord = this->cuurentCoord;
	this->cuurentCoord.y--;
}

/*
	�������ܣ������۷����ϵ�ǰ����һ��
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
	�������ܣ�����ת��
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
�������ܣ�����ת��
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


/*�������ܣ�ʵ����������ʱ�Ķ���Ч��
 * cuurentCoord   ���ﵱǰλ��
 * beforeCoord    �������һ��λ��
 */
void MazePerson::Animation(Coordinate cuurentCoord,Coordinate beforeCoord)
{
	//��λ�������
	this->Gotoxy(this->cuurentCoord);
	//��������
	char person = this->person;
	cout << person;

	//�����һ�����������,���������ͬ�������
	if (!(this->cuurentCoord.x == this->beforeCoord.x && this->cuurentCoord.y == this->beforeCoord.y))
	{

		//��λ�������
		this->Gotoxy(this->beforeCoord);
		//�������,�Կո��滻
		cout << ' ';
	}

	//���ݲ�ͬ���ƶ��ٶȵ�ö�����ӳ�
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
 �������ƣ�gotoxy
 �������ܣ�ȷ������̨���ַ������λ��,�������뽹���ƶ���ָ��������λ����
 �����б�
			x��������
			y��������
*/
void MazePerson::Gotoxy(Coordinate xy)
{
	COORD cd;
	cd.X = xy.y;
	cd.Y = xy.x;
	//cout << "[" << xy.x << "," << xy.y << "]";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
};


/*****************************���ݳ�Ա�ķ�װ����**************************************/

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
 *  �������ܣ�������ǽ�㷨���������￪ʼ�߶�
 *	�����б�maze = �Թ������
 *
 */
void MazePerson::Start(Maze maze)
{
	//�Ƿ񵽴����
	while (!(this->cuurentCoord.x == maze.destination.x && this->cuurentCoord.y == maze.destination.y))
	{
		//�����н�����Ĳ�ִͬ�в�ͬ���ж����
		switch (this->direction)
		{		
			//****************************�͹�������ʱ*****************************************
		case Direction::top:
			//�ж�����Ƿ����ϰ�
			if (maze.map[cuurentCoord.x][cuurentCoord.y -1] == maze.wall || (cuurentCoord.x == beforeCoord.x && cuurentCoord.y -1 == beforeCoord.y))
			{
				//�ж�ǰ���Ƿ����ϰ�
				if (maze.map[cuurentCoord.x - 1][cuurentCoord.y] == maze.wall)
				{
					//��ת90��
					TurnRight();

				}
				else
				{
					//ǰ��
					GoAheadOne();
				}
			}
			else
			{
				//��ת90��
				TurnLeft();
			}
			break;

			//****************************�͹�������ʱ*****************************************
		case Direction::right:
			//�ж�����Ƿ����ϰ�
			if (maze.map[cuurentCoord.x -1][cuurentCoord.y] == maze.wall || (cuurentCoord.x - 1 == beforeCoord.x && cuurentCoord.y == beforeCoord.y))
			{
				//�ж�ǰ���Ƿ����ϰ�
				if (maze.map[cuurentCoord.x][cuurentCoord.y +1] == maze.wall)
				{
					//��ת90��
					TurnRight();
				}
				else
				{
					//ǰ��
					GoAheadOne();
				}
			}
			else
			{
				//��ת90��
				TurnLeft();
			}
			break;

			//****************************�͹�������ʱ*****************************************
		case Direction::buttom:
			//�ж�����Ƿ����ϰ�
			if (maze.map[cuurentCoord.x][cuurentCoord.y + 1] == maze.wall || (cuurentCoord.x == beforeCoord.x && cuurentCoord.y + 1 == beforeCoord.y))
			{
				//�ж�ǰ���Ƿ����ϰ�
				if (maze.map[cuurentCoord.x + 1][cuurentCoord.y] == maze.wall)
				{
					//��ת90��
					TurnRight();
				}
				else
				{
					//ǰ��
					GoAheadOne();
				}
			}
			else
			{
				//��ת90��
				TurnLeft();
			}
			break;

			//****************************�͹�������ʱ*****************************************
		case Direction::left:
			//�ж�����Ƿ����ϰ�
			if (maze.map[cuurentCoord.x + 1][cuurentCoord.y] == maze.wall || (cuurentCoord.x +1 == beforeCoord.x && cuurentCoord.y == beforeCoord.y))
			{
				//�ж�ǰ���Ƿ����ϰ�
				if (maze.map[cuurentCoord.x][cuurentCoord.y -1] == maze.wall)
				{
					//��ת90��
					TurnRight();
					//ǰ��
				}
				else
				{
					//ǰ��
					GoAheadOne();
				}
			}
			else
			{
				//��ת90��
				TurnLeft();
			}
			break;
		}

		//�������ﶯ��
		Animation(this->cuurentCoord,this->beforeCoord);
	}

}
