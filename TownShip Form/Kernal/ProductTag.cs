using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TownShip_Form.Kernal
{

    enum PriorityTag
    {
        one = 1,
        two = 2,
        three = 3
    };

    public enum ProductTag
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
        ptkanope = 67,
        //корм для животных
        ptKormKorova = 68,
        prKormKurica = 69,
        ptKormOvca = 70,
        prKormPchela = 71,
        //фабрика джема
        ptKlubnikaVarenie = 72,
        ptPersikVarenie = 73,
        ptArbuzVarenie = 74,
        ptSlivaVarenie = 75,
        //фрукт с острова
        ptPersik = 76,
        ptArbuz = 77,
        ptSliva = 78,

        //
        ptSotiMed = 79,
        ptPlasticButilka = 80,
        ptToy = 81
    };

    public class ProductTagString
    {
	    public ProductTag mag;
        public String m_Name;
        public ProductTagString(ProductTag tag, String name)
        {
            mag = tag;
            m_Name = name;
        }
    };

    public class CAllProductSpisok
    {
        List<ProductTagString> m_Array = new List<ProductTagString>();
        public String GetName(ProductTag tag)
        {
            String name = "";
            int count = m_Array.Count;
            for (int i = 0; i < count; i++)
            {
                
                if (m_Array[i].mag == tag)
                {
                    name = m_Array[i].m_Name;
                    break;
                }
            }
            return name;
        }
        public ProductTag GetTag(String Name)
        {
            ProductTag tag = ProductTag.ptNotFound;
            int count = m_Array.Count();
            for (int i = 0; i < count; i++)
            {
                if (m_Array[i].m_Name == Name)
                {
                    tag = m_Array[i].mag;
                    break;
                }
            }
            if (Name != "" && tag == ProductTag.ptNotFound)
            {
                System.Diagnostics.Debug.Assert(false, Name);
                //OutputDebugString(("BIG ERROR: ") + Name + ("\n\r\r"));
            }

            return tag;
        }

        public int GetCount()
        {
            return m_Array.Count;
        }

        public CAllProductSpisok()
        {
            m_Array.Add(new ProductTagString(ProductTag.ptPhenica, ("пшеница")));
            m_Array.Add(new ProductTagString(ProductTag.ptKukuruza, ("кукуруза")));
            m_Array.Add(new ProductTagString(ProductTag.ptMorkov, ("морковь")));
            m_Array.Add(new ProductTagString(ProductTag.ptSaharniTrosnik, ("сахарный тросник")));
            m_Array.Add(new ProductTagString(ProductTag.ptHlopok, ("хлопок")));
            m_Array.Add(new ProductTagString(ProductTag.ptKlubnika, ("клубника")));
            m_Array.Add(new ProductTagString(ProductTag.ptTomat, ("томат")));
            m_Array.Add(new ProductTagString(ProductTag.ptSosna, ("сосна")));
            m_Array.Add(new ProductTagString(ProductTag.ptKartofel, ("картофель")));
            m_Array.Add(new ProductTagString(ProductTag.ptKakao, ("какао")));
            m_Array.Add(new ProductTagString(ProductTag.ptKauchuk, ("каучук")));
            m_Array.Add(new ProductTagString(ProductTag.ptShelk, ("шелк")));
            m_Array.Add(new ProductTagString(ProductTag.ptPerec, ("перец")));
            m_Array.Add(new ProductTagString(ProductTag.ptMoloko, ("молоко")));
            m_Array.Add(new ProductTagString(ProductTag.ptYaco, ("яйцо")));
            m_Array.Add(new ProductTagString(ProductTag.ptSherst, ("шерсть")));
            m_Array.Add(new ProductTagString(ProductTag.ptHleb, ("хлеб")));
            m_Array.Add(new ProductTagString(ProductTag.ptPechenie, ("печенье")));
            m_Array.Add(new ProductTagString(ProductTag.ptBublic, ("бублик")));
            m_Array.Add(new ProductTagString(ProductTag.ptPizza, ("пицца")));
            m_Array.Add(new ProductTagString(ProductTag.ptKartofelHleb, ("картофельный хлеб")));
            m_Array.Add(new ProductTagString(ProductTag.ptBananaHleb, ("банановый хлеб")));
            m_Array.Add(new ProductTagString(ProductTag.ptClivki, ("сливки")));
            m_Array.Add(new ProductTagString(ProductTag.ptSyr, ("сыр")));
            m_Array.Add(new ProductTagString(ProductTag.ptMaslo, ("масло")));
            m_Array.Add(new ProductTagString(ProductTag.ptIogury, ("йогурт")));
            m_Array.Add(new ProductTagString(ProductTag.ptPersikIogurt, ("персиковый йогурт")));
            m_Array.Add(new ProductTagString(ProductTag.ptHlopokTkan, ("хлопковая ткань")));
            m_Array.Add(new ProductTagString(ProductTag.ptPryaja, ("пряжа")));
            m_Array.Add(new ProductTagString(ProductTag.ptShelkNit, ("шелковая ткань")));
            m_Array.Add(new ProductTagString(ProductTag.ptRubashka, ("рубашка")));
            m_Array.Add(new ProductTagString(ProductTag.ptSviter, ("свитер")));
            m_Array.Add(new ProductTagString(ProductTag.ptPalto, ("пальто")));
            m_Array.Add(new ProductTagString(ProductTag.ptShlapa, ("шляпа")));
            m_Array.Add(new ProductTagString(ProductTag.ptPlatie, ("платье")));
            m_Array.Add(new ProductTagString(ProductTag.ptKostum, ("костюм")));
            m_Array.Add(new ProductTagString(ProductTag.ptPopkorn, ("попкорн")));
            m_Array.Add(new ProductTagString(ProductTag.ptKukuruzaChips, ("кукурузные чипсы")));
            m_Array.Add(new ProductTagString(ProductTag.ptGranola, ("гранола")));
            m_Array.Add(new ProductTagString(ProductTag.ptChips, ("чипсы")));
            m_Array.Add(new ProductTagString(ProductTag.ptkanope, ("канопе")));
            m_Array.Add(new ProductTagString(ProductTag.ptMilkSheik, ("милкшейк")));
            m_Array.Add(new ProductTagString(ProductTag.ptChisburger, ("чизбургер")));
            m_Array.Add(new ProductTagString(ProductTag.ptSendvich, ("сэндвич")));
            m_Array.Add(new ProductTagString(ProductTag.ptKartoshkaFree, ("картошка фри")));
            m_Array.Add(new ProductTagString(ProductTag.ptPecheneiKartofel, ("печеный картофель")));
            m_Array.Add(new ProductTagString(ProductTag.ptRezina, ("резина")));
            m_Array.Add(new ProductTagString(ProductTag.ptPlastik, ("пластик")));
            m_Array.Add(new ProductTagString(ProductTag.ptKley, ("клей")));
            m_Array.Add(new ProductTagString(ProductTag.ptSahar, ("сахар")));
            m_Array.Add(new ProductTagString(ProductTag.ptSirop, ("сироп")));
            m_Array.Add(new ProductTagString(ProductTag.ptKaramel, ("карамель")));
            m_Array.Add(new ProductTagString(ProductTag.ptMedovayaKaramel, ("медовая карамель")));
            m_Array.Add(new ProductTagString(ProductTag.ptBumaga, ("бумага")));
            m_Array.Add(new ProductTagString(ProductTag.ptBumagaPolotence, ("бумажные полотенца")));
            m_Array.Add(new ProductTagString(ProductTag.ptOboi, ("обои")));
            m_Array.Add(new ProductTagString(ProductTag.ptKniga, ("книга")));
            m_Array.Add(new ProductTagString(ProductTag.ptMorogenoe, ("мороженное")));
            m_Array.Add(new ProductTagString(ProductTag.ptFruktLed, ("фруктовый лед")));
            m_Array.Add(new ProductTagString(ProductTag.ptZamarojeniIogurt, ("замороженный йогурт")));
            m_Array.Add(new ProductTagString(ProductTag.ptEscimo, ("эскимо")));
            m_Array.Add(new ProductTagString(ProductTag.ptAnanasSorbet, ("ананасовый сорбет")));
            m_Array.Add(new ProductTagString(ProductTag.ptKeks, ("кекс")));
            m_Array.Add(new ProductTagString(ProductTag.ptShokoladPirog, ("шоколадный пирог")));
            m_Array.Add(new ProductTagString(ProductTag.ptPirojenoe, ("пироженное")));
            m_Array.Add(new ProductTagString(ProductTag.ptPoncik, ("пончик")));
            m_Array.Add(new ProductTagString(ProductTag.ptChizkeyk, ("чизкейк")));

            m_Array.Add(new ProductTagString(ProductTag.ptKormKorova, ("корм для коров")));
            m_Array.Add(new ProductTagString(ProductTag.prKormKurica, ("корм для куриц")));
            m_Array.Add(new ProductTagString(ProductTag.ptKormOvca, ("корм для овец")));
            m_Array.Add(new ProductTagString(ProductTag.prKormPchela, ("корм для пчел")));

            m_Array.Add(new ProductTagString(ProductTag.ptKlubnikaVarenie, ("клубничное варенье")));
            m_Array.Add(new ProductTagString(ProductTag.ptPersikVarenie, ("персиковый конфитюр")));
            m_Array.Add(new ProductTagString(ProductTag.ptArbuzVarenie, ("арбузный джем")));
            m_Array.Add(new ProductTagString(ProductTag.ptSlivaVarenie, ("сливовое варенье")));

            m_Array.Add(new ProductTagString(ProductTag.ptPersik, ("персик")));
            m_Array.Add(new ProductTagString(ProductTag.ptArbuz, ("арбуз")));
            m_Array.Add(new ProductTagString(ProductTag.ptSliva, ("слива")));

            m_Array.Add(new ProductTagString(ProductTag.ptSotiMed, ("соты с медом")));

            m_Array.Add(new ProductTagString(ProductTag.ptPlasticButilka, ("пластиковая бутылка")));
            m_Array.Add(new ProductTagString(ProductTag.ptToy, ("игрушка")));
        }
    };
    

}
