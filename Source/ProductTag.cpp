#pragma once
#include "stdafx.h"
#include "ProductTag.h"
#include <atlcoll.h>

CAllProductSpisok* GetAllProductSpisok()
{
	static CAllProductSpisok spisok;
	return &spisok;
}


std::string CAllProductSpisok::GetName(ProductTag tag)
{
	std::string name;
	for (auto iter = m_Array.begin(); iter != m_Array.end(); iter++)
	{
		if (iter->m_Tag == tag)
		{
			name = iter->m_Name;
			break;
		}
	}
	return name;
}
ProductTag CAllProductSpisok::GetTag(std::string Name)
{
	ProductTag tag = ProductTag::ptNotFound;
	for (auto iter = m_Array.begin(); iter != m_Array.end(); iter++)
	{
		if (iter->m_Name.compare(Name) == 0)
		{
			tag = iter->m_Tag;
			break;
		}
	}
	if (tag == ProductTag::ptNotFound)
	{
		printf("BIG ERROR: %s\r\n", Name.c_str());
	}

	return tag;
}

CAllProductSpisok::CAllProductSpisok()
{
	m_Array.push_back(ProductTagString(ProductTag::ptPhenica, "�������"));
	m_Array.push_back(ProductTagString(ProductTag::ptKukuruza, "��������"));
	m_Array.push_back(ProductTagString(ProductTag::ptMorkov, "�������"));
	m_Array.push_back(ProductTagString(ProductTag::ptSaharniTrosnik, "�������� �������"));
	m_Array.push_back(ProductTagString(ProductTag::ptHlopok, "������"));
	m_Array.push_back(ProductTagString(ProductTag::ptKlubnika, "��������"));
	m_Array.push_back(ProductTagString(ProductTag::ptTomat, "�����"));
	m_Array.push_back(ProductTagString(ProductTag::ptSosna, "�����"));
	m_Array.push_back(ProductTagString(ProductTag::ptKartofel, "���������"));
	m_Array.push_back(ProductTagString(ProductTag::ptKakao, "�����"));
	m_Array.push_back(ProductTagString(ProductTag::ptKauchuk, "������"));
	m_Array.push_back(ProductTagString(ProductTag::ptShelk, "����"));
	m_Array.push_back(ProductTagString(ProductTag::ptPerec, "�����"));
	m_Array.push_back(ProductTagString(ProductTag::ptMoloko, "������"));
	m_Array.push_back(ProductTagString(ProductTag::ptYaco, "����"));
	m_Array.push_back(ProductTagString(ProductTag::ptSherst, "������"));
	m_Array.push_back(ProductTagString(ProductTag::ptHleb, "����"));
	m_Array.push_back(ProductTagString(ProductTag::ptPechenie, "�������"));
	m_Array.push_back(ProductTagString(ProductTag::ptBublic, "������"));
	m_Array.push_back(ProductTagString(ProductTag::ptPizza, "�����"));
	m_Array.push_back(ProductTagString(ProductTag::ptKartofelHleb, "������������ ����"));
	m_Array.push_back(ProductTagString(ProductTag::ptBananaHleb, "��������� ����"));
	m_Array.push_back(ProductTagString(ProductTag::ptClivki, "������"));
	m_Array.push_back(ProductTagString(ProductTag::ptSyr, "���"));
	m_Array.push_back(ProductTagString(ProductTag::ptMaslo, "�����"));
	m_Array.push_back(ProductTagString(ProductTag::ptIogury, "������"));
	m_Array.push_back(ProductTagString(ProductTag::ptPersikIogurt, "���������� ������"));
	m_Array.push_back(ProductTagString(ProductTag::ptHlopokTkan, "��������� �����"));
	m_Array.push_back(ProductTagString(ProductTag::ptPryaja, "�����"));
	m_Array.push_back(ProductTagString(ProductTag::ptShelkNit, "�������� �����"));
	m_Array.push_back(ProductTagString(ProductTag::ptRubashka, "�������"));
	m_Array.push_back(ProductTagString(ProductTag::ptSviter, "������"));
	m_Array.push_back(ProductTagString(ProductTag::ptPalto, "������"));
	m_Array.push_back(ProductTagString(ProductTag::ptShlapa, "�����"));
	m_Array.push_back(ProductTagString(ProductTag::ptPlatie, "������"));
	m_Array.push_back(ProductTagString(ProductTag::ptKostum, "������"));
	m_Array.push_back(ProductTagString(ProductTag::ptPopkorn, "�������"));
	m_Array.push_back(ProductTagString(ProductTag::ptKukuruzaChips, "���������� �����"));
	m_Array.push_back(ProductTagString(ProductTag::ptGranola, "�������"));
	m_Array.push_back(ProductTagString(ProductTag::ptChips, "�����"));
	m_Array.push_back(ProductTagString(ProductTag::ptkanope, "������"));
	m_Array.push_back(ProductTagString(ProductTag::ptMilkSheik, "��������"));
	m_Array.push_back(ProductTagString(ProductTag::ptChisburger, "���������"));
	m_Array.push_back(ProductTagString(ProductTag::ptSendvich, "�������"));
	m_Array.push_back(ProductTagString(ProductTag::ptKartoshkaFree, "�������� ���"));
	m_Array.push_back(ProductTagString(ProductTag::ptPecheneiKartofel, "������� ���������"));
	m_Array.push_back(ProductTagString(ProductTag::ptRezina, "������"));
	m_Array.push_back(ProductTagString(ProductTag::ptPlastik, "�������"));
	m_Array.push_back(ProductTagString(ProductTag::ptKley, "����"));
	m_Array.push_back(ProductTagString(ProductTag::ptSahar, "�����"));
	m_Array.push_back(ProductTagString(ProductTag::ptSirop, "�����"));
	m_Array.push_back(ProductTagString(ProductTag::ptKaramel, "��������"));
	m_Array.push_back(ProductTagString(ProductTag::ptMedovayaKaramel, "������� ��������"));
	m_Array.push_back(ProductTagString(ProductTag::ptBumaga, "������"));
	m_Array.push_back(ProductTagString(ProductTag::ptBumagaPolotence, "�������� ���������"));
	m_Array.push_back(ProductTagString(ProductTag::ptOboi, "����"));
	m_Array.push_back(ProductTagString(ProductTag::ptKniga, "�����"));
	m_Array.push_back(ProductTagString(ProductTag::ptMorogenoe, "����������"));
	m_Array.push_back(ProductTagString(ProductTag::ptFruktLed, "��������� ���"));
	m_Array.push_back(ProductTagString(ProductTag::ptZamarojeniIogurt, "������������ ������"));
	m_Array.push_back(ProductTagString(ProductTag::ptEscimo, "������"));
	m_Array.push_back(ProductTagString(ProductTag::ptAnanasSorbet, "���������� ������"));
	m_Array.push_back(ProductTagString(ProductTag::ptKeks, "����"));
	m_Array.push_back(ProductTagString(ProductTag::ptShokoladPirog, "���������� �����"));
	m_Array.push_back(ProductTagString(ProductTag::ptPirojenoe, "���������"));
	m_Array.push_back(ProductTagString(ProductTag::ptPoncik, "������"));
	m_Array.push_back(ProductTagString(ProductTag::ptChizkeyk, "�������"));
}