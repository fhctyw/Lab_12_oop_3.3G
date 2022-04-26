#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_12_oop_3.3G\Object.cpp"
#include "..\Lab_12_oop_3.3G\LongLong.cpp"
#include "..\Lab_12_oop_3.3G\Cursor.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Cursor c;
			LongLong pos;
			Assert::AreEqual(2u, Object::Count());
		}
	};
}
