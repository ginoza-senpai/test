﻿#include "Ellipse.h"


double Ellipse::df(double t)
{
	return (sqrt(par[0] / par[4]) * cos(t)) / ( sqrt(par[0] / par[5]) * (-sin(t)));
}

Ellipse::Ellipse(double a, double b, double r)
{
	par[5] = 1/(a*a);
	par[4] = 1/(b*b);
	par[0] = r*r;
}

Point Ellipse::onCurvePoint(double t)
{
	return Point(sqrt(par[0] / par[5]) * cos(t), sqrt(par[0] / par[4]) * sin(t));
}

std::string Ellipse::toStrParametric()
{
	return std::string("(" + std::to_string(sqrt(par[0] / par[5])) + " * cos(t), " + std::to_string(sqrt(par[0] / par[4])) + " * sin(t) ) a=" + std::to_string(1/sqrt(par[5])) + " b=" + std::to_string(1/sqrt(par[4])) + " R=" + std::to_string(par[0]));
}

bool Ellipse::isClosed()
{
	return true;
}

Ellipse * buildEllipse(Point* dotList)
{
	Ellipse* result = nullptr;
	double* kof = rref(doMatr(dotList, basisEllipse, 3, 3), doKof(dotList, yEllipse), 3,3);
	if (kof != nullptr)
		result = new Ellipse(1, 1 / sqrt(kof[0]), sqrt(kof[1]));
	delete[] kof;
	return result;
}

double basisEllipse(double t, int bin)
{
	switch (bin)
	{
	case 0:
		return - t * t;
		break;
	case 1:
		return 1;
		break;
	default:
		return 0;
		break;
	}
}

double yEllipse(double t)
{
	return t * t;
}
