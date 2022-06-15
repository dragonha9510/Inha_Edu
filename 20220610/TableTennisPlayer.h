#pragma once 
 
#ifndef __TABLETENNISPLAYER_H__
#define __TABLETENNISPLAYER_H__
 
class CTableTennisPlayer
{
public:
	virtual	~CTableTennisPlayer();

public:
	CTableTennisPlayer(const string& fn = "none",
		const string& ln = "none", bool ht = false);

public:
	void Name() const;
	bool HasTable() const { return hasTable; }
	void ResetTable(bool v) { hasTable = v; }

private:
	string firstname;
	string lastname;
	bool hasTable = false;
};

#endif // !__TABLETENNISPLAYER_H__