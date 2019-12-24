#include "EncodeData.h"

EncodeData::EncodeData()
{
	
}
EncodeData::~EncodeData()
{

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

	m_Input =_Input;

	for (int m_I = 0; m_Input > 0; m_I++)
	{
		m_Binary.push_back( m_Input % 2);
		m_Input = m_Input / 2;
	}

	if (m_Binary.size() < m_BaseVal)
	{
		for(int m_I=m_Binary.size();m_I<m_BaseVal; m_I++)
			m_ReverceBinary.push_back(0);
	}
	int m_Size = m_Binary.size();

	for (int m_I = m_Size; m_I > 0; m_I--)
	{
		m_ReverceBinary.push_back(m_Binary[m_I-1]);
	}

	return m_ReverceBinary;
}