#pragma once
#include "cocos2d.h"

class Animator
{
public:
	Animator();
	virtual ~Animator();

	//[1, 2] �ִϸ��̼����� ��� �� ��������Ʈ ũ�� [X Y]
	//[3, 4] �� �̹��� ũ�� [X Y]
	//[5]    �̹����� ��� �� �����ð�
	static Animator* InitAnimation(cocos2d::Layer* scene, int unitsizeX, int unitsizeY, int imagewidth, int imageheight, float anidelay);

public:
	void UpdateAni(FLOAT Elapsed);	// ���� �ð��� ������ ��������Ʈ �̹��� ������Ʈ�� ó��

	void SetAniIndex(int Index);	// �ִϸ��̼� ��ȭ�� �����ϱ� ���� �޼ҵ� [ ����(Y��) ��ġ ]

	int GetSrcTop();				// �̹��� (�ҽ�)�� ��ġ�� ������ ���� �޼ҵ�
	int GetSrcLeft();

public:
	int UnitSizeX, UnitSizeY;	// �ִϸ��̼����� ��� �� ��������Ʈ ũ��
	float AniDelay;				// �̹����� ��� �� �����ð�
	int ImageWidth;				// �� �̹��� X�� ũ��
	int ImageHeight;			// �� �̹��� Y�� ũ��
	int CurrentFrame;			// ���� ����� ���� ��������Ʈ ��ġ
	int AniIndex;				// ���� ����� ���� ��������Ʈ ��ġ
	int TotalFrameCount;		// ���� ��������Ʈ ���� [ X ]
	int TotalAniCount;			// ���� ��������Ʈ ���� [ Y ]
	float AniDuration;			// ���� ��������Ʈ�� ����� �ð�.
};

