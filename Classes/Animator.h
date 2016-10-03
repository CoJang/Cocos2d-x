#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Animator : public cocos2d::Sprite
{
public:
	Animator();
	virtual ~Animator();

	//[1, 2] 애니메이션으로 출력 될 스프라이트 크기 [X Y]
	//[3, 4] 총 이미지 크기 [X Y]
	//[5]    한 개의 스프라이트가 출력 될 시간
	//[6, 7] 파일명 [스프라이트, 이미지]
	static Animator* InitAnimation(cocos2d::Layer* scene, int animationCnt, int unitsizeX, int unitsizeY, int imagewidth, int imageheight, float anidelay, char* imagefile);

public:
	void SetAniIndex(int Index);	// 애니메이션 변화를 설정하기 위한 메소드 [ 세로(Y축) 위치 ]

	int GetSrcTop();				// 이미지 (소스)의 위치를 얻어오기 위한 메소드
	int GetSrcLeft();

	//void SetAnchorPoint(Vec2 anchor);
	//void SetPosition(Vec2 sprpos);

protected:
	int UnitSizeX, UnitSizeY;	// 애니메이션으로 출력 될 스프라이트 크기
	float AniDelay;				// 이미지가 출력 될 지연시간
	int ImageWidth;				// 총 이미지 X축 크기
	int ImageHeight;			// 총 이미지 Y축 크기
	int CurrentFrame;			// 현재 출력할 가로 스프라이트 위치
	int AniIndex;				// 현재 출력할 세로 스프라이트 위치
	int TotalHorzCount;		    // 가로 스프라이트 갯수 [ X ]
	int TotalAniCount;			// 전체 스프라이트 개수
	float AniDuration;			// 현재 스프라이트를 출력한 시간.
};

