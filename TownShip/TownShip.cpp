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
	ar.Add(_T("������"), 1);
	ar.Add(_T("������������ ����"), 1);
	ar.Add(_T("���������� �����"), 1);
	ar.Add(_T("������"), 1);
	ar.Add(_T("�������"), 1);
	ar.Add(_T("�������� �������"), 2);
	ar.Add(_T("��������"), 2);
	ar.Add(_T("�������"), 1);
	ar.Add(_T("�������"), 1);
	ar.Add(_T("������"), 1);
	ar.Add(_T("������"), 1);
	ar.Add(_T("��������"), 1);
	ar.Add(_T("������"), 3 * 2);
	ar.Add(_T("�������"), 1);

	ar.Calc();
	ar.Calc();
	ar.Calc();
	ar.Print();
	return 0;
}
