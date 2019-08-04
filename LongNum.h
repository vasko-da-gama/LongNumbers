#pragma once
#include <iostream>
#include <cstdio>
#include <assert.h>

namespace LongNumbers
{
#define MAX_LEN 10000
	class LongNum
	{
	private:
		char* num;
		int size; // default 1
		bool z; // 1 - "+"; 0 - "-"

		void intToArray(int);
		void addInBack(LongNum&, char);
		void addInBack(LongNum&, const LongNum&);

	public:
		LongNum();
		LongNum(char*);
		LongNum(int);
		~LongNum();
		void mfree();

		friend std::ostream& operator<<(std::ostream& out, LongNum& n)
		{
			if (!n.z)
				out << "-";
			for (int i = n.size - 1; i >= 0; i--)
				out << (short)n.num[i];
			out << '\n';
			return out;
		}

		void zero();
		void operator=(int);
		void operator=(char*);
		void operator=(const LongNum);
		int operator>(const LongNum&);
		int operator<(const LongNum&);
		int operator>=(const LongNum&);
		int operator==(const LongNum&);

		LongNum operator+(LongNum&);
		LongNum operator-(LongNum&);
		LongNum operator*(LongNum&);
		LongNum operator/(LongNum&);
		LongNum operator%(LongNum&);

		LongNum pow(LongNum&);

	};
}

