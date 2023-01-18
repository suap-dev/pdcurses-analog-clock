#pragma once

#include "../mnowacki/Vector.h"

#include <vector>

class Entity
{
private:
	std::vector<mnowacki::Vector> vList;
	mnowacki::Vector anchor;

public:
	bool visible;
	Entity();

	Entity(const mnowacki::Vector& anchor);


	void addVector(mnowacki::Vector v);
	void addVector(double x, double y);

	void setAnchor(const mnowacki::Vector& v);
	void setAnchor(double x, double y);
	void move(const mnowacki::Vector& v);
	void move(double dx, double dy);

	void rotate(double angle);
	void setAngle(double angle);
	void scale(double s);

	friend class ScreenHandler;
};

