#include "stdafx0614.h"
#include "SocialAccount.h" 

size_t CSocialAccount::AddFriend(CSocialAccount& fr)
{
	bool bIsIn = false;

	for (size_t i = 0; i < m_iFriendCnt; ++i)
	{
		if (m_pFriendArr[i] == fr.getMyID())
		{
			bIsIn = true;
			break;
		}
	}
	
	if(!bIsIn)
		m_pFriendArr[m_iFriendCnt++] = fr.getMyID();
	
	bIsIn = false;

	int* p = fr.getMyFriendList();
	size_t fs = fr.getMyFriend();

	for (size_t i = 0; i < fs; ++i)
	{
		for (size_t j = 0; j < m_iFriendCnt; ++j)
		{
			if ((m_pFriendArr[j] == p[i]) || (p[i] == m_iMyNum))
			{
				bIsIn = true;
				break;
			}
		}
		if (!bIsIn)
			m_pFriendArr[m_iFriendCnt++] = p[i];
	}

	return m_iFriendCnt;
}
