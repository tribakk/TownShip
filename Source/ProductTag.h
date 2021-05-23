#pragma once
#include <string>
#include <vector>

class CAllProductSpisok;
CAllProductSpisok* GetAllProductSpisok();

enum PriorityTag
{
	one = 1,
	two = 2,
	three = 3
};

enum ProductTag
{
	ptNotFound = 0,
	ptPhenica = 1,
	ptKukuruza = 2,
	ptMorkov = 3,
	ptSaharniTrosnik = 4,
	ptHlopok = 5,
	ptKlubnika = 6,
	ptTomat = 7,
	ptSosna = 8,
	ptKartofel = 9,
	ptKakao = 10,
	ptKauchuk = 11,
	ptShelk = 12,
	ptPerec = 13,
	ptMoloko = 14,
	ptYaco = 15,
	ptSherst = 16,
	ptHleb = 17,
	ptPechenie = 18,
	ptBublic = 19,
	ptPizza = 20,
	ptKartofelHleb = 21,
	ptBananaHleb = 22,
	ptClivki = 23,
	ptSyr = 24,
	ptMaslo = 25,
	ptIogury = 26,
	ptPersikIogurt = 27,
	ptHlopokTkan = 28,
	ptPryaja = 29,
	ptShelkNit = 30,
	ptRubashka = 31,
	ptSviter = 32,
	ptPalto = 33,
	ptShlapa = 34,
	ptPlatie = 35,
	ptKostum = 36,
	ptPopkorn = 37,
	ptKukuruzaChips = 38,
	ptGranola = 39,
	ptChips = 40,
	ptMilkSheik = 41,
	ptChisburger = 42,
	ptSendvich = 43,
	ptKartoshkaFree = 44,
	ptPecheneiKartofel = 45,
	ptRezina = 46,
	ptPlastik = 47,
	ptKley = 48,
	ptSahar = 49,
	ptSirop = 50,
	ptKaramel = 51,
	ptMedovayaKaramel = 52,
	ptBumaga = 53,
	ptBumagaPolotence = 54,
	ptOboi = 55,
	ptKniga = 56,
	ptMorogenoe = 57,
	ptFruktLed = 58,
	ptZamarojeniIogurt = 59,
	ptEscimo = 60,
	ptAnanasSorbet = 61,
	ptKeks = 62,
	ptShokoladPirog = 63,
	ptPirojenoe = 64,
	ptPoncik = 65,
	ptChizkeyk = 66,
	ptkanope = 67

};

class ProductTagString
{
public:
	ProductTag m_Tag;
	std::string m_Name;
	ProductTagString(ProductTag tag, std::string name)
		: m_Tag(tag)
		, m_Name(name)
	{

	}
};

class CAllProductSpisok
{
	friend CAllProductSpisok* GetAllProductSpisok();
	std::vector<ProductTagString> m_Array;
public:
	std::string GetName(ProductTag tag);
	ProductTag GetTag(std::string Name);
private:
	//создать можно только из GetAllProductSpisok
	CAllProductSpisok(const CAllProductSpisok&) = delete;
	CAllProductSpisok(CAllProductSpisok&&) = delete;
	CAllProductSpisok& CAllProductSpisok::operator=(const CAllProductSpisok&) = delete;
	CAllProductSpisok& CAllProductSpisok::operator=(CAllProductSpisok&&) = delete;
	CAllProductSpisok();
};


