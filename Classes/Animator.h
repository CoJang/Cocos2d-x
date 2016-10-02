#pragma once
#include "cocos2d.h"

class Animator : public cocos2d::LayerColor
{
public:
	Animator();
	virtual ~Animator();

	//[1, 2] �ִϸ��̼����� ��� �� ��������Ʈ ũ�� [X Y]
	//[3, 4] �� �̹��� ũ�� [X Y]
	//[5]    �̹����� ��� �� �����ð�
	void InitAnimation(int unitsizeX, int unitsizeY, int imagewidth, int imageheight, float anidelay);

public:
	void FrameMove(FLOAT Elapsed);	// ���� �ð��� ������ ��������Ʈ �̹��� �̵��� ó��

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

