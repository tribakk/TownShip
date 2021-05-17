using Microsoft.VisualStudio.TestTools.UnitTesting;
using TownShip_Form.Kernal;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TownShip_Form.Kernal.Tests
{
    [TestClass()]
    public class CAllProductSpisokTests
    {
        [TestMethod()]
        public void GetNameTest()
        {
            CAllProductSpisok spisok = new CAllProductSpisok();
            string name = spisok.GetName(TownShip_Form.Kernal.ProductTag.prKormPchela);
            Assert.AreEqual("корм для пчел", name);
        }

        //[TestMethod()]
        //public void GetTagTest()
        //{
        //    Assert.Fail();
        //}

        //[TestMethod()]
        //public void GetCountTest()
        //{
        //    Assert.Fail();
        //}

        //[TestMethod()]
        //public void CAllProductSpisokTest()
        //{
        //    //Assert.Fail();
        //}
    }
}