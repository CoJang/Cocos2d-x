#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Animator : public cocos2d::Sprite
{
public:
	Animator();
	virtual ~Animator();

	//[1, 2] �ִϸ��̼����� ��� �� ��������Ʈ ũ�� [X Y]
	//[3, 4] �� �̹��� ũ�� [X Y]
	//[5]    �� ���� ��������Ʈ�� ��� �� �ð�
	//[6, 7] ���ϸ� [��������Ʈ, �̹���]
	static Animator* InitAnimation(cocos2d::Layer* scene, int animationCnt, int unitsizeX, int unitsizeY, int imagewidth, int imageheight, float anidelay, char* imagefile);

public:
	void SetAniIndex(int Index);	// �ִϸ��̼� ��ȭ�� �����ϱ� ���� �޼ҵ� [ ����(Y��) ��ġ ]

	int GetSrcTop();				// �̹��� (�ҽ�)�� ��ġ�� ������ ���� �޼ҵ�
	int GetSrcLeft();

	//void SetAnchorPoint(Vec2 anchor);
	//void SetPosition(Vec2 sprpos);

protected:
	int UnitSizeX, UnitSizeY;	// �ִϸ��̼����� ��� �� ��������Ʈ ũ��
	float AniDelay;				// �̹����� ��� �� �����ð�
	int ImageWidth;				// �� �̹��� X�� ũ��
	int ImageHeight;			// �� �̹��� Y�� ũ��
	int CurrentFrame;			// ���� ����� ���� ��������Ʈ ��ġ
	int AniIndex;				// ���� ����� ���� ��������Ʈ ��ġ
	int TotalHorzCount;		    // ���� ��������Ʈ ���� [ X ]
	int TotalAniCount;			// ��ü ��������Ʈ ����
	float AniDuration;			// ���� ��������Ʈ�� ����� �ð�.
};

