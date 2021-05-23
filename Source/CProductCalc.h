#pragma once

#include <memory>
#include "CSmartArray.h"
#include "ProductTag.h"

class CFactory;
class CProductCalc
{
	CSmartArray m_Array;
	CSmartArray m_AlreadyHave;
	CAtlArray<CFactory*> m_FactArray;
public:
	CProductCalc();

	~CProductCalc();
	void AddNeed(CString name, int count);
	void AddAlreadyHave(CString name, int count);
	void Calc();
	void Print();
	std::unique_ptr<CSmartArray> GetArray();
};