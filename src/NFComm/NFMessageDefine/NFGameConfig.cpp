
#include "NFGameConfig.h"
#include "NFComm/NFCore/NFIniReader.h"


std::string NFToString(int iValue)
{
	char ch[20] = { 0 };
	sprintf(ch, "%d", iValue);
	return ch;
}

