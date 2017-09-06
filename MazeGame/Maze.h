#pragma once
#include "stdafx.h"
#include "Public.h"
//�Թ���
class Maze
{
public:

	/***************************��Ա����**************************/
	//�Թ���Ĺ����Լ���������
	Maze();
	~Maze();

	//�����Թ���ͼ
	void DrawMap();
	//�Թ��߽��麯�����ж����ഫ���ļ�����һ���ߵ������Ƿ�Ϸ�
	bool CheckUpCoor(Coordinate coor);
	//��ȡ��ͼ�����ͳ�������
	void Map_Start_Destination();
	//���ݷ�װ����
	char **GetMap();
	void SetMapl(char arrays[12][12]);

	/**********************************��Ա����*******************************************/

	//�������
	Coordinate start;
	//�յ�����
	Coordinate destination;
	//ǽ���ַ�
	char wall='*';
	//ͨ·�ַ�
	char wool=' ';
	//��ά������к���
	static const int ROW = 12;
	static const int COL = 12;
	//�Թ���ͼ��ά����  1 = ǽ  0 = ·
	char map[ROW][COL];
};

