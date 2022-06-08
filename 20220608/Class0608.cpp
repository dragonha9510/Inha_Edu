#include "stdafx0608.h"

void One()
{
	CStonewt poppins(9, 2.8);
	double p_wt = poppins;

	cout << "double������ ��ȯ => ";
	cout << "Poppins : " << p_wt << "�Ŀ��" << endl;
	cout << "int������ ��ȯ => ";
	cout << "Poppins : " << int(poppins) << "�Ŀ��" << endl;
}

// ������ �����ϴ� Circle2DŬ������ �����϶�.
// -���� �߽��� ��Ÿ���� x, y��� �ΰ��� double�� �׸��� get ��� �Լ�
// -(x,y)�� (0,0), radius�� 1�� �⺻ ���� �����ϴ� ���ڰ� ���� ������
// -������ x,y�� radius�� ���� �����ϴ� ������.
// -���� ������ ��ȯ�ϴ� GetArea() ��� �Լ�
// -���� �ѷ��� ��ȯ�ϴ� getPerimeter() ��� �Լ�
// -������ �� (x,y)�� ������ �� ���ο� ���� ��� true ��ȯ�Լ� contains ����Լ�
// -������ ���� �� ���ο����� ��� true // contains
// ������ ���� ������ ���� ��ø�Ǵ� ��� true // overlaps
// Ŭ������ ���� UML���̾� �׷��� �׸��� Ŭ���� ����

// ���� �Է� c1(2,2,5.5) c2(2,2,5.5) c3(4,5,10.5)
// c1 ����, �ѷ� contains(3.3),
// contains(c2) overlaps(c3) ��� ���

void Question1()
{
	CCircle2D c1(2, 2, 5.5);
	CCircle2D c2(2, 2, 5.5);
	CCircle2D c3(4, 5, 10.5);

	cout << "c1�� ���� : " << c1.getArea() << endl;
	cout << "c1�� �ѷ� : " << c1.getPerimeter() << endl;
	cout << "c1.contains(3,3) : " << (c1.Contains(3, 3) ? "TRUE" : "FALSE") << endl;
	cout << "c1.contains(c2) : " << (c1.Contains(c2) ? "TRUE" : "FALSE") << endl;
	cout << "c1.overlaps(c3) : " << (c1.Overlaps(c3) ? "TRUE" : "FALSE") << endl;
}

// ������ �����ϴ� Rectangle2D Ŭ������ �����϶�.
// - ���簢���� �߽��� ��Ÿ���� x,y �� ���� double
//	�̿� ���� get ��� �Լ��� set �Լ�, �簢���� ���� x��� y�࿡ ������ ������ ����.
// - double ������ �ʵ� width, height �� �̿� ���� get, set
// - x,y = 0,0 width, height = 1,1�� �⺻ ����
// - �����ؼ� �����ϴ� ������
// - getArea() ����
// - getPerimeter() �ѷ�
// - ���� ���簢�� ���ο� ���� ��� true (contains(x,y)) const
// - �簢���� ���ο� ���� ��� true(contains(Rectangle2D)) const
// - ������ ���簢���� ������ ���簢���� ��ø true (overlaps(Rectangle2D)) const
// 
// ���� �Է� r1(2,2,5.5,4.9), r2(4,5,10.5,3.2), r3(3,5,2.3,5.4)
// r1 ����, �ѷ� ���
// r1.contains(3,3)
// r1.contains(r2)
// r1.overlaps(r3)
//

void Question2()
{
	CRectangle2D r1(0, 4, 4, 2);
	CRectangle2D r2(0, 1, 2, 4);
	CRectangle2D r3(2, 0, 2, 2);

	
	cout << "r1 ���� : " << r1.getArea() << endl;
	cout << "r1 �ѷ� : " << r1.getPerimeter() << endl;

	cout << "r1.contains(3,3) : " << (r1.Contains(3, 3) ? "TRUE" : "FALSE") << endl;
	cout << "r1.contains(r2) : " << (r1.Contains(r2) ? "TRUE" : "FALSE") << endl;
	cout << "r1.overlaps(r3) : " << (r1.Overlaps(r3) ? "TRUE" : "FALSE") << endl;
}

// x �� y���� ���� ǥ���ϴ� MyPoint Ŭ������ �����϶�
// - ��ǥ�� ��Ÿ���� �� ���� x, y
// - �� (0,0)�� �����ϴ� �μ� ���� ������
// - ���� ��ǥ�� ���� �����ϴ� ������
// - x, y get�Լ� const
// - MyPoint ������ �� ������ �ٸ� �� ������ �Ÿ��� ��ȯ�ϴ� Distance
// 
// ���� (0,0) -> (10, 30.5) ���� ������ �Ÿ�
// 
// ������ ��ǥ�� ���� Circle, Rectangle ���ο� �ִ��� �Ǵ��ϴ� constains�� ������� ����
//

void Question3()
{
	CMyPoint p1(0, 0);
	CMyPoint p2(10, 30.5);

	cout << "Distance : " << p1.getDistance(p2) << endl;

	CRectangle2D r1(1, 1, 2, 2);

	CCircle2D c1(1, 1, 3);
	
	cout << "c1.Contains(p1) : " << (Contains(c1, p1) ? "TRUE" : "FALSE") << endl;
	cout << "r1.Contains(p1) : " << (Contains(r1, p1) ? "TRUE" : "FALSE") << endl;
}