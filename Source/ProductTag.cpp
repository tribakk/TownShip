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
	m_Array.Add(ProductTagString(ProductTag::ptPhenica, _T("пшеница")));
	m_Array.Add(ProductTagString(ProductTag::ptKukuruza, _T("кукуруза")));
	m_Array.Add(ProductTagString(ProductTag::ptMorkov, _T("морковь")));
	m_Array.Add(ProductTagString(ProductTag::ptSaharniTrosnik, _T("сахарный тросник")));
	m_Array.Add(ProductTagString(ProductTag::ptHlopok, _T("хлопок")));
	m_Array.Add(ProductTagString(ProductTag::ptKlubnika, _T("клубника")));
	m_Array.Add(ProductTagString(ProductTag::ptTomat, _T("томат")));
	m_Array.Add(ProductTagString(ProductTag::ptSosna, _T("сосна")));
	m_Array.Add(ProductTagString(ProductTag::ptKartofel, _T("картофель")));
	m_Array.Add(ProductTagString(ProductTag::ptKakao, _T("какао")));
	m_Array.Add(ProductTagString(ProductTag::ptKauchuk, _T("каучук")));
	m_Array.Add(ProductTagString(ProductTag::ptShelk, _T("шелк")));
	m_Array.Add(ProductTagString(ProductTag::ptPerec, _T("перец")));
	m_Array.Add(ProductTagString(ProductTag::ptMoloko, _T("молоко")));
	m_Array.Add(ProductTagString(ProductTag::ptYaco, _T("€йцо")));
	m_Array.Add(ProductTagString(ProductTag::ptSherst, _T("шерсть")));
	m_Array.Add(ProductTagString(ProductTag::ptHleb, _T("хлеб")));
	m_Array.Add(ProductTagString(ProductTag::ptPechenie, _T("печенье")));
	m_Array.Add(ProductTagString(ProductTag::ptBublic, _T("бублик")));
	m_Array.Add(ProductTagString(ProductTag::ptPizza, _T("пицца")));
	m_Array.Add(ProductTagString(ProductTag::ptKartofelHleb, _T("картофельный хлеб")));
	m_Array.Add(ProductTagString(ProductTag::ptBananaHleb, _T("банановый хлеб")));
	m_Array.Add(ProductTagString(ProductTag::ptClivki, _T("сливки")));
	m_Array.Add(ProductTagString(ProductTag::ptSyr, _T("сыр")));
	m_Array.Add(ProductTagString(ProductTag::ptMaslo, _T("масло")));
	m_Array.Add(ProductTagString(ProductTag::ptIogury, _T("йогурт")));
	m_Array.Add(ProductTagString(ProductTag::ptPersikIogurt, _T("персиковый йогурт")));
	m_Array.Add(ProductTagString(ProductTag::ptHlopokTkan, _T("хлопкова€ ткань")));
	m_Array.Add(ProductTagString(ProductTag::ptPryaja, _T("пр€жа")));
	m_Array.Add(ProductTagString(ProductTag::ptShelkNit, _T("шелкова€ ткань")));
	m_Array.Add(ProductTagString(ProductTag::ptRubashka, _T("рубашка")));
	m_Array.Add(ProductTagString(ProductTag::ptSviter, _T("свитер")));
	m_Array.Add(ProductTagString(ProductTag::ptPalto, _T("пальто")));
	m_Array.Add(ProductTagString(ProductTag::ptShlapa, _T("шл€па")));
	m_Array.Add(ProductTagString(ProductTag::ptPlatie, _T("платье")));
	m_Array.Add(ProductTagString(ProductTag::ptKostum, _T("костюм")));
	m_Array.Add(ProductTagString(ProductTag::ptPopkorn, _T("попкорн")));
	m_Array.Add(ProductTagString(ProductTag::ptKukuruzaChips, _T("кукурузные чипсы")));
	m_Array.Add(ProductTagString(ProductTag::ptGranola, _T("гранола")));
	m_Array.Add(ProductTagString(ProductTag::ptChips, _T("чипсы")));
	m_Array.Add(ProductTagString(ProductTag::ptkanope, _T("канопе")));
	m_Array.Add(ProductTagString(ProductTag::ptMilkSheik, _T("милкшейк")));
	m_Array.Add(ProductTagString(ProductTag::ptChisburger, _T("чизбургер")));
	m_Array.Add(ProductTagString(ProductTag::ptSendvich, _T("сэндвич")));
	m_Array.Add(ProductTagString(ProductTag::ptKartoshkaFree, _T("картошка фри")));
	m_Array.Add(ProductTagString(ProductTag::ptPecheneiKartofel, _T("печеный картофель")));
	m_Array.Add(ProductTagString(ProductTag::ptRezina, _T("резина")));
	m_Array.Add(ProductTagString(ProductTag::ptPlastik, _T("пластик")));
	m_Array.Add(ProductTagString(ProductTag::ptKley, _T("клей")));
	m_Array.Add(ProductTagString(ProductTag::ptSahar, _T("сахар")));
	m_Array.Add(ProductTagString(ProductTag::ptSirop, _T("сироп")));
	m_Array.Add(ProductTagString(ProductTag::ptKaramel, _T("карамель")));
	m_Array.Add(ProductTagString(ProductTag::ptMedovayaKaramel, _T("медова€ карамель")));
	m_Array.Add(ProductTagString(ProductTag::ptBumaga, _T("бумага")));
	m_Array.Add(ProductTagString(ProductTag::ptBumagaPolotence, _T("бумажные полотенца")));
	m_Array.Add(ProductTagString(ProductTag::ptOboi, _T("обои")));
	m_Array.Add(ProductTagString(ProductTag::ptKniga, _T("книга")));
	m_Array.Add(ProductTagString(ProductTag::ptMorogenoe, _T("мороженное")));
	m_Array.Add(ProductTagString(ProductTag::ptFruktLed, _T("фруктовый лед")));
	m_Array.Add(ProductTagString(ProductTag::ptZamarojeniIogurt, _T("замороженный йогурт")));
	m_Array.Add(ProductTagString(ProductTag::ptEscimo, _T("эскимо")));
	m_Array.Add(ProductTagString(ProductTag::ptAnanasSorbet, _T("ананасовый сорбет")));
	m_Array.Add(ProductTagString(ProductTag::ptKeks, _T("кекс")));
	m_Array.Add(ProductTagString(ProductTag::ptShokoladPirog, _T("шоколадный пирог")));
	m_Array.Add(ProductTagString(ProductTag::ptPirojenoe, _T("пироженое")));
	m_Array.Add(ProductTagString(ProductTag::ptPoncik, _T("пончик")));
	m_Array.Add(ProductTagString(ProductTag::ptChizkeyk, _T("чизкейк")));
}