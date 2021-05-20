#pragma once
#include "stdafx.h"
#include "CSmartArray.h"

void CSmartArray::Add(ProductTag tag, int count)
{
	if (count == 0)
		return;
	if (m_TagMap.Lookup(tag))
		m_TagMap[tag] += count;
	else
		m_TagMap[tag] = count;
}
void CSmartArray::Add(const CString& name, int count)
{
	ProductTag tag = GetAllProductSpisok()->GetTag(name);
	Add(tag, count);
}
void CSmartArray::Merge(CSmartArray& Arr)
{
	POSITION pos = Arr.m_TagMap.GetStartPosition();
	for (; pos != NULL;)
	{
		ProductCount* prCount = Arr.m_TagMap.GetNext(pos);
		Add(prCount->m_key, prCount->m_value);
	}
}
void CSmartArray::ClearTag(ProductTag tag)
{
	m_TagMap.RemoveKey(tag);
}

int CSmartArray::GetTagCount(ProductTag tag)
{
	int count = 0;
	if (m_TagMap.Lookup(tag))
		count = m_TagMap[tag];
	return count;
}
void CSmartArray::RemoveAll()
{
	m_TagMap.RemoveAll();
}
void CSmartArray::Print()
{
	POSITION pos = m_TagMap.GetStartPosition();
	for (; pos != NULL;)
	{
		ProductCount* prCount = m_TagMap.GetNext(pos);
		CString sCount;
		sCount.Format(_T(": %i \n\r"), prCount->m_value);
		OutputDebugString(GetAllProductSpisok()->GetName(prCount->m_key) + sCount);
	}
}
bool CSmartArray::IsEmpty()
{
	return m_TagMap.IsEmpty();
}

void CSmartArray::ExcludeWhatHave(CSmartArray& Arr)
{
	POSITION pos = m_TagMap.GetStartPosition();
	for (; pos != NULL;)
	{
		ProductCount prCount(*m_TagMap.GetNext(pos)); //создаем копию, т.к. жизнь указателя не гарантирована
		ProductTag tag = prCount.m_key;
		if (int count = Arr.GetTagCount(tag))
		{
			if (prCount.m_value > count)
			{
				Add(tag, -count);
				Arr.ClearTag(tag);
			}
			else if (prCount.m_value < count)
			{
				ClearTag(tag);
				Arr.Add(tag, -prCount.m_value);
			}
			else //одинаковое значение
			{
				ClearTag(tag);
				Arr.ClearTag(tag);
			}
		}
	}
}
