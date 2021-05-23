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
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("���"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("�����"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("������"));
		m_Priority = PriorityTag::one;
		Init();
	}

	std::string GetFactName()
	{
		return "�������� �������";
	}
	void Calc()
	{
		int count = 0;
		int counter = 0;
		{
			//������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("������"), 1 * count);
			counter++;
		}
		{
			//������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("������"), 2 * count);
			counter++;
		}
		{
			//������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("������"), 3 * count);
			counter++;
		}
		{
			//������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("������"), 4 * count);
			counter++;
		}
	}

};

class CBakery : public CFactory
{
public:
	CBakery()
	{
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("����"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("�������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("�����"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("������������ ����"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("��������� ����"));
		m_Priority = PriorityTag::one;
		Init();
	}
	std::string GetFactName()
	{
		return "�������";
	}

	void Calc()
	{
		int count = 0;
		int counter = 0;
		{
			//����
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("�������"), 2 * count);
			counter++;
		}
		{
			//�������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("�������"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("����"), 2 * count);
			counter++;
		}
		{
			//������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("�������"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("����"), 3 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 3 * count);
			counter++;
		}
		{
			//�����
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("�������"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("���"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 2 * count);
			counter++;
		}

		{
			//������������ ����
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("�������"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("���������"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("����"), 4 * count);
			counter++;
		}

		{
			//��������� ����
			count = m_InputCount[5];
		}
	}

};

class �WeavingFactory : public CFactory
{
public:
	�WeavingFactory()
	{
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("��������� �����"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("�����"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("�������� �����"));
		m_Priority = PriorityTag::one;
		Init();
	}
	std::string GetFactName()
	{
		return "������� �������";
	}
	void Calc()
	{
		int count = 0;
		int counter = 0;
		{
			//��������� �����
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("������"), 2 * count);
			counter++;
		}
		{
			//�����
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("������"), 2 * count);
			counter++;
		}
		{
			//�������� �����
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("����"), 2 * count);
			counter++;
		}
	}

};

class CSewingFactory : public CFactory
{
public:
	CSewingFactory()
	{
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("�������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("�����"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("������"));
		m_Priority = PriorityTag::two;
		Init();
	}
	std::string GetFactName()
	{
		return "������� �������";
	}

	void Calc()
	{
		int count = 0;
		int counter = 0;
		{
			//�������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("��������� �����"), 1 * count);
			counter++;
		}
		{
			//������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 1 * count);
			counter++;
		}
		{
			//������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("��������� �����"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 1 * count);
			counter++;
		}
		{
			//�����
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("��������� �����"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("�������� �����"), 1 * count);
			counter++;
		}
		{
			//������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("�������� �����"), 1 * count);
			counter++;
		}
		{
			//������
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
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("�������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("���������� �����"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("�������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("�����"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("������"));
		m_Priority = PriorityTag::three;
		Init();
	}
	std::string GetFactName()
	{
		return "������� �������";
	}
	void Calc()
	{
		int count = 0;
		int counter = 0;
		{
			//�������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("��������"), 2 * count);
			counter++;
		}
		{
			//���������� �����
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("��������"), 3 * count);
			counter++;
		}
		{
			//�������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("�������"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("��������"), 2 * count);
			counter++;
		}
		{
			//�����
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("���������"), 2 * count);
			counter++;
		}
		{
			//������
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
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("��������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("���������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("�������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("�������� ���"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("������� ���������"));
		m_Priority = PriorityTag::three;
		Init();
	}
	std::string GetFactName()
	{
		return "������� ��������";
	}
	void Calc()
	{
		int count = 0;
		int counter = 0;
		{
			//��������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("������"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("��������"), 1 * count);
			counter++;
		}
		{
			//���������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("����"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("���"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 1 * count);
			counter++;
		}
		{
			//�������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("����"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("��������"), 2 * count);
			counter++;
		}
		{
			//�������� ���
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("���������"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("������"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 2 * count);
			counter++;
		}
		{
			//������� ���������
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
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("�������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("����"));
		m_Priority = PriorityTag::three;
		Init();
	}
	std::string GetFactName()
	{
		return "���������� �������";
	}
	void Calc()
	{
		
		int counter = 0;
		int count = 0;
		{
			//������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("������"), 1 * count);
			counter++;
		}
		{
			//�������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("������"), 3 * count);
			counter++;
		}
		{
			//����
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
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("�����"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("�����"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("��������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("������� ��������"));
		m_Priority = PriorityTag::two;
		Init();
	}
	std::string GetFactName()
	{
		return "�������� �������";
	}
	void Calc()
	{
		int counter = 0;
		int count = 0;
		{
			//�����
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("�������� �������"), 1 * count);
			counter++;
		}
		{
			//�����
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("�������� �������"), 2 * count);
			counter++;
		}
		{
			//��������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("�������� �������"), 3 * count);
			counter++;
		}
		{
			//������� ��������
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
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("�������� ���������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("����"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("�����"));
		m_Priority = PriorityTag::two;
		Init();
	}
	std::string GetFactName()
	{
		return "�������� �������";
	}
	void Calc()
	{
		int counter = 0;
		int count = 0;
		{
			//������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 1 * count);
			counter++;
		}
		{
			//�������� ���������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 2 * count);
			counter++;
		}
		{
			//����
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("������"), 1 * count);
			counter++;
		}
		{
			//�����
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
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("����������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("��������� ���"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("������������ ������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("���������� ������"));
		m_Priority = PriorityTag::three;
		Init();
	}
	std::string GetFactName()
	{
		return "������� �����������";
	}
	void Calc()
	{
		int counter = 0;
		int count = 0;
		{
			//����������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("������"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("������"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 1 * count);
			counter++;
		}
		{
			//��������� ���
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("��������"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 1 * count);
			counter++;
		}
		{
			//������������ ������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("������"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("������"), 1 * count);
			counter++;
		}
		{
			//������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 1 * count);
			counter++;
		}
		{
			//���������� ������
			count = m_InputCount[counter];

			counter++;
		}
	}
};

class �confectioneryFactory : public CFactory
{
public:
	�confectioneryFactory()
	{
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("����"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("���������� �����"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("���������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("������"));
		m_TagInputArray.push_back(GetAllProductSpisok()->GetTag("�������"));
		m_Priority = PriorityTag::three;
		Init();
	}
	std::string GetFactName()
	{
		return "������������";
	}
	void Calc()
	{
		int counter = 0;
		int count = 0;
		{
			//����
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("�������"), 3 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("����"), 4 * count);
			counter++;
		}
		{
			//���������� �����
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 2 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 1 * count);
			counter++;
		}
		{
			//���������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("����"), 5 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("������"), 1 * count);
			counter++;
		}
		{
			//������
			count = m_InputCount[counter];
			m_Result.Add(GetAllProductSpisok()->GetTag("������"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("��������"), 1 * count);
			m_Result.Add(GetAllProductSpisok()->GetTag("�����"), 1 * count);
			counter++;
		}
		{
			//�������
			count = m_InputCount[counter];

			counter++;
		}
	}
};