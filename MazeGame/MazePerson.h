#pragma once
#include "stdafx.h"
#include "Public.h"
//���Թ�����
class MazePerson
{
public:
	MazePerson();
	~MazePerson();
	//���������߶��ĺ���
	void GotoTop();
	void GotoRight();
	void GotoButtom();
	void GotoLeft();

	//���߶������ĺ���
	void Animation(Coordinate cuurentCoord, Coordinate beforeCoord);

	
	//�������ܣ�ȷ������̨���ַ������λ��
	void MazePerson::Gotoxy(Coordinate XY);

	//���￪ʼ�˶��ĺ���
	void Start(Maze maze);

	//�����۷����ǰ��һ��
	void GoAheadOne();

	//�ñ������߼�����ĺ���
	void TurnRight();    //����ת
	void TurnLeft();	//����ת

	//**********************************���ݷ�װ����***************************
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

private://���ݳ�Ա
	
	Direction direction;		//��ǰ������н�����
	int pace;					//��ǰ���ߵĲ���
	char person;				//����������ַ�
	Coordinate cuurentCoord;	//��ǰ���������
	Coordinate beforeCoord;		//��һ��λ�õ�����
	Velocity velocity;			//���ߵ��ٶ�

};

