#include <iostream>

namespace Class1Paul
{
	class Class1
	{
		public:
			Class1(int _a, int _b)
			{
				a = _a;
				b = _b;
			}

			void PrintBil();
		
		private:
			int a = 0, b = 0;
	};
}