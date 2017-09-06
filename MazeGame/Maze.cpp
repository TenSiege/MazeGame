#pragma once
#include "Maze.h"
#include "stdafx.h"
Maze::Maze()
{

}


Maze::~Maze()
{

}


/*
 *�������ܣ����Ƶ�ͼ
 *
 *@char wall ����ǽ���ַ�
 *
 */
void Maze::DrawMap()
{
	//��ѭ�����Ƴ���ͼ
	for (size_t i = 0; i < 12; i++)
	{

		for (size_t j = 0; j < 12; j++)
		{
			//��ӡ��ͼ
			cout << map[i][j];
		}
		//����
		cout << endl;
	}

}

bool Maze::CheckUpCoor(Coordinate coor)
{
	return false;
}

/*
	�������ܣ��ҳ��Թ����ڵ�����

*/
void Maze::Map_Start_Destination()
{
	int count=0;
	Coordinate coor[2];
	//����ϱ���û�г���,������
	for (size_t i = 0; i < ROW; i++)
	{
		if (this->map[0][i] == this->wool)
		{			
			cout << "�ҵ������ˣ� ����Ϊ��" << 0 << "," << i << endl;
			coor[count].x = 0;
			coor[count++].y = i;

		}
	}
	
	//����ұ���û�г���,���ϵ���
	for (size_t i = 0; i < COL; i++)
	{
		if (this->map[i][11] == this->wool)
		{
			cout << "�ҵ������ˣ� ����Ϊ��" << i << "," << 11 << endl;
			coor[count].x = i;
			coor[count++].y = 11;

		}
	}

	//����±���û�г���,������
	for (size_t i = 0; i < ROW; i++)
	{
		if (this->map[11][i] == this->wool)
		{
			cout << "�ҵ������ˣ� ����Ϊ��" << 11 << "," << i << endl;
			coor[count].x = 11;
			coor[count++].y = i;

		}
	}

	//��������û�г���,���ϵ���
	for (size_t i = 0; i < COL; i++)
	{
		if (this->map[i][0] == this->wool)
		{
			cout << "�ҵ������ˣ� ����Ϊ��" << i << "," << 0 << endl;
			coor[count].x = i;
			coor[count++].y = 0;

		}
	}
	/*for (size_t i = 0; i < count; i++)
	{		
		cout << "[" << (coor+i)->x << "," << (coor+i)->y << "]";
	}*/
	//�����յ����������,������Թ��ж������,����Ҫ���յ�ṹ�������Ϊ���ϴ洢�����������
	this->start.x = coor->x;
	this->start.y = coor->y;
	this->destination.x = (coor + 1)->x;
	this->destination.y = (coor + 1)->y;
}

char **Maze::GetMap()
{
	//���ص�ǰ�����ַ
	char **map = NULL;
	map = (char **)this->map;
	return  map;
}

/*

	arrays ��ͼ����
*/
void Maze::SetMapl(char arrays[12][12])
{
	for (size_t i = 0; i < this->ROW; i++)
	{
		for (size_t j = 0; j < this->COL; j++)
		{
			//1����ǽ,0����·
			if (arrays[i][j] == WALL)
			{
				this->map[i][j] = this->wall;
			}
			else if(arrays[i][j] == WOOL)
			{
				this->map[i][j] = this->wool;
			}
		}
	}
}
