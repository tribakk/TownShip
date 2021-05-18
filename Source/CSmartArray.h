#pragma once
#include "ProductTag.h"
#include <atlcoll.h>

class CSmartArray
{
	typedef CAtlMap<ProductTag, int>::CPair ProductCount;
	CAtlMap<ProductTag, int> m_TagMap;
public:
	void Add(ProductTag tag, int count);
	void Add(const CString& name, int count);
	void Merge(CSmartArray& Arr);
	void ClearTag(ProductTag tag);

	int GetTagCount(ProductTag tag);
	void RemoveAll();
	void Print();
	bool IsEmpty();
	void ExcludeWhatHave(CSmartArray& Arr);
};