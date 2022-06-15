#include "stdafx0610.h"
#include "RatedPlayer.h" 
#include "TableTennisPlayer.h"

CRatedPlayer::CRatedPlayer()
{
}

CRatedPlayer::~CRatedPlayer()
{
}

CRatedPlayer::CRatedPlayer(unsigned int r, const string& fn, const string& ln, bool ht)
	:CTableTennisPlayer(fn, ln, ht)
{
	rating = r;
}

CRatedPlayer::CRatedPlayer(unsigned int r, const CTableTennisPlayer& tp)
	: CTableTennisPlayer(tp), rating(r)
{
}

