// TownShip.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Source/CSmartArray.h"
#include "../Source/CFactory.h"
#include "../Source/CProductCalc.h"

void SetAlreadyHave(CProductCalc& arr)
{
	arr.AddAlreadyHave(_T("�������"), 2);
	arr.AddAlreadyHave(_T("��������"), 5);
	arr.AddAlreadyHave(_T("�������"), 5);
	arr.AddAlreadyHave(_T("�������� �������"), 5);
	arr.AddAlreadyHave(_T("������"), 2);
	arr.AddAlreadyHave(_T("��������"), 1);
	arr.AddAlreadyHave(_T("�����"), 2);
	arr.AddAlreadyHave(_T("�����"), 4);
	arr.AddAlreadyHave(_T("���������"), 4);
	arr.AddAlreadyHave(_T("�����"), 13);
	arr.AddAlreadyHave(_T("������"), 2);
	arr.AddAlreadyHave(_T("����"), 3);
	arr.AddAlreadyHave(_T("�����"), 1);
	arr.AddAlreadyHave(_T("����"), 1);
	arr.AddAlreadyHave(_T("�������"), 1);
	arr.AddAlreadyHave(_T("������"), 2);
	arr.AddAlreadyHave(_T("�����"), 2);
	arr.AddAlreadyHave(_T("������������ ����"), 0);
	arr.AddAlreadyHave(_T("��������� ����"), 1);
	arr.AddAlreadyHave(_T("������"), 1);
	arr.AddAlreadyHave(_T("���"), 4);
	arr.AddAlreadyHave(_T("�����"), 0);
	arr.AddAlreadyHave(_T("������"), 1);
	arr.AddAlreadyHave(_T("���������� ������"), 1);
	arr.AddAlreadyHave(_T("��������� �����"), 5);
	arr.AddAlreadyHave(_T("�����"), 4);
	arr.AddAlreadyHave(_T("�������� �����"), 3);
	arr.AddAlreadyHave(_T("�������"), 4);
	arr.AddAlreadyHave(_T("������"), 3);
	arr.AddAlreadyHave(_T("������"), 0);
	arr.AddAlreadyHave(_T("�����"), 3);
	arr.AddAlreadyHave(_T("������"), 3);
	arr.AddAlreadyHave(_T("������"), 1);
	arr.AddAlreadyHave(_T("�������"), 4);
	arr.AddAlreadyHave(_T("���������� �����"), 2);
	arr.AddAlreadyHave(_T("�������"), 5);
	arr.AddAlreadyHave(_T("�����"), 0);
	arr.AddAlreadyHave(_T("��������"), 2);
	arr.AddAlreadyHave(_T("���������"), 0);
	arr.AddAlreadyHave(_T("�������"), 1);
	arr.AddAlreadyHave(_T("�������� ���"), 2);
	arr.AddAlreadyHave(_T("������� ���������"), 1);
	arr.AddAlreadyHave(_T("������"), 3);
	arr.AddAlreadyHave(_T("�������"), 4);
	arr.AddAlreadyHave(_T("����"), 1);
	arr.AddAlreadyHave(_T("�����"), 4);
	arr.AddAlreadyHave(_T("�����"), 2);
	arr.AddAlreadyHave(_T("��������"), 0);
	arr.AddAlreadyHave(_T("������� ��������"), 2);
	arr.AddAlreadyHave(_T("������"), 4);
	arr.AddAlreadyHave(_T("�������� ���������"), 1);
	arr.AddAlreadyHave(_T("����"), 1);
	arr.AddAlreadyHave(_T("�����"), 1);
	arr.AddAlreadyHave(_T("����������"), 2);
	arr.AddAlreadyHave(_T("��������� ���"), 3);
	arr.AddAlreadyHave(_T("������������� ������"), 2);
	arr.AddAlreadyHave(_T("������"), 4);
	arr.AddAlreadyHave(_T("���������� ������"), 2);
	arr.AddAlreadyHave(_T("����"), 1);
	arr.AddAlreadyHave(_T("���������� �����"), 1);
	arr.AddAlreadyHave(_T("��������"), 3);
	arr.AddAlreadyHave(_T("������"), 0);
}

void SetNeed(CProductCalc& arr)
{
	arr.AddNeed(_T("������"), 1);
	arr.AddNeed(_T("������������ ����"), 1);
	arr.AddNeed(_T("���������� �����"), 1);
	arr.AddNeed(_T("������"), 1);
	arr.AddNeed(_T("�������"), 1);
	arr.AddNeed(_T("�������� �������"), 2);
	arr.AddNeed(_T("��������"), 2);
	arr.AddNeed(_T("�������"), 1);
	arr.AddNeed(_T("�������"), 1);
	arr.AddNeed(_T("������"), 1);
	arr.AddNeed(_T("������"), 1);
	arr.AddNeed(_T("��������"), 1);
	arr.AddNeed(_T("������"), 3 * 2);
	arr.AddNeed(_T("�������"), 1);
}

int main()
{
	CProductCalc ar;
	SetNeed(ar);
	SetAlreadyHave(ar);

	ar.Calc();
	ar.Calc();
	ar.Calc();
	ar.Print();
	return 0;
}
