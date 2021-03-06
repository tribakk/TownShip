using TownShip_Form.Kernal;
// <copyright file="CSmartArrayFactory.cs" company="Microsoft">Copyright © Microsoft 2018</copyright>

using System;
using Microsoft.Pex.Framework;

namespace TownShip_Form.Kernal
{
    /// <summary>A factory for TownShip_Form.Kernal.CSmartArray instances</summary>
    public static partial class CSmartArrayFactory
    {
        /// <summary>A factory for TownShip_Form.Kernal.CSmartArray instances</summary>
        [PexFactoryMethod(typeof(CSmartArray))]
        public static CSmartArray Create()
        {
            CSmartArray cSmartArray = new CSmartArray();
            return cSmartArray;

            // TODO: Edit factory method of CSmartArray
            // This method should be able to configure the object in all possible ways.
            // Add as many parameters as needed,
            // and assign their values to each field by using the API.
        }
    }

    public static partial class CProductCalcFactory
    {
        public static CProductCalc Create()
        {
            CProductCalc cProductCalc = new CProductCalc();
            return cProductCalc;
        }
}

    public enum FactType
    {
        ftBackary = 1,
        ftMilk,
        ftWeaving,
        ftSewing,
        ftSnack,
        ftFastFood,
        ftRubber,
        ftSugar,
        ftPaper,
        ftIceCream,
        ftConfectionery,
        ftAnimal,
        ftKorm,
        ftPlastic,
        ftJamFactory,
        ftCandyFactory
    }
    public static partial class FactoryFactory
    {
        public static CFactory CreateFactory(FactType type)
        {
            CFactory pFact = null;
            switch (type)
            {
                case FactType.ftAnimal:
                    pFact = new CAnimalFactory();
                    break;
                case FactType.ftBackary:
                    pFact = new CBakery();
                    break;
                case FactType.ftConfectionery:
                    pFact = new CСonfectioneryFactory();
                    break;
                case FactType.ftFastFood:
                    pFact = new CFastFoodFactory();
                    break;
                case FactType.ftIceCream:
                    pFact = new CIceCreamFactory();
                    break;
                case FactType.ftJamFactory:
                    pFact = new CJamFactory();
                    break;
                case FactType.ftKorm:
                    pFact = new CKormFactory();
                    break;
                case FactType.ftMilk:
                    pFact = new CMilkFactory();
                    break;
                case FactType.ftPaper:
                    pFact = new CPaperFactory();
                    break;
                case FactType.ftPlastic:
                    pFact = new CPlasticFactory();
                    break;
                case FactType.ftSewing:
                    pFact = new CSewingFactory();
                    break;
                case FactType.ftSnack:
                    pFact = new CSnackFactory();
                    break;
                case FactType.ftSugar:
                    pFact = new CSugarFactory();
                    break;
                case FactType.ftWeaving:
                    pFact = new CWeavingFactory();
                    break;
                case FactType.ftRubber:
                    pFact = new CRubberFactory();
                    break;
                case FactType.ftCandyFactory:
                    pFact = new CCandyFactory();
                    break;

            }
            return pFact;
        }
    }
}
