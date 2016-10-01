#pragma once
#include <string>


class Integer
{
	unsigned int m_iSize;//size of memory in byte
	char * m_pByte;//pointer to the used memory

	//private static methods
	static std::string GetPlus(const std::string &, const std::string &, const int &);
	static std::string GetPlusDec(const std::string &, const std::string &);
	static std::string GetDuplicate(const std::string &, const int &);
	static std::string GetDuplicateDec(const std::string &);
	static std::string GetDevideByTwoDec(const std::string &);
	
	static void Duplicate(std::string &, const int &);
	static void DuplicateDec(std::string &);
	static void DevideByTwoDec(std::string &);

	//private methods of object
	void Clear();
	void Dispose();
	void ShiftLeftABit();
	void ShiftRightABit();
	void RotateLeftABit();
	void RotateRightABit();
	void Copy(const Integer &);

public:
	static const unsigned int STANDARD_SIZE;

	//public static methods
	static Integer FromHexString(const std::string &);
	static Integer FromDecString(const std::string &);
	static Integer FromOctString(const std::string &);
	static Integer FromBinString(const std::string &);

	//constructor & destructor
	Integer();
	Integer(const Integer &);
	Integer(const std::string &, const int &);
	Integer(const unsigned int &);
	~Integer();

	//constant methods
	unsigned int GetByteSize() const;
	unsigned int GetBitSize() const;
	std::string GetHexValue() const;
	std::string GetDecValue() const;
	std::string GetOctValue() const;
	std::string GetBinValue() const;
	std::string GetValue(const unsigned short &) const;
	bool GetBit(const unsigned int &) const;
	bool GetRawBit(const unsigned int &) const;
	bool operator[](const unsigned int &) const;//the same as GetBit
	Integer operator ~() const;
	Integer GetNegative() const;
	Integer RotateLeft(const unsigned int & = 1) const;
	Integer RotateRight(const unsigned int & = 1) const;
	operator std::string() const;

	//modifing methods
	void Negative();
	void ShrinkToFit();//reducing the size but keeping value
	Integer operator =(const Integer &);
	Integer operator &(const Integer &);
	Integer operator |(const Integer &);
	Integer operator ^(const Integer &);
	bool SetSize(const unsigned int &);//mordify the size, do not guarantee on the value if new size less than the old one, in other cases, the value is unchange
	bool SetBit(const unsigned int &, const bool & = true);
	bool SetRawBit(const unsigned int &, const bool & = true);
	bool ResetBit(const unsigned int &);//set bit to false
	bool ResetRawBit(const unsigned int &);//set raw bit to false


	//friend methods/operators
	friend Integer operator >> (const Integer &, const unsigned int &);
	friend Integer operator << (const Integer &, const unsigned int &);

	friend Integer operator +(const Integer &, const Integer &);
	friend Integer operator -(const Integer &, const Integer &);
	friend Integer operator *(const Integer &, const Integer &);
	friend Integer operator /(const Integer &, const Integer &);
};

