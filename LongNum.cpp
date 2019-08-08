#include "LongNum.h"

namespace LongNumbers
{
	LongNum::LongNum()
	{
		num = (char*)malloc(MAX_LEN); assert(num);
		memset(num, 0, MAX_LEN);
		size = 1;
		z = true;
	}

	LongNum::LongNum(int a)
	{
		num = (char*)malloc(MAX_LEN); assert(num);
		intToArray(a);
	}

	LongNum::LongNum(char* a)
	{
		z = 1;
		num = (char*)malloc(MAX_LEN); assert(num);
		memset(num, 0, MAX_LEN);
		//size = 1;

		int i = 0;
		while (a[i] != '\0')
			i++;
		if (a[0] == '-')
			z = 0;

		if (a[0] == '-')
			size = i - 1;
		else
			size = i;

		int j = 0;
		for (int k = i - 1; k >= 0; k--)
		{
			if (a[k] != '-' && a[k] != '+')
			{
				num[j] = (a[k] - '0');
				j++;
			}
		}
	}

	LongNum::~LongNum()
	{
		//free((*this).num);
	}

	void LongNum::mfree()
	{
		free((*this).num);
	}

	void LongNum::zero()
	{
		memset((*this).num, 0, MAX_LEN);
		(*this).size = 1;
		(*this).z = 1;
	}

	void LongNum::intToArray(int a)
	{
		(*this).zero();
		if (a == 0)
		{
			return;
		}
		int* mas = new int[10];
		int size1 = 0;
		for (int i = 0; i < 10; i++)
			mas[i] = 0;
		int a_z = 1;
		if (a < 0)
		{
			a *= (-1);
			a_z = 0;
		}
		for (int i = 0; i < 10; i++)
			if (a > 0)
			{
				mas[i] = a % 10;
				a /= 10;
				size1++;
			}
		for (int i = 0; i < size1; i++)
			num[i] = mas[i];
		size = size1;
		z = a_z;
	}

	void LongNum::operator=(int a)
	{
		intToArray(a);
	}

	void LongNum::operator=(char* a)
	{
		memset(num, 0, MAX_LEN);

		int i = 0;
		while (a[i] != '\0')
			i++;
		if (a[0] == '-')
			z = 0;

		if (a[0] == '-')
			size = i - 1;
		else
			size = i;

		int j = 0;
		for (int k = i - 1; k >= 0; k--)
		{
			if (a[k] != '-' && a[k] != '+')
			{
				num[j] = (a[k] - '0');
				j++;
			}
		}
	}

	void LongNum::operator=(const LongNum a)
	{
		(*this).zero();
		memcpy(num, a.num, a.size);
		size = a.size;
		z = a.z;
	}

	int LongNum::operator>(const LongNum& a)
	{
		if (z == 0 && a.z == 1)
			return 0;
		if (z == 1 && a.z == 0)
			return 1;
		
		int equ;
		if (size > a.size)
			equ = 1;
		if (size < a.size)
			equ = 2;
		if (size == a.size)
			for (int i = size; i >= 0; i--)
			{
				if (num[i] > a.num[i])
				{
					equ = 1;
					break;
				}
				if (num[i] < a.num[i])
				{
					equ = 2;
					break;
				}
				if (i == 0)
					equ = 0;
			}
		
		if (z == 0 && a.z == 0)
		{
			if (equ == 1)
				return 0;
			if (equ == 2)
				return 1;
			if (equ == 0)
				return 0;
		}
		if (z == 1 && a.z == 1)
		{
			if (equ == 1)
				return 1;
			if (equ == 2)
				return 0;
			if (equ == 0)
				return 0;
		}
	}

	int LongNum::operator<(const LongNum& a)
	{
		if (z == 0 && a.z == 1)
			return 1;
		if (z == 1 && a.z == 0)
			return 0;
		
		int equ;
		if (size > a.size)
			equ = 1;
		if (size < a.size)
			equ = 2;
		if (size == a.size)
			for (int i = size; i >= 0; i--)
			{
				if (num[i] > a.num[i])
				{
					equ = 1;
					break;
				}
				if (num[i] < a.num[i])
				{
					equ = 2;
					break;
				}
				if (i == 0)
					equ = 0;
			}
		
		if (z == 0 && a.z == 0)
		{
			if (equ == 1)
				return 1;
			if (equ == 2)
				return 0;
			if (equ == 0)
				return 0;
		}
		if (z == 1 && a.z == 1)
		{
			if (equ == 1)
				return 0;
			if (equ == 2)
				return 1;
			if (equ == 0)
				return 0;
		}
	}

	int LongNum::operator>=(const LongNum& a)
	{
		if (z == 0 && a.z == 1)
			return 0;
		if (z == 1 && a.z == 0)
			return 1;
		
		int equ;
		if (size > a.size)
			equ = 1;
		if (size < a.size)
			equ = 2;
		if (size == a.size)
			for (int i = size; i >= 0; i--)
			{
				if (num[i] > a.num[i])
				{
					equ = 1;
					break;
				}
				if (num[i] < a.num[i])
				{
					equ = 2;
					break;
				}
				if (i == 0)
					equ = 0;
			}
		
		if (z == 0 && a.z == 0)
		{
			if (equ == 1)
				return 0;
			if (equ == 2)
				return 1;
			if (equ == 0)
				return 1;
		}
		if (z == 1 && a.z == 1)
		{
			if (equ == 1)
				return 1;
			if (equ == 2)
				return 0;
			if (equ == 0)
				return 1;
		}
	}

	int LongNum::operator==(const LongNum& a)
	{
		if (z == 0 && a.z == 1)
			return 0;
		if (z == 1 && a.z == 0)
			return 1;
		
		int equ;
		if (size > a.size)
			equ = 1;
		if (size < a.size)
			equ = 2;
		if (size == a.size)
			for (int i = size; i >= 0; i--)
			{
				if (num[i] > a.num[i])
				{
					equ = 1;
					break;
				}
				if (num[i] < a.num[i])
				{
					equ = 2;
					break;
				}
				if (i == 0)
					equ = 0;
			}
		
		if (z == 0 && a.z == 0)
		{
			if (equ == 1)
				return 0;
			if (equ == 2)
				return 1;
			if (equ == 0)
				return 0;
		}
		if (z == 1 && a.z == 1)
		{
			if (equ == 1)
				return 0;
			if (equ == 2)
				return 0;
			if (equ == 0)
				return 1;
		}
	}

	inline int Max(int a, int b)
	{
		if (a > b)
			return a;
		if (a < b)
			return b;
		if (a == b)
			return a;
	}

	LongNum LongNum::operator+(LongNum& a)
	{
		LongNum result;
		if ((*this).z == 0 && a.z == 1)
		{
			// -t + a = a - t
			(*this).z = 1;
			result = a - (*this);
			(*this).z = 0;
			return result;
		}
		if ((*this).z == 1 && a.z == 0)
		{
			// t + (-a) = t - a
			a.z = 1;
			result = (*this) - a;
			a.z = 0;
			return result;
		}
		if ((*this).z == 0 && a.z == 0)
		{
			// -t + -a = -t - a = - (t + a)
			(*this).z = 1; a.z = 1;
			result = (*this) + a;
			result.z = 0;
			(*this).z = 0; a.z = 0;
			return result;
		}

		int k = 0;
		int j = Max(size, a.size);

		for (int i = 0; i < j; i++)
		{
			k = num[i] + a.num[i] + result.num[i];
			if (k >= 10)
			{
				result.num[i] = (k % 10);
				result.num[i + 1] = (k / 10);
			}
			else
				result.num[i] = k;
		}

		for (int i = 0; i < MAX_LEN; i++)
			if (result.num[i] != 0)
				result.size = i + 1;

		return result;
	}

	LongNum LongNum::operator-(LongNum& a)
	{
		LongNum result;
		if ((*this).z == 0 && a.z == 1)
		{
			// -a - b = - (a + b)
			(*this).z = 1;
			result = (*this) + a;
			result.z = 0;
			(*this).z = 0;
			return result;
		}
		if ((*this).z == 1 && a.z == 0)
		{
			// a - -b = a + b
			a.z = 1;
			result = (*this) + a;
			a.z = 0;
			return result;
		}
		if ((*this).z == 0 && a.z == 0)
		{
			// -a - -b = -a + b = b - a
			(*this).z = 1; a.z = 1;
			result = a - (*this);
			(*this).z = 0; a.z = 0;
			return result;
		}


		// main block require (this > a) and this > 0 && a > 0
		if ((*this) < a && ((*this).z == 1 && a.z == 1))
		{
			result = a - (*this);
			result.z = 0;
			return result;
		}

		// need to save 'this'
		char* saveThis = (char*)malloc((*this).size); assert(saveThis);
		memcpy(saveThis, (*this).num, (*this).size);
		for (int i = 0; i < (*this).size; i++)
		{
			if ((*this).num[i] >= a.num[i])
			{
				result.num[i] = (*this).num[i] - a.num[i];
			}
			else
			{
				int j = i + 1;
				while ((*this).num[j] == 0)
				{
					(*this).num[j] = 9; j++;
				}
				(*this).num[j] -= 1;
				(*this).num[i] += 10;
				result.num[i] = (*this).num[i] - a.num[i];
			}
		}

		// size
		for (int i = 0; i < MAX_LEN; i++)
			if (result.num[i] != 0)
				result.size = i + 1;

		memset((*this).num, 0, MAX_LEN);
		memcpy((*this).num, saveThis, (*this).size);
		free(saveThis);

		return result;
	}

	LongNum LongNum::operator*(LongNum& a)
	{
		LongNum result;
		if (z == 0 || a.z == 0)
		{
			if (z == 0)
				result.z = 0;
			if (a.z == 0)
				result.z = 0;
			if (z == 0 && a.z == 0)
				result.z = 1;
		}
		int size_r = size + a.size + 1; //size_r -> length

		int* tres = (int*)malloc(sizeof(int) * size_r); assert(tres);
		memset(tres, 0, sizeof(int) * size_r);

		for (int ix = 0; ix < size; ix++)
			for (int jx = 0; jx < a.size; jx++)
				tres[ix + jx] += num[ix] * a.num[jx];

		for (int ix = 0; ix < size_r; ix++)
		{
			tres[ix + 1] += tres[ix] / 10;
			tres[ix] %= 10;
		}

		while (tres[size_r - 1] == 0)
			size_r--;
		result.size = size_r;

		for (int i = 0; i < size_r; i++)
			result.num[i] = (char)(tres[i] & 0xff);

		free(tres);
		return result;
	}

	void LongNum::addInBack(LongNum& a, char b)
	{
		char* tmp = (char*)malloc(a.size); assert(tmp);
		memcpy(tmp, a.num, a.size);
		a.num[0] = b;
		memcpy(a.num + 1, tmp, a.size);
		int newSize = a.size + 1;
		while (a.num[newSize - 1] == 0)
			newSize--;
		a.size = (newSize > 0) ? newSize : 1;
		free(tmp);
	}

	void LongNum::addInBack(LongNum& a, const LongNum& b)
	{
		char* tmp = (char*)malloc(a.size); assert(tmp);
		memcpy(tmp, a.num, a.size);
		memset(a.num, 0, a.size);
		memcpy(a.num, b.num, b.size);
		memcpy(a.num + b.size, tmp, a.size);
		int newSize = a.size + b.size;
		while (a.num[newSize - 1] == 0)
			newSize--;
		a.size = (newSize > 0) ? newSize : 1;
		free(tmp);
	}

	LongNum LongNum::operator/(LongNum& a)
	{
		// this - dividend, a - divider
		LongNum t_dividend, res_array, mul, tmp_r;
		LongNum one((char*) "1");
		int throw_dividend = (*this).size - 1; // this = 1789, a = 256; this.num[throw_dividend] = 8

		// find first dividend
		while (throw_dividend >= 0 && a > t_dividend)
			addInBack(t_dividend, (*this).num[throw_dividend--]);
		
		while (throw_dividend >= -1)
		{
			tmp_r = 0;
			mul = 0;
			while (t_dividend >= mul)
			{
				tmp_r = tmp_r + one;
				mul = tmp_r * a;
			}
			tmp_r = tmp_r - one;
			mul = tmp_r * a;
			
			t_dividend = t_dividend - mul;

			addInBack(res_array, tmp_r);

			if (throw_dividend >= 0) addInBack(t_dividend, (*this).num[throw_dividend]);
			throw_dividend--;
		}

		tmp_r.mfree(); mul.mfree();
		t_dividend.mfree();
		return res_array;
	}

	LongNum LongNum::operator%(LongNum& a)
	{
		// this - dividend, a - divider
		LongNum t_dividend, mul, tmp_r;
		LongNum one((char*) "1");
		int throw_dividend = (*this).size - 1; // this = 1789, a = 256; this.num[throw_dividend] = 8

		// find first dividend
		while (throw_dividend >= 0 && a > t_dividend)
			addInBack(t_dividend, (*this).num[throw_dividend--]);

		while (throw_dividend >= -1)
		{
			tmp_r = 0;
			mul = 0;
			while (t_dividend >= mul)
			{
				tmp_r = tmp_r + one;
				mul = tmp_r * a;
			}
			tmp_r = tmp_r - one;
			mul = tmp_r * a;

			t_dividend = t_dividend - mul;

			if (throw_dividend >= 0) addInBack(t_dividend, (*this).num[throw_dividend]);
			throw_dividend--;
		}

		tmp_r.mfree(); mul.mfree();
		return t_dividend;
	}

	LongNum LongNum::pow(LongNum& a)
	{
		LongNum result, count, one;
		count = 0; one = 1; result = 1;
		while (a > count)
		{
			result = (*this) * result;
			count = count + one;
		}
		count.mfree(); one.mfree();
		return result;
	}

	inline LongNum sqr(LongNum a)
	{
		return (a * a);
	}

	LongNum LongNum::fpow(int power)
	{
		int len = 0, cp = power;
		LongNum last(1);

		while (cp > 0) { cp >>= 1; len++; }

		for (int i = 0; i < (len - 1); i++)
		{
			if (((power >> (len - i - 1)) & 0x01) != 0)
				last = last * (*this);
			last = sqr(last);
		}
		if ((power & 0x01) != 0)
			last = last * (*this);
		return last;
	}

}