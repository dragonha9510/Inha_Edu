#pragma once 
 
#ifndef __RATEDPLAYER_H__
#define __RATEDPLAYER_H__
 
class CTableTennisPlayer;

class CRatedPlayer : public CTableTennisPlayer
{
public:
	explicit CRatedPlayer();
	virtual ~CRatedPlayer();

public:
	CRatedPlayer(unsigned int r = 0, const string& fn = "none",
		const string& ln = "none", bool ht = false);
	CRatedPlayer(unsigned int r, const CTableTennisPlayer& tp);
	
public:
	unsigned int Rating() { return rating; }
	void ResetRating(unsigned int r) { rating = r; }

private:
	unsigned int rating;
};

#endif // !__RATEDPLAYER_H__