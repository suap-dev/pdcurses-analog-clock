#include "Entity.h"
#include "../mnowacki/Vector.h"

Entity::Entity() :
	vList(),
	visible(true),
	anchor(0, 0)
{}

Entity::Entity(const mnowacki::Vector & anchor):
	vList(),
	visible(true),
	anchor(anchor)
{}

void Entity::addVector(mnowacki::Vector v)
{
	vList.push_back(v);
}

void Entity::addVector(double x, double y)
{
	vList.push_back(mnowacki::Vector(x, y));
}

void Entity::setAnchor(const mnowacki::Vector& v)
{
	anchor = v;
}

void Entity::setAnchor(double x, double y)
{
	anchor = mnowacki::Vector(x, y);
}

void Entity::move(const mnowacki::Vector& v)
{
	anchor += v;
}

void Entity::move(double dx, double dy)
{
	anchor.setX(anchor.getX() + dx);
	anchor.setY(anchor.getY() + dy);
}

void Entity::rotate(double angle)
{
	for (mnowacki::Vector& v : vList) {
		v.rotate(angle);
	}
}

void Entity::setAngle(double angle)
{
	for (auto& v : vList) {
		v.setAngle(angle);
	}
}

void Entity::scale(double s)
{
	for (mnowacki::Vector& v : vList) {
		v *= s;
	}
}


