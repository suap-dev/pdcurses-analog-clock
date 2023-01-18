#pragma once
#include <iostream>
#include <string>

namespace mnowacki {
	class Vector {
	private:
		// fields
		double x, y;

		// operations definitions
		Vector plus(const Vector& v) const;
		Vector times(const double& s) const;

		void add(const Vector& v);
		void multiplyBy(const double& s);

		bool equals(const Vector& v) const;

	public:
		Vector();
		Vector(const double& x, const double& y);
		Vector(const Vector& v);
		// getters
		//const double& x() const;
		//const double& y() const;
		double getX() const;
		double getY() const;

		// tutaj przydadza sie funkcje takie jak:
		double getLength() const;
		double getAngle() const;

		// setters
		void setX(const double& x);
		void setY(const double& y);
		void setLength(const double& length);
		void setAngle(const double& angle);

		std::string toString() const;

		Vector operator + (const Vector& v) const;
		Vector operator - (const Vector& v) const;
		Vector operator * (const double& s) const;
		Vector operator / (const double& s) const;
		Vector rotated(const double& angle) const;

		void operator += (const Vector& v);
		void operator -= (const Vector& v);
		void operator *= (const double& s);
		void operator /= (const double& s);
		void rotate(const double& angle);

		bool operator == (const Vector& v) const;
		/*
		// friends
		friend Vector operator * (const double& s, const Vector& v);
		friend Vector operator / (const double& s, const Vector& v);
		friend std::ostream& operator << (std::ostream& os, const my::Vector& v);
		friend std::string to_string(const my::Vector& v);
		*/
	};
}