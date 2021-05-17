using System;
using System.Collections.Generic;
using System.Linq;

namespace TownShip_Form.Kernal
{
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
            if (Name == null || Name.Length == 0)
                return tag;
            int count = m_Array.Count();
            for (int i = 0; i < count; i++)
            {
                //if (i<10 && false) 
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
            m_Array.Add(new ProductTagString(ProductTag.ptPhenica, "пшеница"));
            m_Array.Add(new ProductTagString(ProductTag.ptKukuruza, "кукуруза"));
            m_Array.Add(new ProductTagString(ProductTag.ptMorkov, "морковь"));
            m_Array.Add(new ProductTagString(ProductTag.ptSaharniTrosnik, "сахарный тросник"));
            m_Array.Add(new ProductTagString(ProductTag.ptHlopok, "хлопок"));
            m_Array.Add(new ProductTagString(ProductTag.ptKlubnika, "клубника"));
            m_Array.Add(new ProductTagString(ProductTag.ptTomat, "томат"));
            m_Array.Add(new ProductTagString(ProductTag.ptSosna, "сосна"));
            m_Array.Add(new ProductTagString(ProductTag.ptKartofel, "картофель"));
            m_Array.Add(new ProductTagString(ProductTag.ptKakao, "какао"));
            m_Array.Add(new ProductTagString(ProductTag.ptKauchuk, "каучук"));
            m_Array.Add(new ProductTagString(ProductTag.ptShelk, "шелк"));
            m_Array.Add(new ProductTagString(ProductTag.ptPerec, "перец"));
            m_Array.Add(new ProductTagString(ProductTag.ptMoloko, "молоко"));
            m_Array.Add(new ProductTagString(ProductTag.ptYaco, "яйцо"));
            m_Array.Add(new ProductTagString(ProductTag.ptSherst, "шерсть"));
            m_Array.Add(new ProductTagString(ProductTag.ptHleb, "хлеб"));
            m_Array.Add(new ProductTagString(ProductTag.ptPechenie, "печенье"));
            m_Array.Add(new ProductTagString(ProductTag.ptBublic, "бублик"));
            m_Array.Add(new ProductTagString(ProductTag.ptPizza, "пицца"));
            m_Array.Add(new ProductTagString(ProductTag.ptKartofelHleb, "картофельный хлеб"));
            m_Array.Add(new ProductTagString(ProductTag.ptBananaHleb, "банановый хлеб"));
            m_Array.Add(new ProductTagString(ProductTag.ptClivki, "сливки"));
            m_Array.Add(new ProductTagString(ProductTag.ptSyr, "сыр"));
            m_Array.Add(new ProductTagString(ProductTag.ptMaslo, "масло"));
            m_Array.Add(new ProductTagString(ProductTag.ptIogury, "йогурт"));
            m_Array.Add(new ProductTagString(ProductTag.ptPersikIogurt, "персиковый йогурт"));
            m_Array.Add(new ProductTagString(ProductTag.ptHlopokTkan, "хлопковая ткань"));
            m_Array.Add(new ProductTagString(ProductTag.ptPryaja, "пряжа"));
            m_Array.Add(new ProductTagString(ProductTag.ptShelkNit, "шелковая ткань"));
            m_Array.Add(new ProductTagString(ProductTag.ptRubashka, "рубашка"));
            m_Array.Add(new ProductTagString(ProductTag.ptSviter, "свитер"));
            m_Array.Add(new ProductTagString(ProductTag.ptPalto, "пальто"));
            m_Array.Add(new ProductTagString(ProductTag.ptShlapa, "шляпа"));
            m_Array.Add(new ProductTagString(ProductTag.ptPlatie, "платье"));
            m_Array.Add(new ProductTagString(ProductTag.ptKostum, "костюм"));
            m_Array.Add(new ProductTagString(ProductTag.ptPopkorn, "попкорн"));
            m_Array.Add(new ProductTagString(ProductTag.ptKukuruzaChips, "кукурузные чипсы"));
            m_Array.Add(new ProductTagString(ProductTag.ptGranola, "гранола"));
            m_Array.Add(new ProductTagString(ProductTag.ptChips, "чипсы"));
            m_Array.Add(new ProductTagString(ProductTag.ptkanope, "канопе"));
            m_Array.Add(new ProductTagString(ProductTag.ptMilkSheik, "милкшейк"));
            m_Array.Add(new ProductTagString(ProductTag.ptChisburger, "чизбургер"));
            m_Array.Add(new ProductTagString(ProductTag.ptSendvich, "сэндвич"));
            m_Array.Add(new ProductTagString(ProductTag.ptKartoshkaFree, "картошка фри"));
            m_Array.Add(new ProductTagString(ProductTag.ptPecheneiKartofel, "печеный картофель"));
            m_Array.Add(new ProductTagString(ProductTag.ptRezina, "резина"));
            m_Array.Add(new ProductTagString(ProductTag.ptPlastik, "пластик"));
            m_Array.Add(new ProductTagString(ProductTag.ptKley, "клей"));
            m_Array.Add(new ProductTagString(ProductTag.ptSahar, "сахар"));
            m_Array.Add(new ProductTagString(ProductTag.ptSirop, "сироп"));
            m_Array.Add(new ProductTagString(ProductTag.ptKaramel, "карамель"));
            m_Array.Add(new ProductTagString(ProductTag.ptMedovayaKaramel, "медовая карамель"));
            m_Array.Add(new ProductTagString(ProductTag.ptBumaga, "бумага"));
            m_Array.Add(new ProductTagString(ProductTag.ptBumagaPolotence, "бумажные полотенца"));
            m_Array.Add(new ProductTagString(ProductTag.ptOboi, "обои"));
            m_Array.Add(new ProductTagString(ProductTag.ptKniga, "книга"));
            m_Array.Add(new ProductTagString(ProductTag.ptMorogenoe, "мороженое"));
            m_Array.Add(new ProductTagString(ProductTag.ptFruktLed, "фруктовый лед"));
            m_Array.Add(new ProductTagString(ProductTag.ptZamarojeniIogurt, "замороженный йогурт"));
            m_Array.Add(new ProductTagString(ProductTag.ptEscimo, "эскимо"));
            m_Array.Add(new ProductTagString(ProductTag.ptAnanasSorbet, "ананасовый сорбет"));
            m_Array.Add(new ProductTagString(ProductTag.ptKeks, "кекс"));
            m_Array.Add(new ProductTagString(ProductTag.ptShokoladPirog, "шоколадный пирог"));
            m_Array.Add(new ProductTagString(ProductTag.ptPirojenoe, "пироженое"));
            m_Array.Add(new ProductTagString(ProductTag.ptPoncik, "пончик"));
            m_Array.Add(new ProductTagString(ProductTag.ptChizkeyk, "чизкейк"));

            m_Array.Add(new ProductTagString(ProductTag.ptKormKorova, "корм для коров"));
            m_Array.Add(new ProductTagString(ProductTag.prKormKurica, "корм для куриц"));
            m_Array.Add(new ProductTagString(ProductTag.ptKormOvca, "корм для овец"));
            m_Array.Add(new ProductTagString(ProductTag.prKormPchela, "корм для пчел"));

            m_Array.Add(new ProductTagString(ProductTag.ptKlubnikaVarenie, "клубничное варенье"));
            m_Array.Add(new ProductTagString(ProductTag.ptPersikVarenie, "персиковый конфитюр"));
            m_Array.Add(new ProductTagString(ProductTag.ptArbuzVarenie, "арбузный джем"));
            m_Array.Add(new ProductTagString(ProductTag.ptSlivaVarenie, "сливовое повидло"));

            m_Array.Add(new ProductTagString(ProductTag.ptPersik, "персик"));
            m_Array.Add(new ProductTagString(ProductTag.ptArbuz, "арбуз"));
            m_Array.Add(new ProductTagString(ProductTag.ptSliva, "слива"));

            m_Array.Add(new ProductTagString(ProductTag.ptSotiMed, "соты с медом"));

            m_Array.Add(new ProductTagString(ProductTag.ptPlasticButilka, "пластиковая бутылка"));
            m_Array.Add(new ProductTagString(ProductTag.ptToy, "игрушка"));

            m_Array.Add(new ProductTagString(ProductTag.ptMedPrynic, "медовый пряник"));
            m_Array.Add(new ProductTagString(ProductTag.ptMyach, "мяч"));

            m_Array.Add(new ProductTagString(ProductTag.ptVinograd, "виноград"));
            m_Array.Add(new ProductTagString(ProductTag.ptOlivki, "оливки"));
            m_Array.Add(new ProductTagString(ProductTag.ptLaym, "лайм"));
            m_Array.Add(new ProductTagString(ProductTag.ptVinogradJele, "виноградное желе"));
            m_Array.Add(new ProductTagString(ProductTag.ptNaduvnayaLodka, "надувная лодка"));

            m_Array.Add(new ProductTagString(ProductTag.ptDraje, "драже"));
            m_Array.Add(new ProductTagString(ProductTag.ptIriska, "ириски"));
        }
    };
}