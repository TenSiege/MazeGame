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
 *函数功能：绘制地图
 *
 *@char wall 代表墙的字符
 *
 */
void Maze::DrawMap()
{
	//以循环绘制出地图
	for (size_t i = 0; i < 12; i++)
	{

		for (size_t j = 0; j < 12; j++)
		{
			//打印地图
			cout << map[i][j];
		}
		//换行
		cout << endl;
	}

}

bool Maze::CheckUpCoor(Coordinate coor)
{
	return false;
}

/*
	函数功能：找出迷宫出口的坐标

*/
void Maze::Map_Start_Destination()
{
	int count=0;
	Coordinate coor[2];
	//检查上边有没有出口,从左到右
	for (size_t i = 0; i < ROW; i++)
	{
		if (this->map[0][i] == this->wool)
		{			
			cout << "找到出口了， 坐标为：" << 0 << "," << i << endl;
			coor[count].x = 0;
			coor[count++].y = i;

		}
	}
	
	//检查右边有没有出口,从上到下
	for (size_t i = 0; i < COL; i++)
	{
		if (this->map[i][11] == this->wool)
		{
			cout << "找到出口了， 坐标为：" << i << "," << 11 << endl;
			coor[count].x = i;
			coor[count++].y = 11;

		}
	}

	//检查下边有没有出口,从左到右
	for (size_t i = 0; i < ROW; i++)
	{
		if (this->map[11][i] == this->wool)
		{
			cout << "找到出口了， 坐标为：" << 11 << "," << i << endl;
			coor[count].x = 11;
			coor[count++].y = i;

		}
	}

	//检查左边有没有出口,从上到下
	for (size_t i = 0; i < COL; i++)
	{
		if (this->map[i][0] == this->wool)
		{
			cout << "找到出口了， 坐标为：" << i << "," << 0 << endl;
			coor[count].x = i;
			coor[count++].y = 0;

		}
	}
	/*for (size_t i = 0; i < count; i++)
	{		
		cout << "[" << (coor+i)->x << "," << (coor+i)->y << "]";
	}*/
	//设置终点和起点的坐标,如果有迷宫有多个出口,则需要把终点结构体变量改为集合存储多个出口坐标
	this->start.x = coor->x;
	this->start.y = coor->y;
	this->destination.x = (coor + 1)->x;
	this->destination.y = (coor + 1)->y;
}

char **Maze::GetMap()
{
	//返回当前数组地址
	char **map = NULL;
	map = (char **)this->map;
	return  map;
}

/*

	arrays 地图数组
*/
void Maze::SetMapl(char arrays[12][12])
{
	for (size_t i = 0; i < this->ROW; i++)
	{
		for (size_t j = 0; j < this->COL; j++)
		{
			//1代表墙,0代表路
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
