#include "pch.h"
#include "CppUnitTest.h"
#include "../AP12.4rek/AP12.4rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest124rek
{
	TEST_CLASS(UnitTest124rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* L = NULL;
			LAdd(L, L, 3);
			LAdd(L, L, 4);
			LAdd(L, L, 3);
			LAdd(L, L, 3);
			LAdd(L, L, 5);
			LAdd(L, L, 3);
			Assert::AreEqual(LCount(L, L, 3, 0), 4);

		}
	};
}
