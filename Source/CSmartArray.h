#pragma once
#include "ProductTag.h"
#include <map>

class CSmartArray
{
	std::map<ProductTag, int> m_TagMap;
public:
	void Add(ProductTag tag, int count);
	void Add(const std::string& name, int count);
	void Merge(CSmartArray& Arr);
	void ClearTag(ProductTag tag);

	int GetTagCount(ProductTag tag);
	void RemoveAll();
	void Print();
	bool IsEmpty();
	void ExcludeWhatHave(CSmartArray& Arr);
};