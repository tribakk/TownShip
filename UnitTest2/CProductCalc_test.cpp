#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Source/CProductCalc.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CProductCalc_test
{
	TEST_CLASS(ProductCalc)
	{
	public:
		TEST_METHOD(SimpleBublic)
		{
			CProductCalc productCalc;
			productCalc.AddNeed("������", 2);
			productCalc.Calc();
			std::unique_ptr<CSmartArray> result = productCalc.GetArray();

			Assert::IsTrue(result->GetTagCount(ProductTag::ptPhenica) == 4);
			Assert::IsTrue(result->GetTagCount(ProductTag::ptSaharniTrosnik) == 6);
			Assert::IsTrue(result->GetTagCount(ProductTag::ptYaco) == 6);
		}

		TEST_METHOD(BublicWithAlreadyHave)
		{
			CProductCalc productCalc;
			productCalc.AddNeed("������", 2);
			productCalc.AddAlreadyHave("�������", 3);
			productCalc.AddAlreadyHave("����", 4);
			productCalc.Calc();
			std::unique_ptr<CSmartArray> result = productCalc.GetArray();

			Assert::IsTrue(result->GetTagCount(ProductTag::ptPhenica) == 1);
			Assert::IsTrue(result->GetTagCount(ProductTag::ptSaharniTrosnik) == 6);
			Assert::IsTrue(result->GetTagCount(ProductTag::ptYaco) == 2);
		}

		TEST_METHOD(ManyProducts)
		{
			CProductCalc productCalc;
			productCalc.AddNeed("������", 1);
			productCalc.AddNeed("������", 2);
			productCalc.AddNeed("�������", 3);
			productCalc.AddNeed("�������", 4);
			productCalc.AddNeed("��������� ���", 5);
			productCalc.AddNeed("������", 6);
			productCalc.Calc();
			productCalc.Calc();
			productCalc.Calc();
			productCalc.Calc();
			std::unique_ptr<CSmartArray> result = productCalc.GetArray();

			Assert::IsTrue(result->GetTagCount(ProductTag::ptPhenica) == 22);
			Assert::IsTrue(result->GetTagCount(ProductTag::ptSaharniTrosnik) == 44);
			Assert::IsTrue(result->GetTagCount(ProductTag::ptHlopok) == 6);
			Assert::IsTrue(result->GetTagCount(ProductTag::ptKlubnika) == 18);
			Assert::IsTrue(result->GetTagCount(ProductTag::ptSosna) == 2);
			Assert::IsTrue(result->GetTagCount(ProductTag::ptKakao) == 6);
			Assert::IsTrue(result->GetTagCount(ProductTag::ptYaco) == 21);
		}
	};
}