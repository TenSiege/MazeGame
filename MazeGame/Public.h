#pragma once
#ifndef Public_H_
#define Public_H_

/*
 *一些公共的自定义数据类型
 */

//人行走的速度枚举
extern enum Velocity
{
	fast,//快速的
	horotelic,//中速的
	SLOW//慢速的
};
//方向枚举
extern enum Direction
{
	top,
	buttom,
	left,
	right
};
//坐标类型结构体，x = 横,y = 纵
extern struct Coordinate
{
	int x;
	int y;
	bool operator==(const Coordinate& rhs) // 操作运算符重载  
	{
		return(x == rhs.x) && (y == rhs.y);

	}
};

const char WALL = '1';    //墙壁字符
const char WOOL = '0';	  //通路字符
#endif //Public_H_