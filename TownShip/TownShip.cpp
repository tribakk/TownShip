// TownShip.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Source/CSmartArray.h"
#include "../Source/CFactory.h"
#include "../Source/CProductCalc.h"
#include "../Source/CProductCallFill.h"

int main()
{
	CProductCalc ar;
	ar.Add(_T("пончик"), 1);
	ar.Add(_T("картофельный хлеб"), 1);
	ar.Add(_T("кукурузные чипсы"), 1);
	ar.Add(_T("пальто"), 1);
	ar.Add(_T("печенье"), 1);
	ar.Add(_T("сахарный тросник"), 2);
	ar.Add(_T("кукуруза"), 2);
	ar.Add(_T("сэндвич"), 1);
	ar.Add(_T("попкорн"), 1);
	ar.Add(_T("йогурт"), 1);
	ar.Add(_T("пончик"), 1);
	ar.Add(_T("карамель"), 1);
	ar.Add(_T("молоко"), 3 * 2);
	ar.Add(_T("попкорн"), 1);

	ar.Calc();
	ar.Calc();
	ar.Calc();
	ar.Print();
	return 0;
}
