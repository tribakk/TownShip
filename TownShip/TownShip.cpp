// TownShip.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Source/CSmartArray.h"
#include "../Source/CFactory.h"
#include "../Source/CProductCalc.h"

void SetAlreadyHave(CProductCalc& arr)
{
	arr.AddAlreadyHave(_T("пшеница"), 2);
	arr.AddAlreadyHave(_T("кукуруза"), 5);
	arr.AddAlreadyHave(_T("морковь"), 5);
	arr.AddAlreadyHave(_T("сахарный тросник"), 5);
	arr.AddAlreadyHave(_T("хлопок"), 2);
	arr.AddAlreadyHave(_T("клубника"), 1);
	arr.AddAlreadyHave(_T("томат"), 2);
	arr.AddAlreadyHave(_T("сосна"), 4);
	arr.AddAlreadyHave(_T("картофель"), 4);
	arr.AddAlreadyHave(_T("какао"), 13);
	arr.AddAlreadyHave(_T("каучук"), 2);
	arr.AddAlreadyHave(_T("шелк"), 3);
	arr.AddAlreadyHave(_T("перец"), 1);
	arr.AddAlreadyHave(_T("хлеб"), 1);
	arr.AddAlreadyHave(_T("печенье"), 1);
	arr.AddAlreadyHave(_T("бублик"), 2);
	arr.AddAlreadyHave(_T("пицца"), 2);
	arr.AddAlreadyHave(_T("картофельный хлеб"), 0);
	arr.AddAlreadyHave(_T("банановый хлеб"), 1);
	arr.AddAlreadyHave(_T("сливки"), 1);
	arr.AddAlreadyHave(_T("сыр"), 4);
	arr.AddAlreadyHave(_T("масло"), 0);
	arr.AddAlreadyHave(_T("йогурт"), 1);
	arr.AddAlreadyHave(_T("персиковый йогурт"), 1);
	arr.AddAlreadyHave(_T("хлопкова€ ткань"), 5);
	arr.AddAlreadyHave(_T("пр€жа"), 4);
	arr.AddAlreadyHave(_T("шелкова€ ткань"), 3);
	arr.AddAlreadyHave(_T("рубашка"), 4);
	arr.AddAlreadyHave(_T("свитер"), 3);
	arr.AddAlreadyHave(_T("пальто"), 0);
	arr.AddAlreadyHave(_T("шл€па"), 3);
	arr.AddAlreadyHave(_T("платье"), 3);
	arr.AddAlreadyHave(_T("костюм"), 1);
	arr.AddAlreadyHave(_T("попкорн"), 4);
	arr.AddAlreadyHave(_T("кукурузные чипсы"), 2);
	arr.AddAlreadyHave(_T("√ранола"), 5);
	arr.AddAlreadyHave(_T("чипсы"), 0);
	arr.AddAlreadyHave(_T("милкшейк"), 2);
	arr.AddAlreadyHave(_T("чизбургер"), 0);
	arr.AddAlreadyHave(_T("сэндвич"), 1);
	arr.AddAlreadyHave(_T("картошка фри"), 2);
	arr.AddAlreadyHave(_T("печеный картофель"), 1);
	arr.AddAlreadyHave(_T("резина"), 3);
	arr.AddAlreadyHave(_T("пластик"), 4);
	arr.AddAlreadyHave(_T("клей"), 1);
	arr.AddAlreadyHave(_T("сахар"), 4);
	arr.AddAlreadyHave(_T("сироп"), 2);
	arr.AddAlreadyHave(_T("карамель"), 0);
	arr.AddAlreadyHave(_T("медова€ карамель"), 2);
	arr.AddAlreadyHave(_T("бумага"), 4);
	arr.AddAlreadyHave(_T("бумажные полотенца"), 1);
	arr.AddAlreadyHave(_T("обои"), 1);
	arr.AddAlreadyHave(_T("книга"), 1);
	arr.AddAlreadyHave(_T("мороженное"), 2);
	arr.AddAlreadyHave(_T("фруктовый лед"), 3);
	arr.AddAlreadyHave(_T("заморолженный йогурт"), 2);
	arr.AddAlreadyHave(_T("эскимо"), 4);
	arr.AddAlreadyHave(_T("ананасовый сорбет"), 2);
	arr.AddAlreadyHave(_T("кекс"), 1);
	arr.AddAlreadyHave(_T("шоколадный пирог"), 1);
	arr.AddAlreadyHave(_T("пирожное"), 3);
	arr.AddAlreadyHave(_T("пончик"), 0);
}

void SetNeed(CProductCalc& arr)
{
	arr.AddNeed(_T("пончик"), 1);
	arr.AddNeed(_T("картофельный хлеб"), 1);
	arr.AddNeed(_T("кукурузные чипсы"), 1);
	arr.AddNeed(_T("пальто"), 1);
	arr.AddNeed(_T("печенье"), 1);
	arr.AddNeed(_T("сахарный тросник"), 2);
	arr.AddNeed(_T("кукуруза"), 2);
	arr.AddNeed(_T("сэндвич"), 1);
	arr.AddNeed(_T("попкорн"), 1);
	arr.AddNeed(_T("йогурт"), 1);
	arr.AddNeed(_T("пончик"), 1);
	arr.AddNeed(_T("карамель"), 1);
	arr.AddNeed(_T("молоко"), 3 * 2);
	arr.AddNeed(_T("попкорн"), 1);
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
