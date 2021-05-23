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
	m_Array.push_back(ProductTagString(ProductTag::ptPhenica, "пшеница"));
	m_Array.push_back(ProductTagString(ProductTag::ptKukuruza, "кукуруза"));
	m_Array.push_back(ProductTagString(ProductTag::ptMorkov, "морковь"));
	m_Array.push_back(ProductTagString(ProductTag::ptSaharniTrosnik, "сахарный тросник"));
	m_Array.push_back(ProductTagString(ProductTag::ptHlopok, "хлопок"));
	m_Array.push_back(ProductTagString(ProductTag::ptKlubnika, "клубника"));
	m_Array.push_back(ProductTagString(ProductTag::ptTomat, "томат"));
	m_Array.push_back(ProductTagString(ProductTag::ptSosna, "сосна"));
	m_Array.push_back(ProductTagString(ProductTag::ptKartofel, "картофель"));
	m_Array.push_back(ProductTagString(ProductTag::ptKakao, "какао"));
	m_Array.push_back(ProductTagString(ProductTag::ptKauchuk, "каучук"));
	m_Array.push_back(ProductTagString(ProductTag::ptShelk, "шелк"));
	m_Array.push_back(ProductTagString(ProductTag::ptPerec, "перец"));
	m_Array.push_back(ProductTagString(ProductTag::ptMoloko, "молоко"));
	m_Array.push_back(ProductTagString(ProductTag::ptYaco, "€йцо"));
	m_Array.push_back(ProductTagString(ProductTag::ptSherst, "шерсть"));
	m_Array.push_back(ProductTagString(ProductTag::ptHleb, "хлеб"));
	m_Array.push_back(ProductTagString(ProductTag::ptPechenie, "печенье"));
	m_Array.push_back(ProductTagString(ProductTag::ptBublic, "бублик"));
	m_Array.push_back(ProductTagString(ProductTag::ptPizza, "пицца"));
	m_Array.push_back(ProductTagString(ProductTag::ptKartofelHleb, "картофельный хлеб"));
	m_Array.push_back(ProductTagString(ProductTag::ptBananaHleb, "банановый хлеб"));
	m_Array.push_back(ProductTagString(ProductTag::ptClivki, "сливки"));
	m_Array.push_back(ProductTagString(ProductTag::ptSyr, "сыр"));
	m_Array.push_back(ProductTagString(ProductTag::ptMaslo, "масло"));
	m_Array.push_back(ProductTagString(ProductTag::ptIogury, "йогурт"));
	m_Array.push_back(ProductTagString(ProductTag::ptPersikIogurt, "персиковый йогурт"));
	m_Array.push_back(ProductTagString(ProductTag::ptHlopokTkan, "хлопкова€ ткань"));
	m_Array.push_back(ProductTagString(ProductTag::ptPryaja, "пр€жа"));
	m_Array.push_back(ProductTagString(ProductTag::ptShelkNit, "шелкова€ ткань"));
	m_Array.push_back(ProductTagString(ProductTag::ptRubashka, "рубашка"));
	m_Array.push_back(ProductTagString(ProductTag::ptSviter, "свитер"));
	m_Array.push_back(ProductTagString(ProductTag::ptPalto, "пальто"));
	m_Array.push_back(ProductTagString(ProductTag::ptShlapa, "шл€па"));
	m_Array.push_back(ProductTagString(ProductTag::ptPlatie, "платье"));
	m_Array.push_back(ProductTagString(ProductTag::ptKostum, "костюм"));
	m_Array.push_back(ProductTagString(ProductTag::ptPopkorn, "попкорн"));
	m_Array.push_back(ProductTagString(ProductTag::ptKukuruzaChips, "кукурузные чипсы"));
	m_Array.push_back(ProductTagString(ProductTag::ptGranola, "гранола"));
	m_Array.push_back(ProductTagString(ProductTag::ptChips, "чипсы"));
	m_Array.push_back(ProductTagString(ProductTag::ptkanope, "канопе"));
	m_Array.push_back(ProductTagString(ProductTag::ptMilkSheik, "милкшейк"));
	m_Array.push_back(ProductTagString(ProductTag::ptChisburger, "чизбургер"));
	m_Array.push_back(ProductTagString(ProductTag::ptSendvich, "сэндвич"));
	m_Array.push_back(ProductTagString(ProductTag::ptKartoshkaFree, "картошка фри"));
	m_Array.push_back(ProductTagString(ProductTag::ptPecheneiKartofel, "печеный картофель"));
	m_Array.push_back(ProductTagString(ProductTag::ptRezina, "резина"));
	m_Array.push_back(ProductTagString(ProductTag::ptPlastik, "пластик"));
	m_Array.push_back(ProductTagString(ProductTag::ptKley, "клей"));
	m_Array.push_back(ProductTagString(ProductTag::ptSahar, "сахар"));
	m_Array.push_back(ProductTagString(ProductTag::ptSirop, "сироп"));
	m_Array.push_back(ProductTagString(ProductTag::ptKaramel, "карамель"));
	m_Array.push_back(ProductTagString(ProductTag::ptMedovayaKaramel, "медова€ карамель"));
	m_Array.push_back(ProductTagString(ProductTag::ptBumaga, "бумага"));
	m_Array.push_back(ProductTagString(ProductTag::ptBumagaPolotence, "бумажные полотенца"));
	m_Array.push_back(ProductTagString(ProductTag::ptOboi, "обои"));
	m_Array.push_back(ProductTagString(ProductTag::ptKniga, "книга"));
	m_Array.push_back(ProductTagString(ProductTag::ptMorogenoe, "мороженное"));
	m_Array.push_back(ProductTagString(ProductTag::ptFruktLed, "фруктовый лед"));
	m_Array.push_back(ProductTagString(ProductTag::ptZamarojeniIogurt, "замороженный йогурт"));
	m_Array.push_back(ProductTagString(ProductTag::ptEscimo, "эскимо"));
	m_Array.push_back(ProductTagString(ProductTag::ptAnanasSorbet, "ананасовый сорбет"));
	m_Array.push_back(ProductTagString(ProductTag::ptKeks, "кекс"));
	m_Array.push_back(ProductTagString(ProductTag::ptShokoladPirog, "шоколадный пирог"));
	m_Array.push_back(ProductTagString(ProductTag::ptPirojenoe, "пироженое"));
	m_Array.push_back(ProductTagString(ProductTag::ptPoncik, "пончик"));
	m_Array.push_back(ProductTagString(ProductTag::ptChizkeyk, "чизкейк"));
}