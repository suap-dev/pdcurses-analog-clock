#include "Vector.h"
#include <cmath>

namespace mnowacki {
	Vector::Vector()
	{
		x = 1;
		y = 1;
	}

	Vector::Vector(const double& x, const double& y)
	{
		this->x = x;
		this->y = y;
	}

	Vector::Vector(const Vector& v)
	{
		x = v.x;
		y = v.y;

		//Vector(v.x, v.y);
	}

	Vector Vector::plus(const Vector& v) const
	{
		return Vector(x + v.x, y + v.y);
	}

	Vector Vector::times(const double& s) const
	{
		return Vector(x * s, y * s);
	}

	void Vector::add(const Vector& v)
	{
		x += v.x;
		y += v.y;
	}

	void Vector::multiplyBy(const double& s)
	{
		x *= s;
		y *= s;
	}

	bool Vector::equals(const Vector& v) const
	{
		return (x == v.x && y == v.y);
	}

	double Vector::getX() const
	{
		return x;
	}

	double Vector::getY() const
	{
		return y;
	}

	double Vector::getLength() const
	{
		return sqrt(x*x + y*y);
	}

	double Vector::getAngle() const
	{
		return atan(y / x);
	}

	void Vector::setX(const double& x)
	{
		this->x = x;
	}

	void Vector::setY(const double& y)
	{
		this->x = x;
	}

	void Vector::setLength(const double& length)
	{
		double k = length / sqrt(x * x + y * y);

		x *= k;
		y *= k;

		// TODO: Speed Testy
		/*
		double alpha = atan(y / x);
		x = cos(alpha) * length;
		y = sin(alpha) * length;
		*/

	}

	void Vector::setAngle(const double& angle)
	{
		double r = sqrt(x * x + y * y);

		x = cos(angle) * r;
		y = sin(angle) * r;
	}

	std::string Vector::toString() const
	{
		return ("[" + std::to_string(x) + "; " + std::to_string(y) + "]");
	}

	Vector Vector::operator+(const Vector& v) const
	{
		// alternatywnie
		//plus(v);
		return Vector(x + v.x, y + v.y);
	}

	Vector Vector::operator-(const Vector& v) const
	{
		return Vector(x - v.x, y - v.y);
	}

	Vector Vector::operator*(const double& s) const
	{
		return Vector(x * s, y * s);
	}

	Vector Vector::operator/(const double& s) const
	{
		return Vector(x / s, y / s);
	}

	Vector Vector::rotated(const double& angle) const
	{
		return Vector(x * cos(angle) - y * sin(angle), y * cos(angle) + x * sin(angle));
	}

	void Vector::operator+=(const Vector& v)
	{
		// alternatywnie
		//addVector(v);
		x += v.x;
		y += v.y;
	}

	void Vector::operator-=(const Vector& v)
	{
		x -= v.x;
		y -= v.y;
	}

	void Vector::operator*=(const double& s)
	{
		x *= s;
		y *= s;
	}

	void Vector::operator/=(const double& s)
	{
		x /= s;
		y /= s;
	}

	void Vector::rotate(const double& angle)
	{
		x = x * cos(angle) - y * sin(angle);
		y = y * cos(angle) + x * sin(angle);
	}

	bool Vector::operator==(const Vector& v) const
	{
		if (x == v.x && y == v.y)
			return true;
		else
			return false;
	}
}