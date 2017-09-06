#pragma once
#include "stdafx.h"
#include "Public.h"
//迷宫类
class Maze
{
public:

	/***************************成员函数**************************/
	//迷宫类的构造以及析构函数
	Maze();
	~Maze();

	//绘制迷宫地图
	void DrawMap();
	//迷宫边界检查函数，判断人类传来的即将下一步走的坐标是否合法
	bool CheckUpCoor(Coordinate coor);
	//读取地图的起点和出口坐标
	void Map_Start_Destination();
	//数据封装函数
	char **GetMap();
	void SetMapl(char arrays[12][12]);

	/**********************************成员函数*******************************************/

	//起点坐标
	Coordinate start;
	//终点坐标
	Coordinate destination;
	//墙壁字符
	char wall='*';
	//通路字符
	char wool=' ';
	//二维数组的行和列
	static const int ROW = 12;
	static const int COL = 12;
	//迷宫地图二维数组  1 = 墙  0 = 路
	char map[ROW][COL];
};

