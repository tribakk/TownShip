#pragma once
#include "stdafx.h"
#include "CSmartArray.h"

void CSmartArray::Add(ProductTag tag, int count)
{
	if (count == 0)
		return;
	if (m_TagMap.find(tag) != m_TagMap.end())
		m_TagMap[tag] += count;
	else
		m_TagMap[tag] = count;
}
void CSmartArray::Add(const std::string& name, int count)
{
	ProductTag tag = GetAllProductSpisok()->GetTag(name);
	Add(tag, count);
}
void CSmartArray::Merge(CSmartArray& Arr)
{
	for (auto iter = Arr.m_TagMap.begin(); iter != Arr.m_TagMap.end(); iter++)
	{
		Add(iter->first, iter->second);
	}
}
void CSmartArray::ClearTag(ProductTag tag)
{
	m_TagMap.erase(tag);
}

int CSmartArray::GetTagCount(ProductTag tag)
{
	int count = 0;
	if (m_TagMap.find(tag) != m_TagMap.end())
		count = m_TagMap[tag];
	return count;
}
void CSmartArray::RemoveAll()
{
	m_TagMap.clear();
}
void CSmartArray::Print()
{
	for (auto iter = m_TagMap.begin(); iter != m_TagMap.end(); iter++)
	{
		ProductTag tag = iter->first;
		int count = iter->second;
		std::string tagName = GetAllProductSpisok()->GetName(tag);
		std::string text = tagName + " - " + std::to_string(count);
		OutputDebugStringA(text.c_str());
	}
}
bool CSmartArray::IsEmpty()
{
	return m_TagMap.empty();
}

void CSmartArray::ExcludeWhatHave(CSmartArray& Arr)
{
	std::vector<ProductTag> tagVector;
	for (auto iter = m_TagMap.begin(); iter != m_TagMap.end(); iter++)
	{
		tagVector.push_back(iter->first);
	}
	for (auto iter = tagVector.begin(); iter != tagVector.end(); iter++)
	{
		ProductTag tag = *iter;
		int value = m_TagMap[tag];
		if (int count = Arr.GetTagCount(tag))
		{
			if (value > count)
			{
				Add(tag, -count);
				Arr.ClearTag(tag);
			}
			else if (value < count)
			{
				ClearTag(tag);
				Arr.Add(tag, -value);
			}
			else //одинаковое значение
			{
				ClearTag(tag);
				Arr.ClearTag(tag);
			}
		}
	}
}
