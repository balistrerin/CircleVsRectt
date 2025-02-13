#include <iostream>
#include <optional>
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#define OLC_PGEX_TRANSFORMEDVIEW
#include "olcPGEX_TransformedView.h"

class CircleVsRect : public olc::PixelGameEngine
{
public:
	CircleVsRect()
	{
		sAppName = "Circle Vs Rectangle";
	}

private:
	olc::TileTransformedView tv;

	struct sWorldObject
	{
		olc::vf2d vPos;
		olc::vf2d vVel;
		float fRadius = 0.5f;
	};

public:
	bool OnUserCreate() override
	{
		tv = olc::TileTransformedView({ ScreenWidth(), ScreenHeight() }, { 32,32 });
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		//Pan & Zoom
		if (GetMouse(2).bPressed) tv.StartPan(GetMousePos());
		if (GetMouse(2).bHeld) tv.UpdatePan(GetMousePos());
		if (GetMouse(2).bReleased) tv.EndPan(GetMousePos());
		if (GetMouse(2).bPressed) tv.StartPan(GetMousePos());
		if (GetMouseWheel() > 0) tv.ZoomAtScreenPos(2.0f, GetMousePos());
		if (GetMouseWheel() < 0) tv.ZoomAtScreenPos(0.5f, GetMousePos());

		Clear(olc::VERY_DARK_BLUE);

		tv.DrawCircle({ 0,0 }, 20.0f);

		return true;
	}
};


int main()
{
	CircleVsRect demo;
	if (demo.Construct(640, 480, 2, 2))
		demo.Start();

	return 0;
}