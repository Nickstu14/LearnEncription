#include "EncodeData.h"


EncodeData::EncodeData()
{
	
}
EncodeData::~EncodeData()
{

}

void EncodeData::SetupLetter(char& _Char, int _BaseVal)
{
	SetLetter(_Char);
	SetBaseVal(_BaseVal);
	SetNumber(CharToAscii(_Char));
	SetBinary(IntToBinary(GetNumber()));
}

void EncodeData::SetupBinary(std::vector<int> _Binary, int _BaseVal)
{
	SetNumber(BinaryToAscii(_Binary, _BaseVal));
	SetLetter(AsciiToChar(GetNumber()));
}

int EncodeData::CharToAscii(char _Input)
{
	int m_Val;

	m_Val = int(_Input);
	return m_Val;
}
std::vector<int> EncodeData::IntToBinary(int _Input)
{
	int m_Input;
	std::vector<int> m_Binary;
	std::vector<int> m_ReverceBinary;

	m_Input = _Input;

	for (int m_I = 0; m_Input > 0; m_I++)
	{
		m_Binary.push_back(m_Input % 2);
		m_Input = m_Input / 2;
	}

	if (m_Binary.size() < m_BaseVal)
	{
		for (int m_I = m_Binary.size(); m_I < m_BaseVal; m_I++)
			m_ReverceBinary.push_back(0);
	}
	int m_Size = m_Binary.size();

	for (int m_I = m_Size; m_I > 0; m_I--)
	{
		m_ReverceBinary.push_back(m_Binary[m_I - 1]);
	}

	return m_ReverceBinary;
}

int EncodeData::BinaryToAscii(std::vector<int> _Binary, int _BaceVal)
{
	int m_DecimalNum = 0;
	int m_Bace = 1;

	for (unsigned int m_I = _Binary.size() - 1; m_I >= 0; m_I--)
	{
		m_DecimalNum += _Binary[m_I] * m_Bace;
		m_Bace *= 2;

		if (m_I == 0)
			break;
	}

	return m_DecimalNum;
}

char EncodeData::AsciiToChar(int _Number)
{
	char m_Char = _Number;
	return m_Char;
}