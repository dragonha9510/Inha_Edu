#include "stdafx0610.h"
#include "TableTennisPlayer.h" 

CTableTennisPlayer::~CTableTennisPlayer()
{
}

CTableTennisPlayer::CTableTennisPlayer(const string& fn, const string& ln, bool ht)
	:firstname(fn), lastname(ln), hasTable(ht)
{

}

void CTableTennisPlayer::Name() const
{
	cout << lastname << ", " << firstname;
}

