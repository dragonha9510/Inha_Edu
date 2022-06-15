#pragma once 
 
#ifndef __SOCIALACCOUNT_H__
#define __SOCIALACCOUNT_H__
 
class CSocialAccount
{
public:
	explicit CSocialAccount() {};
	~CSocialAccount() { delete[] m_pFriendArr; };

public: // get
	size_t getMyID() { return m_iMyNum; }
	size_t getMyFriend() { return m_iFriendCnt; }
	int* getMyFriendList() { return m_pFriendArr; }

public:
	void Init(int num, int max) { m_iMyNum = num; m_pFriendArr = new int[max]; }
	size_t AddFriend(CSocialAccount& fr);

private:
	size_t m_iMyNum = 0;
	size_t m_iFriendCnt = 0;
	int* m_pFriendArr = nullptr;
};

#endif // !__SOCIALACCOUNT_H__