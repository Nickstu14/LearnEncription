#ifndef _ENCODEDATA_H_
#define _ENCODEDATA_H_
#include <string>
#include <vector>

class EncodeData
{
public:
	EncodeData();
	~EncodeData();

	void SetupLetter(char& _char, int _BaseVal);
	void SetupBinary(std::vector<int> _Binary, int _BaseVal);

	int CharToAscii(char _Input);
	std::vector<int> IntToBinary(int _Input);
	int BinaryToAscii(std::vector<int> _Binary, int _BaceVal);

	void SetLetter(char _val) { m_Letter = _val; }
	void SetNumber(int _Val) { m_AsciiNumber = _Val; }
	void SetBinary(std::vector<int> _Val) { m_Binary = _Val; }
	void SetBaseVal(int _Val) { m_BaseVal = _Val; }

	char GetLetter() { return m_Letter; }
	int GetNumber() { return m_AsciiNumber; }
	std::vector<int> GetBinary() { return m_Binary; }
	int GetBaseVal() { return m_BaseVal; }


private:
	char m_Letter;
	int m_AsciiNumber;
	std::vector<int> m_Binary;
	int m_BaseVal;
};


#endif // !_ENCODEDATA_H_

