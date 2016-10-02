#include "Animator.h"

Animator::Animator()
{
	UnitSizeX = 0;			UnitSizeY = 0;
	AniDelay = 0; 			AniIndex = 0;
	ImageWidth = 0;			ImageHeight = 0;
	CurrentFrame = 0;
	TotalFrameCount = 0;	TotalAniCount = 0;
	AniDuration = 0;
}

Animator::~Animator()
{
}

void Animator::InitAnimation(int unitsizeX, int unitsizeY, int imagewidth, int imageheight, float anidelay)
{
	UnitSizeX = unitsizeX;
	UnitSizeY = unitsizeY;
	ImageWidth = imagewidth;
	ImageHeight = imageheight;
	AniDelay = anidelay;
	TotalFrameCount = ImageWidth / UnitSizeX;
	TotalAniCount = ImageHeight / UnitSizeY;
}

void Animator::FrameMove(float Elapsed)
{
	AniDuration -= Elapsed;

	if (AniDuration < 0)
	{
		AniDuration += AniDelay;
		++CurrentFrame;
		if (CurrentFrame >= TotalFrameCount)
			CurrentFrame = 0;
	}
}

void Animator::SetAniIndex(int index)
{
	AniIndex = index;
}

int Animator::GetSrcTop()
{
	return AniIndex * UnitSizeY;
}

int Animator::GetSrcLeft()
{
	return CurrentFrame * UnitSizeX;
}