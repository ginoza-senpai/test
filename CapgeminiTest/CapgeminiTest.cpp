﻿#include "CapgeminiTest.h"

using namespace std;

void curveInfo(Curve* obj, double t,string inf = "object")
{
	if (obj != nullptr)
	{
		cout << "--- beg info ---\n";
		cout << "Parametric interpretation: " << obj->toStrParametric();
		cout << "\nPoint on curve: " << obj->onCurvePoint(t).toStr() << '\n';
		cout << "Tangetn to point" << obj->findTangent(t).toStr();
		cout << "\nIs closed: " << obj->isClosed();
		cout << "\n--- end info ---\n";
	}
	else
		cout << "--- beg info ---\n Incorrect dots to build " << inf << "\n--- end info ---\n";
}

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	double t = 0;
	double tPi = 2*acos(0.0);

	if (argc > 1)
		t = atoi(argv[1]);
	if (argc > 2)
		tPi *=  atof(argv[2]);


	Point* dotList = new Point[3];

	dotList[0] = Point(-1, 1); 
	dotList[1] = Point(0, 0);
	dotList[2] = Point(2, 4);
	cout << "### Parabola ###\nCorrect dots: " << dotList[0].toStr() << ", " << dotList[1].toStr() <<", " << dotList[2].toStr() << "\n";
	Parabola * par = buildParabola(dotList);;
	curveInfo(par, t, "parabola");
	delete[] par;

	dotList[0] = Point(-1, 1);
	dotList[1] = Point(0, 0);
	dotList[2] = Point(0, 1);
	cout << "\nIncrrect dots: " << dotList[0].toStr() << ", " << dotList[1].toStr() << ", " << dotList[2].toStr() << "\n";
	par = buildParabola(dotList);
	curveInfo(par,t, "parabola");
	delete[] par;

	dotList[0] = Point(-10, -10);
	dotList[1] = Point(0, 0);
	dotList[2] = Point(10, 1);
	cout << "\nOne more dots set: " << dotList[0].toStr() << ", " << dotList[1].toStr() << ", " << dotList[2].toStr() << "\n";
	par = buildParabola(dotList);
	curveInfo(par, t, "parabola");
	delete[] par;


	
	dotList[0] = Point(-4, 0);
	dotList[1] = Point(0, 1);
	dotList[2] = Point(4, 0);
	cout << "\n\n\n### Ellipse ###\nCorrect dots: " << dotList[0].toStr() << ", " << dotList[1].toStr() << ", " << dotList[2].toStr() << "\n";
	Ellipse *ell = buildEllipse(dotList);
	curveInfo(ell, tPi, "ellipse");
	delete[] ell;

	dotList[0] = Point(-1, 1);
	dotList[1] = Point(0, 0);
	dotList[2] = Point(0, 1);
	cout << "\nIncrrect dots: " << dotList[0].toStr() << ", " << dotList[1].toStr() << ", " << dotList[2].toStr() << "\n";
	ell = buildEllipse(dotList);
	curveInfo(ell, tPi, "ellipse");
	delete[] ell;

	dotList[0] = Point(1, 0);
	dotList[1] = Point(0, -7);
	dotList[2] = Point(0, 7);
	cout << "\nOne more dots set: " << dotList[0].toStr() << ", " << dotList[1].toStr() << ", " << dotList[2].toStr() << "\n";
	ell = buildEllipse(dotList);
	curveInfo(ell, tPi, "ellipse");
	delete[] ell;



	dotList[0] = Point(-4, 0);
	dotList[1] = Point(0, 4);
	dotList[2] = Point(4, 0);
	cout << "\n\n\n### Circle ###\nCorrect dots: " << dotList[0].toStr() << ", " << dotList[1].toStr() << ", " << dotList[2].toStr() << "\n";
	Circle *cir = buildCircle(dotList);
	curveInfo(cir, tPi, "circle");
	delete[] cir;

	dotList[0] = Point(-1, 1);
	dotList[1] = Point(0, 0);
	dotList[2] = Point(0, 1);
	cout << "\nIncrrect dots: " << dotList[0].toStr() << ", " << dotList[1].toStr() << ", " << dotList[2].toStr() << "\n";
	cir = buildCircle(dotList);
	curveInfo(cir, tPi, "circle");
	delete[] cir;

	dotList[0] = Point(7, 0);
	dotList[1] = Point(0, -7);
	dotList[2] = Point(0, 7);
	cout << "\nOne more dots set: " << dotList[0].toStr() << ", " << dotList[1].toStr() << ", " << dotList[2].toStr() << "\n";
	cir = buildCircle(dotList);
	curveInfo(cir, tPi, "circle");
	delete[] cir;

	
	delete[] dotList;
}