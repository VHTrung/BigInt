#include "Integer.h"


const unsigned int Integer::STANDARD_SIZE = 16;
//private static methods
std::string Integer::GetPlus(const std::string & _str1, const std::string & _str2, const int & _radix)
{
	std::string result;
	char carry = 0, digit;
	if (_str1.size() == _str2.size())
	{
		int i = _str1.size() - 1;
		for (; i >= 0; --i)
		{
			digit = _str1[i] <= '9' ? _str1[i] - '0' : _str1[i] + 10 - 'A';//get digit value

			//plus values
			if (_str2[i] <= '9')
				digit += _str2[i] - '0' + carry;
			else
				digit += _str2[i] + 10 - 'A' + carry;

			carry = digit / _radix;

			//get the digit coresponding to value after remove the carry
			if (digit % _radix < 10)
				digit = digit % _radix + '0';
			else
				digit = digit % _radix + 'A' - 10;
			result.insert(0, 1, digit);
		}

		//add carry
		if (carry)
		{
			if (carry % _radix < 10)
				digit = carry % _radix + '0';
			else
				digit = carry % _radix + 'A' - 10;
			result.insert(0, 1, digit);
		}
		return result;
	}
	else if (_str1.size() < _str2.size())
	{
		int i = _str1.size() - 1, j = _str2.size() - 1;

		//add two digit
		for (; i >= 0; --i, --j)
		{
			digit = _str2[j] <= '9' ? _str2[j] - '0' : _str2[j] + 10 - 'A';
			if (_str1[i] <= '9')
				digit += _str1[i] - '0' + carry;
			else
				digit += _str1[i] + 10 - 'A' + carry;
			carry = digit / _radix;
			if (digit % _radix < 10)
				digit = digit % _radix + '0';
			else
				digit = digit % _radix + 'A' - 10;
			result.insert(0, 1, digit);
		}

		//plus carry
		for (; j >= 0; --j)
		{
			digit = _str2[j] <= '9' ? _str2[j] - '0' : _str2[j] + 10 - 'A';
			digit += carry;
			carry = digit / _radix;
			if (digit % _radix < 10)
				digit = digit % _radix + '0';
			else
				digit = digit % _radix + 'A' - 10;
			result.insert(0, 1, digit);
		}

		//add carry
		if (carry)
		{
			if (carry % _radix < 10)
				digit = carry % _radix + '0';
			else
				digit = carry % _radix + 'A' - 10;
			result.insert(0, 1, digit);
		}
	}
	else//_str1.size() > _str2.size()
	{
		int i = _str2.size() - 1, j = _str1.size() - 1;
		for (; i >= 0; --i, --j)
		{
			digit = _str1[j] <= '9' ? _str1[j] - '0' : _str1[j] + 10 - 'A';
			if (_str2[i] <= '9')
				digit += _str2[i] - '0' + carry;
			else
				digit += _str2[i] + 10 - 'A' + carry;
			carry = digit / _radix;
			if (digit % _radix < 10)
				digit = digit % _radix + '0';
			else
				digit = digit % _radix + 'A' - 10;
			result.insert(0, 1, digit);
		}
		for (; j >= 0; --j)
		{
			digit = _str1[j] <= '9' ? _str1[j] - '0' : _str1[j] + 10 - 'A';
			digit += carry;
			carry = digit / _radix;
			if (digit % _radix < 10)
				digit = digit % _radix + '0';
			else
				digit = digit % _radix + 'A' - 10;
			result.insert(0, 1, digit);
		}
		if (carry)
		{
			if (carry % _radix < 10)
				digit = carry % _radix + '0';
			else
				digit = carry % _radix + 'A' - 10;
			result.insert(0, 1, digit);
		}
	}
	return result;
}
std::string Integer::GetPlusDec(const std::string & _str1, const std::string & _str2)
{
	std::string result;
	char carry = 0, digit;
	if (_str1.size() == _str2.size())
	{
		int i = _str1.size() - 1;
		for (; i >= 0; --i)
		{
			digit = _str1[i] <= '9' ? _str1[i] - '0' : _str1[i] + 10 - 'A';
			digit += _str2[i] - '0' + carry;
			carry = digit / 10;
			digit = digit % 10 + '0';
			result.insert(0, 1, digit);
		}
		if (carry)
		{
			digit = carry % 10 + '0';
			result.insert(0, 1, digit);
		}
		return result;
	}
	else if (_str1.size() < _str2.size())
	{
		int i = _str1.size() - 1, j = _str2.size() - 1;
		for (; i >= 0; --i, --j)
		{
			digit = _str2[j] <= '9' ? _str2[j] - '0' : _str2[j] + 10 - 'A';
			digit += _str1[i] - '0' + carry;
			carry = digit / 10;
			digit = digit % 10 + '0';
			result.insert(0, 1, digit);
		}
		for (; j >= 0; --j)
		{
			digit = _str2[j] <= '9' ? _str2[j] - '0' : _str2[j] + 10 - 'A';
			digit += carry;
			carry = digit / 10;
			digit = digit % 10 + '0';
			result.insert(0, 1, digit);
		}
		if (carry)
		{
			digit = carry % 10 + '0';
			result.insert(0, 1, digit);
		}
	}
	else
	{
		int i = _str2.size() - 1, j = _str1.size() - 1;
		for (; i >= 0; --i, --j)
		{
			digit = _str1[j] <= '9' ? _str1[j] - '0' : _str1[j] + 10 - 'A';
			digit += _str2[i] - '0' + carry;
			carry = digit / 10;
			digit = digit % 10 + '0';
			result.insert(0, 1, digit);
		}
		for (; j >= 0; --j)
		{
			digit = _str1[j] <= '9' ? _str1[j] - '0' : _str1[j] + 10 - 'A';
			digit += carry;
			carry = digit / 10;
			digit = digit % 10 + '0';
			result.insert(0, 1, digit);
		}
		if (carry)
		{
			digit = carry % 10 + '0';
			result.insert(0, 1, digit);
		}
	}


	return result;
}
std::string Integer::GetDuplicate(const std::string & _src, const int & _radix)
{
	char carry = 0, digit;
	std::string result;
	for (unsigned int i = 1; i <= _src.size(); ++i)
	{
		digit = _src[_src.size() - i];

		//
		if (digit <= '9')
			digit = (digit - '0') * 2 + carry;
		else
			digit = (digit - 'A' + 10) * 2 + carry;

		//
		carry = digit / _radix;

		//
		if (digit % _radix < 10)
			digit = digit % _radix + '0';
		else
			digit = digit % _radix + 'A' - 10;

		//
		result.insert(0, 1, digit);
	}

	//
	if (carry)
	{
		if (carry % _radix < 10)
			digit = carry % _radix + '0';
		else
			digit = carry % _radix + 'A' - 10;
		result.insert(0, 1, digit);
	}
	return result;
}
std::string Integer::GetDuplicateDec(const std::string & _src)
{
	char carry = 0, digit;
	std::string result;
	for (unsigned int i = 1; i <= _src.size(); ++i)
	{
		digit = _src[_src.size() - i];
		if (digit <= '9')
			digit = (digit - '0') * 2 + carry;
		else
			digit = (digit - 'A' + 10) * 2 + carry;
		carry = digit / 10;
		digit = digit % 10 + '0';
		result.insert(0, 1, digit);
	}
	if (carry)
	{
		digit = carry % 10 + '0';
		result.insert(0, 1, digit);
	}
	return result;
}
std::string Integer::GetDevideByTwoDec(const std::string & _str)
{
	std::string result;
	char carry = 0;
	bool isSign = _str[0] == '-';
	unsigned int i = isSign;

	for (; i < _str.size(); ++i)
	{
		result.push_back((_str[i] - '0' + carry * 10) / 2 + '0');
		carry = (_str[i] - '0') % 2;
	}

	//remove zero digits which are in front of the numerical string
	while (result[0] == '0')
		result.erase(0, 1);
	if (isSign)
		result.insert(0, 1, '-');

	return result;
}

void Integer::Duplicate(std::string & _src, const int & _radix)
{
	_src = GetDuplicate(_src, _radix);
}
void Integer::DuplicateDec(std::string & _src)
{
	_src = GetDuplicateDec(_src);
}
void Integer::DevideByTwoDec(std::string & _src)
{
	_src = GetDevideByTwoDec(_src);
}

//private methods of object
void Integer::Clear()
{
	for (unsigned int i = 0; i < m_iSize; ++i)
		m_pByte[i] = 0;
}
void Integer::Dispose()
{
	if (m_pByte)
	{
		m_iSize = 0;
		delete m_pByte;
		m_pByte = 0;
	}
}
void Integer::ShiftLeftABit()
{
	SetSize(STANDARD_SIZE);
	for (unsigned int i = 0; i < m_iSize * 8 - 1; ++i)
		SetBit(i, GetBit(i + 1));
	ShrinkToFit();
	SetRawBit(0, false);
}
void Integer::ShiftRightABit()
{
	SetSize(STANDARD_SIZE);
	for (unsigned int i = 0; i < m_iSize * 8 - 1; ++i)
		SetRawBit(i, GetRawBit(i + 1));
	ShrinkToFit();
}
void Integer::RotateLeftABit()
{
	SetSize(STANDARD_SIZE);
	bool tmp = GetBit(0);
	for (unsigned int i = 0; i < m_iSize * 8 - 1; ++i)
		SetBit(i, GetBit(i + 1));
	ShrinkToFit();
	SetRawBit(0, tmp);
}
void Integer::RotateRightABit()
{
	SetSize(STANDARD_SIZE);
	bool tmp = GetRawBit(0);
	for (unsigned int i = 0; i < m_iSize * 8 - 1; ++i)
		SetRawBit(i, GetRawBit(i + 1));
	ShrinkToFit();
	SetBit(0, tmp);
}
void Integer::Copy(const Integer & _src)
{
	for (unsigned int i = 0; i < m_iSize * 8; ++i)
		SetRawBit(i, _src.GetRawBit(i));
}

//public static methods
Integer Integer::FromHexString(const std::string & _str)
{
	Integer result(_str.size() / 2 + _str.size() % 2 + 1);
	for (int i = _str.size() - 1, j = 0; i >= 0; --i, j += 4)
	{
		switch (_str[i])
		{
		case '0':
			break;
		case '1':
			result.SetRawBit(j, true);
			break;
		case '2':
			result.SetRawBit(j + 1, true);
			break;
		case '3':
			result.SetRawBit(j, true);
			result.SetRawBit(j + 1, true);
			break;
		case '4':
			result.SetRawBit(j + 2, true);
			break;
		case '5':
			result.SetRawBit(j, true);
			result.SetRawBit(j + 2, true);
			break;
		case '6':
			result.SetRawBit(j + 1, true);
			result.SetRawBit(j + 2, true);
			break;
		case '7':
			result.SetRawBit(j, true);
			result.SetRawBit(j + 1, true);
			result.SetRawBit(j + 2, true);
			break;
		case '8':
			result.SetRawBit(j + 3, true);
			break;
		case '9':
			result.SetRawBit(j, true);
			result.SetRawBit(j + 3, true);
			break;
		case 'A': case 'a':
			result.SetRawBit(j + 1, true);
			result.SetRawBit(j + 3, true);
			break;
		case 'B': case 'b':
			result.SetRawBit(j, true);
			result.SetRawBit(j + 1, true);
			result.SetRawBit(j + 3, true);
			break;
		case 'C': case 'c':
			result.SetRawBit(j + 2, true);
			result.SetRawBit(j + 3, true);
			break;
		case 'D': case 'd':
			result.SetRawBit(j, true);
			result.SetRawBit(j + 2, true);
			result.SetRawBit(j + 3, true);
			break;
		case 'E': case 'e':
			result.SetRawBit(j + 1, true);
			result.SetRawBit(j + 2, true);
			result.SetRawBit(j + 3, true);
			break;
		case 'F': case 'f':
			result.SetRawBit(j, true);
			result.SetRawBit(j + 1, true);
			result.SetRawBit(j + 3, true);
			result.SetRawBit(j + 2, true);
			break;
		default:
			break;
		}
	}
	result.SetSize(STANDARD_SIZE);
	result.ShrinkToFit();
	return result;
}
Integer Integer::FromDecString(const std::string & _str)
{
	std::string tmp(_str);
	Integer result(_str.size());
	int i = 0;

	while (tmp.size() != 1)
	{
		if ((tmp[tmp.size() - 1] - '0') % 2 == 1)
			result.SetRawBit(i, true);
		DevideByTwoDec(tmp);
		++i;
	}

	//check the last character
	if (tmp[0] == '-')
		result.Negative();
	else
	{
		while (tmp.size() != 0)
		{
			if ((tmp[tmp.size() - 1] - '0') % 2 == 1)
				result.SetRawBit(i, true);
			DevideByTwoDec(tmp);
			++i;
		}
	}
	result.SetSize(STANDARD_SIZE);
	result.ShrinkToFit();
	return result;
}
Integer Integer::FromOctString(const std::string & _str)
{
	Integer result(_str.size() * 3 / 8 + (((_str.size() * 3) % 8) == 0 ? 1 : 2));
	for (int i = _str.size() - 1, j = 0; i >= 0; --i, j += 3)
	{
		switch (_str[i])
		{
		case '0':
			break;
		case '1':
			result.SetRawBit(j, true);
			break;
		case '2':
			result.SetRawBit(j + 1, true);
			break;
		case '3':
			result.SetRawBit(j, true);
			result.SetRawBit(j + 1, true);
			break;
		case '4':
			result.SetRawBit(j + 2, true);
			break;
		case '5':
			result.SetRawBit(j, true);
			result.SetRawBit(j + 2, true);
			break;
		case '6':
			result.SetRawBit(j + 1, true);
			result.SetRawBit(j + 2, true);
			break;
		case '7':
			result.SetRawBit(j, true);
			result.SetRawBit(j + 1, true);
			result.SetRawBit(j + 2, true);
			break;
		default:
			break;
		}
	}
	result.SetSize(STANDARD_SIZE);
	result.ShrinkToFit();
	return result;
}
Integer Integer::FromBinString(const std::string & _str)
{
	Integer result(_str.size() / 8 + ((_str.size() % 8) == 0 ? 1 : 2));

	for (int i = _str.size() - 1, j = 0; i >= 0; --i, ++j)
	{
		switch (_str[i])
		{
		case '0':
			break;
		case '1':
			result.SetRawBit(j, true);
			break;
		default:
			break;
		}
	}
	result.SetSize(STANDARD_SIZE);
	result.ShrinkToFit();
	return result;
}

//constructor & destructor
Integer::Integer()
{
	m_iSize = 1;
	m_pByte = new char[m_iSize];//use 1 byte in default case
	Clear();
}
Integer::Integer(const Integer & _src)//copy constructor
{
	if (this != &_src)
	{
		m_iSize = _src.m_iSize;
		m_pByte = new char[m_iSize];
		for (unsigned int i = 0; i < m_iSize; ++i)
			m_pByte[i] = _src.m_pByte[i];
	}
}
Integer::Integer(const unsigned int & _size)//constructor acording to given size (in byte)
{
	m_iSize = _size;
	m_pByte = new char[m_iSize];
	Clear();
}
Integer::Integer(const std::string & _str, const int & _radix)//constructor acording to string value in radix
{
	m_pByte = 0;
	switch (_radix)
	{
	case 2:
		*this = FromBinString(_str);
		break;
	case 8:
		*this = FromOctString(_str);
		break;
	case 10:
		*this = FromDecString(_str);
		break;
	case 16:
		*this = FromHexString(_str);
		break;
	default:
		m_iSize = 1;
		m_pByte = new char[m_iSize];//use 1 byte in default case
		Clear();
		break;
	}
}
Integer::~Integer()
{
	if (m_pByte)
	{
		m_iSize = 0;
		delete m_pByte;
	}
	m_pByte = 0;
}

//constant methods
unsigned int Integer::GetByteSize() const
{
	return m_iSize;
}
unsigned int Integer::GetBitSize() const
{
	return m_iSize * 8;
}
std::string Integer::GetHexValue() const
{
	char tmp = 0;
	std::string value;
	for (unsigned int i = 0; i < m_iSize * 8; i += 4)
	{
		for (int j = 0; j < 4; ++j)
			tmp += GetRawBit(i + j) * int(pow(2.0, j));
		if (tmp < 10)
			value.insert(0, 1, tmp + '0');
		else
			value.insert(0, 1, tmp % 10 + 'A');
		tmp = 0;
	}
	if (GetBit(0) == true)
		while (value.size() < STANDARD_SIZE * 2)
			value.insert(0, 1, 'F');
	while (value[0] == '0' && value.size() > 1)
		value.erase(0, 1);
	return value;
}
std::string Integer::GetDecValue() const//
{
	std::string value, tmp, sumUp;
	tmp.push_back('1');
	value.push_back('0');

	if (GetBit(0) == true)//negative number
	{
		Integer twoComplement(*this);
		twoComplement.Negative();
		for (unsigned int i = 0; i < m_iSize * 8; ++i)
		{
			if (twoComplement.GetRawBit(i))
				value = GetPlusDec(value, tmp);
			DuplicateDec(tmp);
		}
		value.insert(0, 1, '-');
	}
	else//non-negative number
	{
		for (unsigned int i = 0; i < m_iSize * 8; ++i)
		{
			if (GetRawBit(i))
				value = GetPlusDec(value, tmp);
			DuplicateDec(tmp);
		}
	}
	return value;
}
std::string Integer::GetOctValue() const
{
	char tmp = 0;
	std::string value;
	for (unsigned int i = 0; i < m_iSize * 8; i += 3)
	{
		for (int j = 0; j < 3; ++j)
			tmp += GetRawBit(i + j) * int(pow(2.0, j));
		value.insert(0, 1, tmp + '0');
		tmp = 0;
	}
	if (GetBit(0) == true)
		while (value.size() < STANDARD_SIZE * 8 / 3 + (((STANDARD_SIZE * 8) % 3 == 0 ? 0 : 1)))
			value.insert(0, 1, '7');
	while (value[0] == '0' && value.size() > 1)
		value.erase(0, 1);
	return value;
}
std::string Integer::GetBinValue() const
{
	std::string value;
	for (unsigned int i = 0; i < m_iSize * 8; ++i)
		value.insert(0, 1, GetRawBit(i) + '0');
	if (GetBit(0) == true)
		while (value.size() < STANDARD_SIZE * 8)
			value.insert(0, 1, '1');
	while (value[0] == '0' && value.size() > 1)
		value.erase(0, 1);
	return value;
}
std::string Integer::GetValue(const unsigned short & _radix) const
{
	switch (_radix)
	{
	case 2:
		return GetBinValue();
	case 8:
		return GetOctValue();;
	case 10:
		return GetDecValue();
	case 16:
		return GetHexValue();
	default:
		return "";
	}
}
bool Integer::GetBit(const unsigned int & _index) const
{
	unsigned int realIndex = 8 * m_iSize - _index - 1;
	if (realIndex < 0)
		return false;
	if (realIndex >= 8 * m_iSize)
		return GetBit(0);
	unsigned int byteIndex = realIndex / 8;
	unsigned char mask = 128;
	unsigned int bitIndex = realIndex % 8;
	mask = mask >> bitIndex;
	if ((m_pByte[byteIndex] & mask) != 0)
		return true;
	else
		return false;
}
bool Integer::GetRawBit(const unsigned int & _index) const
{
	if (_index < 0)
		return false;
	if (_index >= 8 * m_iSize)
		return GetBit(0);
	unsigned int byteIndex = _index / 8;
	unsigned int bitIndex = _index % 8;
	unsigned char mask;
	mask = 128;
	mask = mask >> bitIndex;
	if ((m_pByte[byteIndex] & mask) != 0)
		return true;
	return false;
}
bool Integer::operator[](const unsigned int & _index)const
{
	unsigned int realIndex = 8 * m_iSize - _index - 1;
	if (realIndex < 0)
		return false;
	if (realIndex >= 8 * m_iSize)
		return GetBit(0);
	unsigned int byteIndex = realIndex / 8;
	unsigned char mask = 128;
	unsigned int bitIndex = realIndex % 8;
	mask = mask >> bitIndex;
	if ((m_pByte[byteIndex] & mask) != 0)
		return true;
	else
		return false;
}
Integer Integer::GetNegative() const
{
	Integer result(*this);
	for (unsigned int i = 0; i < m_iSize * 8; ++i)
		result.SetRawBit(i, !result.GetRawBit(i));
	unsigned int iSize = m_iSize;
	Integer one(m_iSize);
	one.SetRawBit(0, true);
	result = result + one;
	result.SetSize(iSize);
	return result;
}
Integer Integer::operator ~() const
{
	Integer result(*this);
	for (unsigned int i = 0; i < m_iSize * 8; ++i)
		result.SetRawBit(i, !result.GetRawBit(i));
	return result;
}
Integer Integer::RotateLeft(const unsigned int & _amount) const
{
	Integer result(*this);
	result.SetSize(STANDARD_SIZE);
	for (unsigned int i = 0; i < _amount; ++i)
	{
		bool tmp = result.GetBit(0);
		for (unsigned int j = 0; j < result.m_iSize * 8 - 1; ++j)
			result.SetBit(j, result.GetBit(j + 1));
		result.SetRawBit(0, tmp);
	}
	result.ShrinkToFit();
	return result;
}
Integer Integer::RotateRight(const unsigned int & _amount) const
{
	Integer result(*this);
	result.SetSize(STANDARD_SIZE);
	for (unsigned int i = 0; i < _amount; ++i)
	{
		bool tmp = result.GetRawBit(0);
		for (unsigned int j = 0; j < result.m_iSize * 8 - 1; ++j)
			result.SetRawBit(j, result.GetRawBit(j + 1));
		result.SetBit(0, tmp);
	}
	result.ShrinkToFit();
	return result;
}
Integer::operator std::string() const
{
	return GetBinValue();
}

//modifing methods
void Integer::Negative()
{
	for (unsigned int i = 0; i < m_iSize * 8; ++i)
		SetRawBit(i, !GetRawBit(i));
	unsigned int iSize = m_iSize;
	Integer one(m_iSize);
	one.SetRawBit(0, true);
	*this = *this + one;
	this->SetSize(iSize);
}
void Integer::ShrinkToFit()
{
	if (GetRawBit(m_iSize * 8 - 1) == 1)
		return;
	unsigned int i = m_iSize * 8 - 1, meaningByteNum;
	while (GetRawBit(i) == 0 && i != 0)
		--i;
	i += 2;
	meaningByteNum = (i / 8) + (i % 8 == 0 ? 0 : 1);
	char* pNewByte = new char[meaningByteNum];
	for (unsigned int j = 0; j < meaningByteNum; ++j)
		pNewByte[j] = m_pByte[j];
	delete[] m_pByte;
	m_pByte = pNewByte;
	m_iSize = meaningByteNum;
}
Integer Integer::operator =(const Integer & _src)
{
	if (this != &_src)
	{
		if (m_iSize != _src.m_iSize)
		{
			Dispose();
			m_iSize = _src.m_iSize;
			m_pByte = new char[m_iSize];
		}
		for (unsigned int i = 0; i < m_iSize; ++i)
			m_pByte[i] = _src.m_pByte[i];
	}
	return *this;
}
Integer Integer::operator &(const Integer & _rhs)
{
	unsigned int iBitSize = 8 * (m_iSize < _rhs.m_iSize ? _rhs.m_iSize : m_iSize);
	Integer result(iBitSize / 8);
	for (unsigned int i = 0; i < iBitSize; ++i)
		result.SetRawBit(i, (GetRawBit(i) && _rhs.GetRawBit(i)));
	return result;
}
Integer Integer::operator |(const Integer & _rhs)
{
	unsigned int iBitSize = 8 * (m_iSize < _rhs.m_iSize ? _rhs.m_iSize : m_iSize);
	Integer result(iBitSize / 8);
	for (unsigned int i = 0; i < iBitSize; ++i)
		result.SetRawBit(i, (GetRawBit(i) || _rhs.GetRawBit(i)));
	return result;
}
Integer Integer::operator ^(const Integer & _rhs)
{
	unsigned int iBitSize = 8 * (m_iSize < _rhs.m_iSize ? _rhs.m_iSize : m_iSize);
	Integer result(iBitSize / 8);
	for (unsigned int i = 0; i < iBitSize; ++i)
	{
		result.SetRawBit(i, (GetRawBit(i) ^ _rhs.GetRawBit(i)));
	}
	return result;
}
bool Integer::SetSize(const unsigned int & _iSize)
{
	if (_iSize == m_iSize)
		return true;
	else if (_iSize < m_iSize)
	{
		char * p = new char[_iSize];
		for (unsigned int i = 0; i < _iSize; ++i)
			p[i] = m_pByte[i];
		m_iSize = _iSize;
		delete[] m_pByte;
		m_pByte = p;
		return false;
	}
	else
	{
		char * p = new char[_iSize];
		unsigned int i;
		for (i = 0; i < m_iSize; ++i)
			p[i] = m_pByte[i];
		unsigned char exByte;
		if (GetRawBit(GetBitSize() - 1) == true)
			exByte = 255;
		else
			exByte = 0;
		for (; i < _iSize; ++i)
			p[i] = exByte;
		m_iSize = _iSize;
		delete[] m_pByte;
		m_pByte = p;
		return true;
	}
}
bool Integer::SetBit(const unsigned int & _index, const bool & _value)
{
	unsigned int realIndex = 8 * m_iSize - _index - 1;
	if (realIndex < 0 || realIndex >= 8 * m_iSize)
		return false;
	unsigned int byteIndex = realIndex / 8;
	unsigned int bitIndex = realIndex % 8;
	unsigned char mask;
	if (_value == true)
	{
		mask = 128;
		mask = mask >> bitIndex;
		m_pByte[byteIndex] = m_pByte[byteIndex] | mask;
	}
	else
	{
		mask = 255;
		mask -= int(pow(2, 7.0 - bitIndex));
		m_pByte[byteIndex] = m_pByte[byteIndex] & mask;
	}
	return true;
}
bool Integer::SetRawBit(const unsigned int & _index, const bool & _value)
{
	if (_index < 0 || _index >= 8 * m_iSize)
		return false;
	unsigned int byteIndex = _index / 8;
	unsigned int bitIndex = _index % 8;
	unsigned char mask;
	if (_value == true)
	{
		mask = 128;
		mask = mask >> bitIndex;
		m_pByte[byteIndex] = m_pByte[byteIndex] | mask;
	}
	else
	{
		mask = 255;
		mask -= int(pow(2, 7.0 - bitIndex));
		m_pByte[byteIndex] = m_pByte[byteIndex] & mask;
	}
	return true;
}
bool Integer::ResetBit(const unsigned int & _index)
{
	unsigned int realIndex = 8 * m_iSize - _index - 1;
	if (realIndex < 0 || realIndex >= 8 * m_iSize)
		return false;
	unsigned int byteIndex = realIndex / 8;
	unsigned int bitIndex = realIndex % 8;
	unsigned char mask;
	mask = 255;
	mask -= int(pow(2, 7.0 - bitIndex));
	m_pByte[byteIndex] = m_pByte[byteIndex] & mask;
	return true;
}
bool Integer::ResetRawBit(const unsigned int & _index)
{
	if (_index < 0 || _index >= 8 * m_iSize)
		return false;
	unsigned int byteIndex = _index / 8;
	unsigned int bitIndex = _index % 8;
	unsigned char mask;
	mask = 255;
	mask -= int(pow(2, 7.0 - bitIndex));
	m_pByte[byteIndex] = m_pByte[byteIndex] & mask;
	return true;
}

//friend methods/operators
Integer operator >>(const Integer & _lhs, const unsigned int & _amount)
{
	Integer result(_lhs);
	for (unsigned int i = 0; i < _amount; ++i)
		result.ShiftRightABit();
	return result;
}
Integer operator <<(const Integer & _lhs, const unsigned int & _amount)
{
	Integer result(_lhs);
	for (unsigned int i = 0; i < _amount; ++i)
		result.ShiftLeftABit();
	return result;
}

Integer operator +(const Integer & _lhs, const Integer & _rhs)
{
	bool carry = false;
	bool lhsBit, rhsBit;
	Integer result(_lhs.m_iSize > _rhs.m_iSize ? _lhs.m_iSize : _rhs.m_iSize);

	for (unsigned int i = 0; i < result.m_iSize * 8; ++i)
	{
		lhsBit = _lhs.GetRawBit(i);
		rhsBit = _rhs.GetRawBit(i);
		if (lhsBit == rhsBit)
		{
			result.SetRawBit(i, carry);
			carry = lhsBit;
		}
		else if (lhsBit != rhsBit)
			result.SetRawBit(i, true && !carry);
	}
	if (carry)
	{
		result.SetSize(result.m_iSize + 1);
		result.SetRawBit((result.m_iSize - 1) * 8);
	}
	return result;
}
Integer operator -(const Integer & _lhs, const Integer & _rhs)
{
	bool carry = false;
	Integer result(_lhs.m_iSize > _rhs.m_iSize ? _lhs.m_iSize : _rhs.m_iSize);

	////full case
	//for (unsigned int i = 0; i < result.m_iSize * 8; ++i)
	//{
	//	if (_lhs.GetRawBit(i) == false && _rhs.GetRawBit(i) == false)
	//		if (carry == true)
	//			result.SetRawBit(i, true);
	//		else
	//		{
	//			result.SetRawBit(i, false);
	//		}
	//	else if (_lhs.GetRawBit(i) == false && _rhs.GetRawBit(i) == true)
	//	{
	//		if (carry == true)
	//			result.SetRawBit(i, false);
	//		else
	//		{
	//			result.SetRawBit(i, true);
	//			carry = true;
	//		}
	//	}
	//	else if (_lhs.GetRawBit(i) == true && _rhs.GetRawBit(i) == false)
	//	{
	//		if (carry == true)
	//		{
	//			result.SetRawBit(i, false);
	//			carry = false;
	//		}
	//		else
	//			result.SetRawBit(i, true);
	//	}
	//	else if (_lhs.GetRawBit(i) == true && _rhs.GetRawBit(i) == true)
	//		if (carry == true)
	//			result.SetRawBit(i, true);
	//		else
	//			result.SetRawBit(i, false);
	//}

	//short case
	bool lhsBit, rhsBit;
	for (unsigned int i = 0; i < result.m_iSize * 8; ++i)
	{
		lhsBit = _lhs.GetRawBit(i);
		rhsBit = _rhs.GetRawBit(i);
		if (lhsBit == rhsBit)
			result.SetRawBit(i, carry);
		else if (lhsBit != rhsBit)
		{
			result.SetRawBit(i, !carry);
			carry = !lhsBit;
		}
	}
	return result;
}
Integer operator *(const Integer & _lhs, const Integer & _rhs)
{
	//setup
	Integer result(_lhs.m_iSize + _rhs.m_iSize);

	Integer A;
	A.Dispose();
	A.m_iSize = _lhs.m_iSize;
	A.m_pByte = result.m_pByte + _rhs.m_iSize;


	Integer Q;
	Q.Dispose();
	Q.m_iSize = _rhs.m_iSize;
	Q.m_pByte = result.m_pByte;

	for (unsigned int i = 0; i < _rhs.m_iSize; ++i)
		Q.m_pByte[i] = _rhs.m_pByte[i];

	bool Qz = false;

	//
	for (unsigned int i = 0; i < _rhs.m_iSize * 8; ++i)
	{
		if (Q.GetRawBit(0) == false && Qz == true)
			A.Copy(A + _lhs);
		if (Q.GetRawBit(0) == true && Qz == false)
			A.Copy(A - _lhs);
		//shift
		Qz = Q.GetRawBit(0);
		for (unsigned int j = 0; j < result.m_iSize * 8 - 1; ++j)
			result.SetRawBit(j, result.GetRawBit(j + 1));
	}
	Q.m_iSize = A.m_iSize = 0;
	Q.m_pByte = A.m_pByte = 0;
	result.ShrinkToFit();
	return result;
}
Integer operator /(const Integer & _lhs, const Integer & _rhs)
{
	//repair
	unsigned int size = _lhs.m_iSize > _rhs.m_iSize ? _lhs.m_iSize : _rhs.m_iSize;
	Integer lhsTemp(_lhs), rhsTemp(_rhs);
	lhsTemp.SetSize(size);
	rhsTemp.SetSize(size);
	if (_lhs.GetBit(0) == true)//_lhs is negative
	{
		lhsTemp.Negative();
		rhsTemp.Negative();
	}
	//setup
	Integer QA(lhsTemp.m_iSize + rhsTemp.m_iSize);

	Integer Q;
	Q.Dispose();
	Q.m_iSize = lhsTemp.m_iSize;
	Q.m_pByte = QA.m_pByte;

	Integer A;
	A.Dispose();
	A.m_iSize = rhsTemp.m_iSize;
	A.m_pByte = QA.m_pByte + lhsTemp.m_iSize;

	for (unsigned int i = 0; i < lhsTemp.m_iSize; ++i)
		Q.m_pByte[i] = lhsTemp.m_pByte[i];

	if (Q.GetBit(0) == 1)
		for (unsigned int i = 0; i < A.m_iSize; ++i)
			A.m_pByte[i] = -1;

	//
	if (rhsTemp.GetBit(0) == false)//rhsTemp is positive
		for (unsigned int i = 0; i < rhsTemp.m_iSize * 8; ++i)
		{
			//shift
			for (unsigned int j = 0; j < QA.m_iSize * 8; ++j)
				QA.SetBit(j, QA.GetBit(j + 1));
			QA.SetRawBit(0, false);

			A.Copy(A - rhsTemp);
			if (A.GetBit(0) == true)
			{
				Q.SetRawBit(0, false);
				A.Copy(A + rhsTemp);
			}
			else
				Q.SetRawBit(0, true);
		}
	else//rhsTemp is negative
		for (unsigned int i = 0; i < rhsTemp.m_iSize * 8; ++i)
		{
			//shift
			for (unsigned int j = 0; j < QA.m_iSize * 8; ++j)
				QA.SetBit(j, QA.GetBit(j + 1));
			QA.SetRawBit(0, false);

			A.Copy(A + rhsTemp);
			if (A.GetBit(0) == true)
			{
				Q.SetRawBit(0, false);
				A.Copy(A - rhsTemp);
			}
			else
				Q.SetRawBit(0, true);
		}
	Integer result(Q);
	result.ShrinkToFit();
	if (rhsTemp.GetBit(0) == true)
		result.Negative();
	Q.m_iSize = A.m_iSize = 0;
	Q.m_pByte = A.m_pByte = 0;
	result.ShrinkToFit();
	return result;
}


