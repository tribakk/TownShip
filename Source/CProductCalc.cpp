#pragma once
#include "stdafx.h"
#include "CProductCalc.h"
#include "CFactory.h"

CProductCalc::CProductCalc()
{
	m_FactArray.Add(new CMilkFactory());
	m_FactArray.Add(new CBakery());
	m_FactArray.Add(new СWeavingFactory());
	m_FactArray.Add(new CSewingFactory());
	m_FactArray.Add(new CSnackFactory());
	m_FactArray.Add(new CFastFoodFactory());
	m_FactArray.Add(new CRubberFactory());
	m_FactArray.Add(new CSugarFactory());
	m_FactArray.Add(new CPaperFactory());
	m_FactArray.Add(new CIceCreamFactory());
	m_FactArray.Add(new СconfectioneryFactory());
}

CProductCalc::~CProductCalc()
{
	size_t count = m_FactArray.GetCount();
	for (size_t i = 0; i < count; i++)
	{
		delete m_FactArray[i];
	}
}
void CProductCalc::AddNeed(CString name, int count)
{
	m_Array.Add(name, count);
}

void CProductCalc::AddAlreadyHave(CString name, int count)
{
	m_AlreadyHave.Add(name, count);
}

void CProductCalc::Calc()
{
	size_t count = m_FactArray.GetCount();
	m_Array.ExcludeWhatHave(m_AlreadyHave);
	//if (firstcalc)
	//{

	//}
	for (size_t i = 0; i < count; i++)
	{
		CFactory* pFact = m_FactArray[i];
		pFact->SetInput(m_Array);
		pFact->Calc();
		pFact->UpdateResult(m_Array);
		m_Array.ExcludeWhatHave(m_AlreadyHave);
	}
}

void CProductCalc::Print()
{
	OutputDebugString(_T("Информация по фабрикам:\n\r"));
	size_t count = m_FactArray.GetCount();
	for (int pr = 0; pr < (int)PriorityTag::three + 1; pr++)
	{
		for (size_t i = 0; i < count; i++)
		{
			if (m_FactArray[i]->GetPriorety() == pr)
				m_FactArray[i]->Print();
		}

	}
	OutputDebugString(_T("\n\rИнформация по ингридиентам:\n\r"));
	m_Array.Print();
}
