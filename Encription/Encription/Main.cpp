#include <iostream>
#include <vector>
#include "EncodeData.h"

#pragma once

int main()
{
	std::string m_Input;
	std::vector<EncodeData> m_Data;

	//Get user input
	std::cout << "Enter Password: ";
	std::cin >> m_Input;
	
	for (char m_Char : m_Input)
	{
		EncodeData m_Encode;
		m_Encode.SetLetter(m_Char);
		m_Encode.SetBaseVal(8);
		m_Encode.SetNumber(m_Encode.CharToAscii(m_Char));
		m_Encode.SetBinary(m_Encode.IntToBinary(m_Encode.GetNumber()));

		m_Data.push_back(m_Encode);
	}


	//endcode into varied base

	//display encode

	//encryipt maybe

	return 0;
}