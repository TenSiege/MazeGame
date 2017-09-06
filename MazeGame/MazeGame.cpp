// MazeGame.cpp: 定义控制台应用程序的入口点。
//
#pragma once
#include "stdafx.h"
#include "Public.h"


int main()
{
	//迷宫类对象
	Maze *maze = new Maze();
	//定义地图
	char map[12][12] ={ 
						{ WALL,WALL, WALL, WALL, WALL,WALL, WALL, WALL, WALL,WALL, WALL, WALL }, //1
						{ WALL,WOOL, WALL, WALL, WALL,WALL, WALL, WALL, WALL,WALL, WALL, WALL }, //2
						{ WALL,WOOL, WALL, WALL, WALL,WOOL, WOOL, WOOL, WALL,WALL, WALL, WALL }, //3
						{ WALL,WOOL, WALL, WALL, WOOL,WOOL, WALL, WOOL, WOOL,WOOL, WOOL, WOOL }, //4
						{ WALL,WOOL, WALL, WALL, WOOL,WALL, WALL, WALL, WALL,WALL, WALL, WALL }, //5
						{ WALL,WOOL, WOOL, WALL, WOOL,WALL, WALL, WALL, WALL,WOOL, WALL, WALL }, //6
						{ WALL,WALL, WOOL, WALL, WOOL,WALL, WALL, WALL, WALL,WOOL, WALL, WALL }, //7
						{ WALL,WALL, WOOL, WALL, WOOL,WALL, WALL, WALL, WALL,WOOL, WALL, WALL }, //8
						{ WALL,WALL, WOOL, WOOL, WOOL,WOOL, WOOL, WOOL, WOOL,WOOL, WALL, WALL }, //9
						{ WALL,WOOL, WOOL, WALL, WALL,WALL, WALL, WALL, WOOL,WOOL, WALL, WALL }, //10
						{ WALL,WOOL, WALL, WALL, WALL,WALL, WALL, WALL, WALL,WALL, WALL, WALL }, //11
						{ WALL,WOOL, WALL, WALL, WALL,WALL, WALL, WALL, WALL,WALL, WALL, WALL }  //12
					  };

	//将地图赋值给地图数组
	maze->SetMapl(map);
	//绘制迷宫地图
	maze->DrawMap();
	//读取迷宫出入口坐标
	maze->Map_Start_Destination();
	//人类对象
	MazePerson *person = new MazePerson();
	//起点坐标
	person->SetCuurentCoord(maze->start);
	//上一个位置的坐标
	person->SetBeforeCoord(maze->start);
	//代表人的字符
	person->SetPerson('O');
	//人的朝向
	person->SetDirection(Direction::left);
	//人物的行走速度
	person->SetVelocity(Velocity::fast);//快速的
	//绘制人物
	person->Animation(person->GetCuurentCoord(),person->GetBeforeCoord());
	//启动摸墙算法，控制人物行走，直达到达出口 ->>
	person->Start(*maze);


	//暂停
	string isExit;
	cin >> isExit;

    return 0;
}

