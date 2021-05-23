#pragma once
#include "CSmartArray.h"

class CFactory
{
protected:
	std::vector<ProductTag> m_TagInputArray;
	std::vector<int> m_InputCount;
	CSmartArray  m_SmartInput;
	CSmartArray m_Result;
	PriorityTag m_Priority;
	void Init()
	{
		size_t count = m_TagInputArray.size();
		for (size_t i = 0; i < count; i++)
		{
			m_InputCount.push_back(0);
		}
	}
public:
	virtual void Calc() = 0;
	virtual std::string GetFactName() = 0;
	void SetInput(CSmartArray& Array)
	{
		size_t count = m_TagInputArray.size();
		for (size_t i = 0; i < count; i++)
		{
			ProductTag tag = m_TagInputArray[i];
			int ProductCount = Array.GetTagCount(tag);
			m_InputCount[i] = ProductCount;
			m_SmartInput.Add(tag, ProductCount);
			Array.ClearTag(tag);
		}
	}
	PriorityTag GetPriorety()
	{
		return m_Priority;
	}
	//void ClearSmartInput()
	//{
	//	m_SmartInput.RemoveAll();
	//}
	void UpdateResult(CSmartArray& arr)
	{
		arr.Merge(m_Result);
		m_Result.RemoveAll();
	}
	CSmartArray* GetResult()
	{
		return &m_Result;
	}

	void AddResult(std::string name, int count)
	{
		m_Result.Add(GetAllProductSpisok()->GetTag(name), count);
	}
	void Print()
	{
		if (m_SmartInput.IsEmpty())
			return;
		OutputDebugStringA((GetFactName() + "\n\r").c_str());
		m_SmartInput.Print();
	}
	void Merge(CSmartArray& Array)
	{
		Array.Merge(m_SmartInput);
	}
};

class CMilkFactory : public CFactory
{
public:
	CMilkFactory()
	{
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("сливки"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("сыр"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("масло"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("йогурт"));
		m_Priority = PriorityTag::one;
		Init();
	}

	std::string GetFactName()
	{
		return "Молочная фабрика";
	}
	void Calc()
	{
		int count = 0;
		int counter = 0;
		{
			//сливки
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("молоко"), 1 * count);
			counter++;
		}
		{
			//сливки
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("молоко"), 2 * count);
			counter++;
		}
		{
			//сливки
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("молоко"), 3 * count);
			counter++;
		}
		{
			//сливки
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("молоко"), 4 * count);
			counter++;
		}
	}

};

class CBakery : public CFactory
{
public:
	CBakery()
	{
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("хлеб"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("печенье"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("бублик"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("пицца"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("картофельный хлеб"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("банановый хлеб"));
		m_Priority = PriorityTag::one;
		Init();
	}
	std::string GetFactName()
	{
		return "пекарня";
	}

	void Calc()
	{
		int count = 0;
		int counter = 0;
		{
			//хлеб
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("пшеница"), 2 * count);
			counter++;
		}
		{
			//печенье
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("пшеница"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("яйцо"), 2 * count);
			counter++;
		}
		{
			//бублик
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("пшеница"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("яйцо"), 3 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("сахар"), 3 * count);
			counter++;
		}
		{
			//пицца
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("пшеница"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("сыр"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("томат"), 2 * count);
			counter++;
		}

		{
			//картофельный хлеб
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("пшеница"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("картофель"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("яйцо"), 4 * count);
			counter++;
		}

		{
			//банановый хлеб
			count = m_InputCount[5];
		}
	}

};

class СWeavingFactory : public CFactory
{
public:
	СWeavingFactory()
	{
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("хлопковая ткань"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("пряжа"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("шелковая ткань"));
		m_Priority = PriorityTag::one;
		Init();
	}
	std::string GetFactName()
	{
		return "Ткацкая фабрика";
	}
	void Calc()
	{
		int count = 0;
		int counter = 0;
		{
			//хлопковая ткань
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("хлопок"), 2 * count);
			counter++;
		}
		{
			//пряжа
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("шерсть"), 2 * count);
			counter++;
		}
		{
			//шелковая ткань
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("шелк"), 2 * count);
			counter++;
		}
	}

};

class CSewingFactory : public CFactory
{
public:
	CSewingFactory()
	{
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("рубашка"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("свитер"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("пальто"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("шляпа"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("платье"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("костюм"));
		m_Priority = PriorityTag::two;
		Init();
	}
	std::string GetFactName()
	{
		return "Швейная фабрика";
	}

	void Calc()
	{
		int count = 0;
		int counter = 0;
		{
			//рубашка
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("хлопковая ткань"), 1 * count);
			counter++;
		}
		{
			//свитер
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("пряжа"), 1 * count);
			counter++;
		}
		{
			//пальто
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("хлопковая ткань"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("пряжа"), 1 * count);
			counter++;
		}
		{
			//шляпа
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("хлопковая ткань"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("шелковая ткань"), 1 * count);
			counter++;
		}
		{
			//платье
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("пряжа"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("шелковая ткань"), 1 * count);
			counter++;
		}
		{
			//костюм
			count = m_InputCount[counter];

			counter++;
		}
	}

};

class CSnackFactory : public CFactory
{
public:
	CSnackFactory()
	{
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("попкорн"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("кукурузные чипсы"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("гранола"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("чипсы"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("канопе"));
		m_Priority = PriorityTag::three;
		Init();
	}
	std::string GetFactName()
	{
		return "Фабрика закусок";
	}
	void Calc()
	{
		int count = 0;
		int counter = 0;
		{
			//попкорн
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("кукуруза"), 2 * count);
			counter++;
		}
		{
			//кукурузные чипсы
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("кукуруза"), 3 * count);
			counter++;
		}
		{
			//гранола
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("пшеница"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("клубника"), 2 * count);
			counter++;
		}
		{
			//чипсы
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("картофель"), 2 * count);
			counter++;
		}
		{
			//канапе
			count = m_InputCount[counter];

			counter++;
		}
	}
};

class CFastFoodFactory : public CFactory
{
public:
	CFastFoodFactory()
	{
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("милкшейк"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("чизбургер"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("сэндвич"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("картошка фри"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("печеный картофель"));
		m_Priority = PriorityTag::three;
		Init();
	}
	std::string GetFactName()
	{
		return "Фабрика фастфуда";
	}
	void Calc()
	{
		int count = 0;
		int counter = 0;
		{
			//милкшейк
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("молоко"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("клубника"), 1 * count);
			counter++;
		}
		{
			//чизбургер
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("хлеб"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("сыр"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("томат"), 1 * count);
			counter++;
		}
		{
			//сэндвич
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("хлеб"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("масло"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("клубника"), 2 * count);
			counter++;
		}
		{
			//картошка фри
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("картофель"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("сливки"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("томат"), 2 * count);
			counter++;
		}
		{
			//печеный картофель
			count = m_InputCount[counter];

			counter++;
		}
	}
};

class CRubberFactory : public CFactory
{
public:
	CRubberFactory()
	{
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("резина"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("пластик"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("клей"));
		m_Priority = PriorityTag::three;
		Init();
	}
	std::string GetFactName()
	{
		return "Каучуковая фабрика";
	}
	void Calc()
	{
		
		int counter = 0;
		int count = 0;
		{
			//резина
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("каучук"), 1 * count);
			counter++;
		}
		{
			//пластик
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("каучук"), 3 * count);
			counter++;
		}
		{
			//клей
			count = m_InputCount[counter];
			
			counter++;
		}
	}
};

class CSugarFactory : public CFactory
{
public:
	CSugarFactory()
	{
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("сахар"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("сироп"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("карамель"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("медовая карамель"));
		m_Priority = PriorityTag::two;
		Init();
	}
	std::string GetFactName()
	{
		return "Сахарная фабрика";
	}
	void Calc()
	{
		int counter = 0;
		int count = 0;
		{
			//сахар
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("сахарный тросник"), 1 * count);
			counter++;
		}
		{
			//сироп
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("сахарный тросник"), 2 * count);
			counter++;
		}
		{
			//карамель
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("сахарный тросник"), 3 * count);
			counter++;
		}
		{
			//медовая карамель
			count = m_InputCount[counter];

			counter++;
		}
	}
};

class CPaperFactory : public CFactory
{
public:
	CPaperFactory()
	{
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("бумага"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("бумажные полотенца"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("обои"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("книга"));
		m_Priority = PriorityTag::two;
		Init();
	}
	std::string GetFactName()
	{
		return "Бумажная фабрика";
	}
	void Calc()
	{
		int counter = 0;
		int count = 0;
		{
			//бумага
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("сосна"), 1 * count);
			counter++;
		}
		{
			//бумажные полотенца
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("сосна"), 2 * count);
			counter++;
		}
		{
			//обои
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("сосна"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("резина"), 1 * count);
			counter++;
		}
		{
			//книга
			count = m_InputCount[counter];

			counter++;
		}
	}
};

class CIceCreamFactory : public CFactory
{
public:
	CIceCreamFactory()
	{
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("мороженное"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("фруктовый лед"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("замороженный йогурт"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("эскимо"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("ананасовый сорбет"));
		m_Priority = PriorityTag::three;
		Init();
	}
	std::string GetFactName()
	{
		return "Фабрика мороженного";
	}
	void Calc()
	{
		int counter = 0;
		int count = 0;
		{
			//мороженное
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("молоко"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("сливки"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("сахар"), 1 * count);
			counter++;
		}
		{
			//фруктовый лед
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("клубника"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("сахар"), 1 * count);
			counter++;
		}
		{
			//замороженный йогурт
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("йогурт"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("сливки"), 1 * count);
			counter++;
		}
		{
			//эскимо
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("сироп"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("какао"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("сосна"), 1 * count);
			counter++;
		}
		{
			//ананасовый сорбет
			count = m_InputCount[counter];

			counter++;
		}
	}
};

class СconfectioneryFactory : public CFactory
{
public:
	СconfectioneryFactory()
	{
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("кекс"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("шоколадный пирог"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("пироженое"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("пончик"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("чизкейк"));
		m_Priority = PriorityTag::three;
		Init();
	}
	std::string GetFactName()
	{
		return "Кондитерская";
	}
	void Calc()
	{
		int counter = 0;
		int count = 0;
		{
			//кекс
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("пшеница"), 3 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("сахар"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("яйцо"), 4 * count);
			counter++;
		}
		{
			//шоколадный пирог
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("какао"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("сироп"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("масло"), 1 * count);
			counter++;
		}
		{
			//пироженое
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("сахар"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("яйцо"), 5 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("сливки"), 1 * count);
			counter++;
		}
		{
			//пончик
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("бублик"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("карамель"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("какао"), 1 * count);
			counter++;
		}
		{
			//чизкейк
			count = m_InputCount[counter];

			counter++;
		}
	}
};