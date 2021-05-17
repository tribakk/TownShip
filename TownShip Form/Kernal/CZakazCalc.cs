using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Office.Interop.Excel;

namespace TownShip_Form.Kernal
{
    class CZakazCalc
    {
        private static readonly Application m_pApplication = new Application();
        private readonly Workbook m_pBook;
        private readonly List<CZakaz> m_zakazList = new List<CZakaz>();
        private readonly CSmartArray m_alreadyHave = new CSmartArray();
        private readonly CAllProductSpisok m_Spisok = new CAllProductSpisok();

        public CZakazCalc()
        {
            m_pBook = GetWorkbook("test.xlsx");
        }
        ~CZakazCalc()
        {
            try
            {
                m_pBook.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                //throw;
            }
        }
        private static Workbook GetWorkbook(string name = "")
        {
            Workbook pBook = null;
            m_pApplication.Visible = true;
            if (name == "")
            {
                pBook = m_pApplication.Workbooks.Add();
            }
            else
            {
                string path = System.IO.Directory.GetCurrentDirectory();
                pBook = m_pApplication.Workbooks.Open(path + "\\" + name);
            }

            return pBook;
        }
        private Worksheet GetWorksheet(string sheetName, bool bThrow = true)
        {
            Worksheet pSheet = null;
            try
            {
                pSheet = (Worksheet)m_pBook.Worksheets.Item[sheetName];
            }
            catch
            {
                if (bThrow)
                    throw new ArgumentNullException("нет листа " + sheetName);
            }

            return pSheet;
        }
        private string GetUniqueSheetName(string name)
        {
            string uniqueName;
            for (int i = 1;; i++)
            {
                uniqueName = name + i.ToString();
                if (GetWorksheet(uniqueName, false) == null)
                    break;
            }

            return uniqueName;
        }
        public void UpdateZakazList()
        {
            Worksheet pSheet = GetWorksheet("Zakaz");
            m_zakazList.Clear();
            for (int column = 1; ; column += 2)
            {
                if (pSheet.Cells[1, column].Text == "")
                    break;

                CZakaz pZakaz = new CZakaz();
                pZakaz.LoadValueFromSheet(pSheet, column);
                m_zakazList.Add(pZakaz);
            }
        }

        public void UpdateAlreadyHaveList()
        {
            Worksheet pSheet = GetWorksheet("AlreadyHave");
            m_alreadyHave.RemoveAll();
            for (int column = 1;; column += 2)
            {
                if (pSheet.Cells[1, column].Text == "")
                    break;
                for (int row = 2;; row++)
                {
                    string name = pSheet.Cells[row, column].Text;
                    if (name == "")
                        break;
                    string value = pSheet.Cells[row, column + 1].Text;
                    m_alreadyHave.Add(name, Convert.ToInt32(value));
                }
            }
        }
        public void CreateEmptyAlreadyHaveSheet()
        {
            Worksheet pSheet = m_pBook.Worksheets.Add();
            pSheet.Name = GetUniqueSheetName("EmptyAlreadyHave");
            pSheet.Cells[1, 1] = "Наименование";
            pSheet.Cells[1, 2] = "Значение";
            int count = m_Spisok.GetCount();
            for (int i = 0; i < m_Spisok.GetCount(); i++)
            {
                ProductTag tag = (ProductTag) (i + 1);
                string tagName = m_Spisok.GetName(tag);
                pSheet.Cells[i + 2, 1] = tagName;
                pSheet.Cells[i + 2, 2] = 0;
            }
        }

        private void ExportToExcel(Worksheet pSheet, List<CFactory> pFactory, CSmartArray array)
        {
            CExportAllFactoryHelper excelHelper = new CExportAllFactoryHelper(pSheet, pFactory, array);
        }
        public void Calc()
        {
            List<CZakaz> simpleZakazes = new List<CZakaz>();
            List<CZakaz> newZakazes = new List<CZakaz>();
            List<CZakaz> resolveZakazes = new List<CZakaz>();

            UpdateZakazsList(resolveZakazes, newZakazes, simpleZakazes);

            CSmartArray calcArray = new CSmartArray();
            LoadZakazListToSmartArray(calcArray, simpleZakazes);

            CProductCalc productCalc = new CProductCalc();
            productCalc.SetArray(calcArray);
            productCalc.SetAlreadyHave(m_alreadyHave.Copy());
            productCalc.Calc(5);

            Worksheet pTotalSheet = m_pBook.Worksheets.Add();
            pTotalSheet.Name = GetUniqueSheetName("MainTotal");
            ExportToExcel(pTotalSheet, productCalc.GetFactoryList(), productCalc.GetArray());
            {
                Worksheet pOneTableSheet = m_pBook.Worksheets.Add();
                pOneTableSheet.Name = GetUniqueSheetName("OneTableTotal");
                Kernal.CAllFactoryOneTable allFactoryOneTable = new Kernal.CAllFactoryOneTable(productCalc.GetFactoryList(), pOneTableSheet);
                Kernal.CAllSourceWrite AllSourceWrite = new Kernal.CAllSourceWrite(pOneTableSheet, productCalc.GetArray());

            }

            if (newZakazes.Count > 0)
            {
                CProductCalc productCalc2 = GetProductCalcSimpleAndSecond(simpleZakazes, newZakazes);
                {
                    Worksheet pTotalSheet2 = m_pBook.Worksheets.Add();
                    pTotalSheet2.Name = GetUniqueSheetName("OtherTotal");
                    ExportToExcel(pTotalSheet2, productCalc2.GetFactoryList(), productCalc2.GetArray());
                }
                productCalc2.ExcludeWhatHave(productCalc);
                Worksheet pSimpleSheet = m_pBook.Worksheets.Add();
                pSimpleSheet.Name = GetUniqueSheetName("SimpleTotal");
                new CSimpleFactoryExport(pSimpleSheet, productCalc2.GetFactoryList(), productCalc2.GetArray());

            }
            if (resolveZakazes.Count > 0)
            {
                CProductCalc productCalc2 = GetProductCalcSimpleAndSecond(simpleZakazes, resolveZakazes);
                CSmartArray newAlreadyHave = productCalc.GetAlreadyHave();

                //вывести на другой лист значение newAlreadyHave
            }
        }
        private CProductCalc GetProductCalcSimpleAndSecond(List<CZakaz> simpleZakazes, List<CZakaz> newZakazes)
        {
            CSmartArray calcArray2 = new CSmartArray();
            LoadZakazListToSmartArray(calcArray2, simpleZakazes);
            LoadZakazListToSmartArray(calcArray2, newZakazes);

            CProductCalc productCalc2 = new CProductCalc();
            productCalc2.SetArray(calcArray2);
            productCalc2.SetAlreadyHave(m_alreadyHave.Copy());
            productCalc2.Calc(5);
            return productCalc2;
        }
        private void UpdateZakazsList(List<CZakaz> resolveZakazes, List<CZakaz> newZakazes, List<CZakaz> simpleZakazes)
        {
            for (int i = 0; i < m_zakazList.Count; i++)
            {
                CZakaz pZakaz = m_zakazList[i]/* ?? throw new ArgumentNullException("кривой заказ")*/;
                if (pZakaz.IsResolve())
                    resolveZakazes.Add((pZakaz));
                else if (pZakaz.IsNew())
                    newZakazes.Add(pZakaz);
                else
                    simpleZakazes.Add(pZakaz);
            }

            if ((resolveZakazes.Count * newZakazes.Count) != 0)
                throw new ArgumentNullException("есть Resolve и New заказы одновременно");
        }

        private void LoadZakazListToSmartArray(CSmartArray array, List<CZakaz> pList)
        {
            for (int i = 0; i < pList.Count; i++)
            {
                array.Merge(pList[i].GetSmartArray());
            }
        }
    }
}
