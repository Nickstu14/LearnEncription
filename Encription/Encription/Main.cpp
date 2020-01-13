#include <iostream>
#include <vector>
#include "EncodeData.h"

#pragma once

int main()
{
	std::string m_Input;
	std::vector<EncodeData*> m_Data;
	std::vector<EncodeData*> m_EncodedData;
	std::vector<int> m_BinaryLine;
	int m_NewBit;
	int m_Counter = 0;

	//Get user input
	std::cout << "Enter Password: ";
	//std::cin >> m_Input;

	std::getline(std::cin, m_Input); //for the user to input a sentence

	for (char m_Char : m_Input)
	{ // place letters into the class, this will break it down into ascii and binary
		EncodeData* m_TempEncode = new EncodeData();
		m_TempEncode->SetupLetter(m_Char, 8);
		m_Data.push_back(m_TempEncode);
	}

	//attach all binary values into a long line
	for (EncodeData* m_Binary : m_Data)
	{
		std::vector<int> m_Bin = m_Binary->GetBinary();
		for (int m_Bit : m_Bin)
		{
			m_BinaryLine.push_back(m_Bit);
		}
	}

	for (int m_I = 0; m_I < m_BinaryLine.size(); m_I++)
	{ //debug printout
		std::cout << m_BinaryLine.at(m_I);
	}

	std::cout << std::endl << "Bits:" << m_BinaryLine.size() << std::endl;

	//Ask user for new bit to conver to
	std::cout << "\nConvert to bit: ";
	std::cin >> m_NewBit;

	char m_Val = 'A';

	for (int m_I = 0; m_I <= m_BinaryLine.size() - 1; m_I++)
	{
		//if ((m_I + m_NewBit) <= m_BinaryLine.size())
		{
			int m_J;
			EncodeData* m_TempEncode = new EncodeData();
			std::vector<int> m_NewBitBinary;
			for (m_J = 0; m_J <= m_NewBit - 1; m_J++)
			{
				if ((m_I + 1) <= m_BinaryLine.size())
				{
					m_NewBitBinary.push_back(m_BinaryLine.at(m_I + m_J));
					std::cout << m_I + m_J << " " << m_BinaryLine.at(m_I + m_J) << std::endl;
				}
			}
			if (m_NewBitBinary.size() < m_NewBit)
			{
				for (int m_K = m_NewBitBinary.size(); m_K <= m_NewBit - 1; m_K++)
					m_NewBitBinary.push_back(0);
			}

			std::cout << std::endl << "---" << std::endl;

			m_TempEncode->SetupBinary(m_NewBitBinary, m_NewBit);
			m_EncodedData.push_back(m_TempEncode);
			m_I += m_J - 1;
		}
	}

	


	for (EncodeData* m_ED : m_EncodedData)
	{
		std::cout << m_ED->GetLetter();
	}
	//endcode into varied base

	//display encode

	//encryipt maybe

	return 0;
}