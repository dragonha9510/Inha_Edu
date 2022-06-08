#include "stdafx0608.h"

void One()
{
	CStonewt poppins(9, 2.8);
	double p_wt = poppins;

	cout << "double형으로 변환 => ";
	cout << "Poppins : " << p_wt << "파운드" << endl;
	cout << "int형으로 변환 => ";
	cout << "Poppins : " << int(poppins) << "파운드" << endl;
}

// 다음을 포함하는 Circle2D클래스를 정의하라.
// -원의 중심을 나타내는 x, y라는 두개의 double형 그리고 get 상수 함수
// -(x,y)가 (0,0), radius가 1인 기본 원을 생성하는 인자가 없는 생성자
// -지정된 x,y와 radius로 원을 생성하는 생성자.
// -원의 면적을 반환하는 GetArea() 상수 함수
// -원의 둘레를 반환하는 getPerimeter() 상수 함수
// -지정된 점 (x,y)가 생성된 원 내부에 있을 경우 true 반환함수 contains 상수함수
// -지정된 원이 원 내부에있을 경우 true // contains
// 지정된 원이 생성된 원가 중첩되는 경우 true // overlaps
// 클래스에 대한 UML다이어 그램을 그리고 클래스 구현

// 예제 입력 c1(2,2,5.5) c2(2,2,5.5) c3(4,5,10.5)
// c1 면적, 둘레 contains(3.3),
// contains(c2) overlaps(c3) 결과 출력

void Question1()
{
	CCircle2D c1(2, 2, 5.5);
	CCircle2D c2(2, 2, 5.5);
	CCircle2D c3(4, 5, 10.5);

	cout << "c1의 면적 : " << c1.getArea() << endl;
	cout << "c1의 둘레 : " << c1.getPerimeter() << endl;
	cout << "c1.contains(3,3) : " << (c1.Contains(3, 3) ? "TRUE" : "FALSE") << endl;
	cout << "c1.contains(c2) : " << (c1.Contains(c2) ? "TRUE" : "FALSE") << endl;
	cout << "c1.overlaps(c3) : " << (c1.Overlaps(c3) ? "TRUE" : "FALSE") << endl;
}

// 다음을 포함하는 Rectangle2D 클래스를 정의하라.
// - 직사각형의 중심을 나타내는 x,y 두 개의 double
//	이에 대한 get 상수 함수와 set 함수, 사각형의 변은 x축과 y축에 평행인 것으로 가정.
// - double 데이터 필드 width, height 와 이에 대한 get, set
// - x,y = 0,0 width, height = 1,1인 기본 생성
// - 지정해서 생성하는 생성자
// - getArea() 넓이
// - getPerimeter() 둘레
// - 점이 직사각형 내부에 있을 경우 true (contains(x,y)) const
// - 사각형이 내부에 있을 경우 true(contains(Rectangle2D)) const
// - 지정된 직사각형이 생성된 직사각형과 중첩 true (overlaps(Rectangle2D)) const
// 
// 예제 입력 r1(2,2,5.5,4.9), r2(4,5,10.5,3.2), r3(3,5,2.3,5.4)
// r1 면적, 둘레 출력
// r1.contains(3,3)
// r1.contains(r2)
// r1.overlaps(r3)
//

void Question2()
{
	CRectangle2D r1(0, 4, 4, 2);
	CRectangle2D r2(0, 1, 2, 4);
	CRectangle2D r3(2, 0, 2, 2);

	
	cout << "r1 면적 : " << r1.getArea() << endl;
	cout << "r1 둘레 : " << r1.getPerimeter() << endl;

	cout << "r1.contains(3,3) : " << (r1.Contains(3, 3) ? "TRUE" : "FALSE") << endl;
	cout << "r1.contains(r2) : " << (r1.Contains(r2) ? "TRUE" : "FALSE") << endl;
	cout << "r1.overlaps(r3) : " << (r1.Overlaps(r3) ? "TRUE" : "FALSE") << endl;
}

// x 와 y축의 점을 표시하는 MyPoint 클래스를 설계하라
// - 좌표를 나타내는 두 개의 x, y
// - 점 (0,0)을 생성하는 인수 없는 생성자
// - 지정 좌표의 점을 생성하는 생성자
// - x, y get함수 const
// - MyPoint 유형의 한 점에서 다른 점 까지의 거리를 반환하는 Distance
// 
// 예제 (0,0) -> (10, 30.5) 두점 사이의 거리
// 
// 생성된 좌표의 점이 Circle, Rectangle 내부에 있는지 판단하는 constains를 프렌드로 구현
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