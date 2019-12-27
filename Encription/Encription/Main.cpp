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
	int m_Counter=0;

	//Get user input
	std::cout << "Enter Password: ";
	//std::cin >> m_Input;

	std::getline(std::cin, m_Input); //for the user to input a sentence

	for (char m_Char : m_Input)
	{ // place letters into the class, this will break it down into ascii and binary
		m_Data.push_back(new EncodeData());
		m_Data.at(m_Data.end()).SetupLetter(m_Char, 8);
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

	for (int m_I =0; m_I < m_BinaryLine.size(); m_I++)
	{ //debug printout
		std::cout << m_BinaryLine.at(m_I);
	}

	//Ask user for new bit to conver to
	std::cout << "\nConvert to bit: ";
	std::cin >> m_NewBit;

	char m_Val = 'A';
	
	
	do
	{
		std::vector<int> m_NewBitBinary;
		for (int m_I = 0; m_I < m_NewBit; m_I++)
		{
			m_NewBitBinary.push_back(m_BinaryLine.at(m_Counter));
			m_Counter++;
		}
		if (m_BinaryLine.size() < m_NewBit)
		{
			for (int m_J = m_BinaryLine.size(); m_J < m_NewBit; m_J++)
				m_NewBitBinary.push_back(0);
		}

		m_EncodedData.push_back(new EncodeData());
		m_EncodedData.end()->SetupBinary(m_NewBitBinary);

	} while (m_Counter <= m_BinaryLine.size());
	//endcode into varied base

	//display encode

	//encryipt maybe

	return 0;
}