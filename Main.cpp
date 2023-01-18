#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>

#include "mnowacki/Vector.h"
#include "base/Entity.h"
#include "base/ScreenHandler.h"

//#define DEBUG

#ifdef DEBUG
#define log(x) std::cout << (x) << std::endl;
#endif // DEBUG

int main() {
#ifdef DEBUG



#endif

#ifndef DEBUG
	using namespace mnowacki;

	ScreenHandler screen;
	screen.init();

	Entity L_shape;
	const bool L_Defined = false;
	if(L_Defined)
	{
		L_shape.addVector(0, -1);
		L_shape.addVector(0, 0);
		L_shape.addVector(0, 1);
		L_shape.addVector(1, 1);

		L_shape.setAnchor(screen.center());

		L_shape.visible = false;
	}	
		
	Entity sHand;
	{
		const int sLength = 26;
		sHand.setAnchor(screen.center());
		for (int i = 0; i < sLength; i += 2) {
			sHand.addVector(0, i);
		}
	}

	Entity mHand;
	{
		const int mLength = 20;
		mHand.setAnchor(screen.center());
		for (int i = 0; i < mLength; i += 2) {
			mHand.addVector(0, i);
		}
	}

	Entity hHand;
	{
		const int hLength = 14;
		hHand.setAnchor(screen.center());
		for (int i = 0; i < hLength; i += 2) {
			hHand.addVector(0, i);
		}
	}

	Entity face;
	{
		face.setAnchor(screen.center());
		Vector v(0, 28);
		for (double i = 0; i < 2 * M_PI; i += M_PI / 120) {
			face.addVector(v);
			v.rotate(M_PI / 120);
		}
		screen.draw(face);
		screen.mvprint(1, screen.maxY() - 2, "Press \'x\' to exit.");
	}

	//time variables
	time_t tt;
	tm* ti;
	const double angleCorrection = M_PI / 2.0f;

	char wsad{0};
	do {
		time(&tt);
		ti = localtime(&tt);

		screen.mvprint(1, 1, "          ");
		screen.mvprint(1, 1, ti->tm_hour);
		screen.mvprint(3, 1, ti->tm_min);
		screen.mvprint(5, 1, ti->tm_sec);

		screen.erase(sHand);
		screen.erase(mHand);
		screen.erase(hHand);

		double sHandAngle = ti->tm_sec * M_PI / 30.0f;
		double mHandAngle = ti->tm_min * M_PI / 30.0f + sHandAngle / (double(12.0f) * 5.0f);
		double hHandAngle = ti->tm_hour * M_PI / 6.0f + mHandAngle / 12.0f;		

		/*
		sHand.setAngle(ti->tm_sec *  M_PI / 30 - M_PI / 2);
		mHand.setAngle(ti->tm_min *  M_PI / 30 - M_PI / 2);
		hHand.setAngle(ti->tm_hour * M_PI / 6  - M_PI / 2);
		*/

		sHand.setAngle(sHandAngle - angleCorrection);
		mHand.setAngle(mHandAngle - angleCorrection);
		hHand.setAngle(hHandAngle - angleCorrection);

		screen.draw(sHand);
		screen.draw(mHand);
		screen.draw(hHand);

		if(L_Defined)
		{
			screen.erase(L_shape);
			if (wsad == 'w') L_shape.rotate(M_PI / 2.0);
			if (wsad == 'd') L_shape.move(Vector(1, 0));
			screen.draw(L_shape);
			screen.log(L_shape);
		}

		screen.refresh();
	} while ((wsad = getch()) != 'x');
#endif // !DEBUG

}