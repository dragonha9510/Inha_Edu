#pragma once 
 
#ifndef __WORKER_H__
#define __WORKER_H__
 
class CWorker
{
public:
	explicit CWorker() : fullname("no name"), id(0L) {};
	CWorker(const std::string& s, long n)
		:fullname(s), id(n) {}
	virtual ~CWorker() = 0;
	virtual void Set();
	virtual void Show() const;

private:
	string fullname;
	long id;
};

class CWaiter : public CWorker
{
private:
	int panache;
public:
	CWaiter() : CWorker(), panache(0) {}
	CWaiter(const string& s, long n, int p = 0)
		: CWorker(s, n), panache(p) {}
	CWaiter(const CWorker& wk, int p = 0)
		: CWorker(wk), panache(p) {}
	void Set();
	void Show() const;
};

class CSinger : public CWorker
{
protected:
	enum { other, alto, contralto, soprano, bass, baritone, tenor };
	enum { Vtypes = 7 };

private:
	static const char* pv[Vtypes];
	int voice;
public:
	CSinger() : CWorker(), voice(other) {};
	CSinger(const string& s, long n, int v = other)
		: CWorker(s, n), voice(v) {}
	CSinger(const CWorker& wk, int v = other)
		: CWorker(wk), voice(v) {}
	void Set();
	void Show() const;
};
#endif // !__WORKER_H__