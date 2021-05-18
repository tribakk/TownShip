#pragma once
#include "stdafx.h"
#include "ProductTag.h"
#include <atlcoll.h>
#include <atlstr.h>

CAllProductSpisok* GetAllProductSpisok()
{
	static CAllProductSpisok spisok;
	return &spisok;
}


CString CAllProductSpisok::GetName(ProductTag tag)
{
	CString name;
	size_t count = m_Array.GetCount();
	for (size_t i = 0; i < count; i++)
	{
		if (m_Array[i].m_Tag == tag)
		{
			name = m_Array[i].m_Name;
			break;
		}
	}
	return name;
}
ProductTag CAllProductSpisok::GetTag(CString Name)
{
	ProductTag tag = ProductTag::ptNotFound;
	size_t count = m_Array.GetCount();
	for (size_t i = 0; i < count; i++)
	{
		if (m_Array[i].m_Name.CompareNoCase(Name) == 0)
		{
			tag = m_Array[i].m_Tag;
			break;
		}
	}
	if (tag == ProductTag::ptNotFound)
	{
		OutputDebugString(_T("BIG ERROR: ") + Name + _T("\n\r\r"));
	}

	return tag;
}

CAllProductSpisok::CAllProductSpisok()
{
	m_Array.Add(ProductTagString(ProductTag::ptPhenica, _T("�������")));
	m_Array.Add(ProductTagString(ProductTag::ptKukuruza, _T("��������")));
	m_Array.Add(ProductTagString(ProductTag::ptMorkov, _T("�������")));
	m_Array.Add(ProductTagString(ProductTag::ptSaharniTrosnik, _T("�������� �������")));
	m_Array.Add(ProductTagString(ProductTag::ptHlopok, _T("������")));
	m_Array.Add(ProductTagString(ProductTag::ptKlubnika, _T("��������")));
	m_Array.Add(ProductTagString(ProductTag::ptTomat, _T("�����")));
	m_Array.Add(ProductTagString(ProductTag::ptSosna, _T("�����")));
	m_Array.Add(ProductTagString(ProductTag::ptKartofel, _T("���������")));
	m_Array.Add(ProductTagString(ProductTag::ptKakao, _T("�����")));
	m_Array.Add(ProductTagString(ProductTag::ptKauchuk, _T("������")));
	m_Array.Add(ProductTagString(ProductTag::ptShelk, _T("����")));
	m_Array.Add(ProductTagString(ProductTag::ptPerec, _T("�����")));
	m_Array.Add(ProductTagString(ProductTag::ptMoloko, _T("������")));
	m_Array.Add(ProductTagString(ProductTag::ptYaco, _T("����")));
	m_Array.Add(ProductTagString(ProductTag::ptSherst, _T("������")));
	m_Array.Add(ProductTagString(ProductTag::ptHleb, _T("����")));
	m_Array.Add(ProductTagString(ProductTag::ptPechenie, _T("�������")));
	m_Array.Add(ProductTagString(ProductTag::ptBublic, _T("������")));
	m_Array.Add(ProductTagString(ProductTag::ptPizza, _T("�����")));
	m_Array.Add(ProductTagString(ProductTag::ptKartofelHleb, _T("������������ ����")));
	m_Array.Add(ProductTagString(ProductTag::ptBananaHleb, _T("��������� ����")));
	m_Array.Add(ProductTagString(ProductTag::ptClivki, _T("������")));
	m_Array.Add(ProductTagString(ProductTag::ptSyr, _T("���")));
	m_Array.Add(ProductTagString(ProductTag::ptMaslo, _T("�����")));
	m_Array.Add(ProductTagString(ProductTag::ptIogury, _T("������")));
	m_Array.Add(ProductTagString(ProductTag::ptPersikIogurt, _T("���������� ������")));
	m_Array.Add(ProductTagString(ProductTag::ptHlopokTkan, _T("��������� �����")));
	m_Array.Add(ProductTagString(ProductTag::ptPryaja, _T("�����")));
	m_Array.Add(ProductTagString(ProductTag::ptShelkNit, _T("�������� �����")));
	m_Array.Add(ProductTagString(ProductTag::ptRubashka, _T("�������")));
	m_Array.Add(ProductTagString(ProductTag::ptSviter, _T("������")));
	m_Array.Add(ProductTagString(ProductTag::ptPalto, _T("������")));
	m_Array.Add(ProductTagString(ProductTag::ptShlapa, _T("�����")));
	m_Array.Add(ProductTagString(ProductTag::ptPlatie, _T("������")));
	m_Array.Add(ProductTagString(ProductTag::ptKostum, _T("������")));
	m_Array.Add(ProductTagString(ProductTag::ptPopkorn, _T("�������")));
	m_Array.Add(ProductTagString(ProductTag::ptKukuruzaChips, _T("���������� �����")));
	m_Array.Add(ProductTagString(ProductTag::ptGranola, _T("�������")));
	m_Array.Add(ProductTagString(ProductTag::ptChips, _T("�����")));
	m_Array.Add(ProductTagString(ProductTag::ptkanope, _T("������")));
	m_Array.Add(ProductTagString(ProductTag::ptMilkSheik, _T("��������")));
	m_Array.Add(ProductTagString(ProductTag::ptChisburger, _T("���������")));
	m_Array.Add(ProductTagString(ProductTag::ptSendvich, _T("�������")));
	m_Array.Add(ProductTagString(ProductTag::ptKartoshkaFree, _T("�������� ���")));
	m_Array.Add(ProductTagString(ProductTag::ptPecheneiKartofel, _T("������� ���������")));
	m_Array.Add(ProductTagString(ProductTag::ptRezina, _T("������")));
	m_Array.Add(ProductTagString(ProductTag::ptPlastik, _T("�������")));
	m_Array.Add(ProductTagString(ProductTag::ptKley, _T("����")));
	m_Array.Add(ProductTagString(ProductTag::ptSahar, _T("�����")));
	m_Array.Add(ProductTagString(ProductTag::ptSirop, _T("�����")));
	m_Array.Add(ProductTagString(ProductTag::ptKaramel, _T("��������")));
	m_Array.Add(ProductTagString(ProductTag::ptMedovayaKaramel, _T("������� ��������")));
	m_Array.Add(ProductTagString(ProductTag::ptBumaga, _T("������")));
	m_Array.Add(ProductTagString(ProductTag::ptBumagaPolotence, _T("�������� ���������")));
	m_Array.Add(ProductTagString(ProductTag::ptOboi, _T("����")));
	m_Array.Add(ProductTagString(ProductTag::ptKniga, _T("�����")));
	m_Array.Add(ProductTagString(ProductTag::ptMorogenoe, _T("����������")));
	m_Array.Add(ProductTagString(ProductTag::ptFruktLed, _T("��������� ���")));
	m_Array.Add(ProductTagString(ProductTag::ptZamarojeniIogurt, _T("������������ ������")));
	m_Array.Add(ProductTagString(ProductTag::ptEscimo, _T("������")));
	m_Array.Add(ProductTagString(ProductTag::ptAnanasSorbet, _T("���������� ������")));
	m_Array.Add(ProductTagString(ProductTag::ptKeks, _T("����")));
	m_Array.Add(ProductTagString(ProductTag::ptShokoladPirog, _T("���������� �����")));
	m_Array.Add(ProductTagString(ProductTag::ptPirojenoe, _T("���������")));
	m_Array.Add(ProductTagString(ProductTag::ptPoncik, _T("������")));
	m_Array.Add(ProductTagString(ProductTag::ptChizkeyk, _T("�������")));
}