#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Source/CSmartArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CSmartArray_test
{
	TEST_CLASS(SmartArray)
	{
	public:
		TEST_METHOD(IsEmpty)
		{
			CSmartArray testArray;
			Assert::IsTrue(testArray.IsEmpty());
			testArray.Add(ProductTag::ptBublic, 2);
			Assert::IsFalse(testArray.IsEmpty());
		}

		TEST_METHOD(RemoveAll)
		{
			CSmartArray testArray;
			testArray.Add(ProductTag::ptBananaHleb, 3);
			Assert::IsFalse(testArray.IsEmpty());
			testArray.RemoveAll();
			Assert::IsTrue(testArray.IsEmpty());
			
		}
		TEST_METHOD(Add)
		{
			CSmartArray testArray;
			testArray.Add(ProductTag::ptBublic, 3);
			Assert::IsTrue(testArray.GetTagCount(ProductTag::ptBublic) == 3);
			testArray.Add(ProductTag::ptBublic, 2);
			Assert::IsTrue(testArray.GetTagCount(ProductTag::ptBublic) == 5);
			testArray.Add(ProductTag::ptBublic, -4);
			Assert::IsTrue(testArray.GetTagCount(ProductTag::ptBublic) == 1);
		}

		TEST_METHOD(Exclude1)
		{
			CSmartArray testArray1;
			testArray1.Add(ProductTag::ptBublic, 3);
			CSmartArray testArray2;
			testArray2.Add(ProductTag::ptBublic, 2);
			testArray1.ExcludeWhatHave(testArray2);

			Assert::IsTrue(testArray1.GetTagCount(ProductTag::ptBublic) == 1);
			Assert::IsTrue(testArray2.GetTagCount(ProductTag::ptBublic) == 0);
		}

		TEST_METHOD(Exclude2)
		{
			CSmartArray testArray1;
			testArray1.Add(ProductTag::ptBublic, 3);
			CSmartArray testArray2;
			testArray2.Add(ProductTag::ptBublic, 2);
			testArray2.ExcludeWhatHave(testArray1);

			Assert::IsTrue(testArray1.GetTagCount(ProductTag::ptBublic) == 1);
			Assert::IsTrue(testArray2.GetTagCount(ProductTag::ptBublic) == 0);
		}

		TEST_METHOD(Exclude3)
		{
			CSmartArray testArray1;
			testArray1.Add(ProductTag::ptBublic, 3);
			CSmartArray testArray2;
			testArray2.Add(ProductTag::ptBumaga, 2);
			testArray1.ExcludeWhatHave(testArray2);

			Assert::IsTrue(testArray1.GetTagCount(ProductTag::ptBublic) == 3);
			Assert::IsTrue(testArray2.GetTagCount(ProductTag::ptBumaga) == 2);
		}

		TEST_METHOD(ClearTag)
		{
			CSmartArray testArray;
			testArray.Add(ProductTag::ptBublic, 3);
			testArray.Add(ProductTag::ptAnanasSorbet, 10);
			testArray.ClearTag(ProductTag::ptAnanasSorbet);

			Assert::IsTrue(testArray.GetTagCount(ProductTag::ptBublic) == 3);
			Assert::IsTrue(testArray.GetTagCount(ProductTag::ptAnanasSorbet) == 0);
		}

		TEST_METHOD(Merge)
		{
			CSmartArray testArray1;
			testArray1.Add(ProductTag::ptBublic, 3);
			testArray1.Add(ProductTag::ptEscimo, 7);
			CSmartArray testArray2;
			testArray2.Add(ProductTag::ptBublic, 5);
			testArray2.Add(ProductTag::ptBumaga, 2);
			testArray1.Merge(testArray2);

			//провер€ем что в 1ом массиве сумма товаров
			Assert::IsTrue(testArray1.GetTagCount(ProductTag::ptBublic) == 8);
			Assert::IsTrue(testArray1.GetTagCount(ProductTag::ptEscimo) == 7);
			Assert::IsTrue(testArray1.GetTagCount(ProductTag::ptBumaga) == 2);
			//провер€ем что 2ой массив не помен€лс€ после мерджа
			Assert::IsTrue(testArray2.GetTagCount(ProductTag::ptBublic) == 5);
			Assert::IsTrue(testArray2.GetTagCount(ProductTag::ptBumaga) == 2);
		}

		TEST_METHOD(TabNameTest)
		{
			CSmartArray testArray;
			testArray.Add("бублик", 3);
			Assert::IsTrue(testArray.GetTagCount(ProductTag::ptBublic) == 3);
			
		}
	};
}