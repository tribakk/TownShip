#pragma once

#include "CFactory.h"
#include "CSmartArray.h"
#include "ProductTag.h"
#include "CProductCallFill.h"
class CProductCalc
{
	CSmartArray m_Array;
	CSmartArray m_AlreadyHave;
	CAtlArray<CFactory*> m_FactArray;
public:
	CProductCalc();

	~CProductCalc();
	void Add(CString name, int count);
	void Calc();
	void Print();
};