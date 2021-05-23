#pragma once
#include "stdafx.h"
#include "CProductCalc.h"
#include "CFactory.h"

CProductCalc::CProductCalc()
{
	m_FactArray.push_back(new CMilkFactory());
	m_FactArray.push_back(new CBakery());
	m_FactArray.push_back(new СWeavingFactory());
	m_FactArray.push_back(new CSewingFactory());
	m_FactArray.push_back(new CSnackFactory());
	m_FactArray.push_back(new CFastFoodFactory());
	m_FactArray.push_back(new CRubberFactory());
	m_FactArray.push_back(new CSugarFactory());
	m_FactArray.push_back(new CPaperFactory());
	m_FactArray.push_back(new CIceCreamFactory());
	m_FactArray.push_back(new СconfectioneryFactory());
}

CProductCalc::~CProductCalc()
{
	size_t count = m_FactArray.size();
	for (size_t i = 0; i < count; i++)
	{
		delete m_FactArray[i];
	}
}
void CProductCalc::AddNeed(std::string name, int count)
{
	m_Array.Add(name, count);
}

void CProductCalc::AddAlreadyHave(std::string name, int count)
{
	m_AlreadyHave.Add(name, count);
}

void CProductCalc::Calc()
{
	m_Array.ExcludeWhatHave(m_AlreadyHave);
	//if (firstcalc)
	//{

	//}
	for (auto iter = m_FactArray.begin(); iter != m_FactArray.end(); iter++)
	{
		CFactory* pFact = *iter;
		pFact->SetInput(m_Array);
		pFact->Calc();
		pFact->UpdateResult(m_Array);
		m_Array.ExcludeWhatHave(m_AlreadyHave);
	}
}

void CProductCalc::Print()
{
	OutputDebugStringA("Информация по фабрикам:\n\r");
	for (int pr = 0; pr < (int)PriorityTag::three + 1; pr++)
	{
		for (auto iter = m_FactArray.begin(); iter != m_FactArray.end(); iter++)
		{
			if ((*iter)->GetPriorety() == pr)
				(*iter)->Print();
		}

	}
	OutputDebugStringA("\n\rИнформация по ингридиентам:\n\r");
	m_Array.Print();
}

std::unique_ptr<CSmartArray> CProductCalc::GetArray()
{
	std::unique_ptr<CSmartArray> pAllProduct = std::make_unique<CSmartArray>();
	pAllProduct->Merge(m_Array);
	return std::move(pAllProduct);
}
