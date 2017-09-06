#pragma once
#ifndef Public_H_
#define Public_H_

/*
 *һЩ�������Զ�����������
 */

//�����ߵ��ٶ�ö��
extern enum Velocity
{
	fast,//���ٵ�
	horotelic,//���ٵ�
	SLOW//���ٵ�
};
//����ö��
extern enum Direction
{
	top,
	buttom,
	left,
	right
};
//�������ͽṹ�壬x = ��,y = ��
extern struct Coordinate
{
	int x;
	int y;
	bool operator==(const Coordinate& rhs) // �������������  
	{
		return(x == rhs.x) && (y == rhs.y);

	}
};

const char WALL = '1';    //ǽ���ַ�
const char WOOL = '0';	  //ͨ·�ַ�
#endif //Public_H_