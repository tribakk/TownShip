using System;

namespace TownShip_Form.Kernal
{
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
}