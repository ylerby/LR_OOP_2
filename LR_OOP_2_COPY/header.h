using namespace std;

#include<iostream>

extern HPEN WhitePen;
extern HPEN BlackPen;
extern HPEN RedPen;
extern HPEN GreenPen;

const int CarCount = 3;
const int BusCount = 4;

class Location
{
protected:
	int X;
	int Y;

public:
	Location(int InitX, int InitY);
	virtual ~Location();
	int GetX();
	int GetY();
	void SetX(int NewX);
	void SetY(int NewY);
};

class VirtualPoint : public Location
{
protected:
	bool Visible;

public:
	VirtualPoint(int InitX, int InitY);
	virtual ~VirtualPoint();
	bool IsVisible();
	void Drag(int Step);
	void MoveTo(int NewX, int NewY);
	virtual void Show();
	virtual void Hide();
};

class VirtualFigure : public VirtualPoint {
private:
	int Side;

public:
	VirtualFigure(int InitX, int InitY, int InitSide);
	virtual ~VirtualFigure();
	void Show();
	void Hide();
};

class Car : public VirtualPoint
{
protected:
	int carSide;
public:
	Car(int InitX, int InitY, int initCarSide);
	virtual ~Car();
	int GetSide();
	void Show();
	void Hide();
};

class EnemyCar : public Car
{
public:
	EnemyCar(int InitX, int InitY, int carSide);
	virtual ~EnemyCar();
	void Show(void);
	void Hide(void);
};

class EnemyVan : public Car
{
public:
	EnemyVan(int InitX, int InitY, int carSide);
	~EnemyVan();

	void Show();
	void Hide();
};

class FriendCar : public Car
{
public:
	FriendCar(int InitX, int InitY, int carSide);
	virtual ~FriendCar();
	void Show();
};

class Bus : public VirtualFigure
{
protected:
	int Side;

public:
	Bus(int InitX, int InitY, int side);
	virtual ~Bus();
	void Show();
	int GetSide();
};

class BusWithBonnet : public Bus
{
public:
	BusWithBonnet(int InitX, int InitY, int side);
	virtual ~BusWithBonnet();
	void Show();
	void Hide();
};

class BusWithRoof : public Bus
{
public:
	BusWithRoof(int InitX, int InitY, int side);
	virtual ~BusWithRoof();
	void Show();
	void Hide();
};

class BusWithRoofAndBonnet : public Bus
{
public:
	BusWithRoofAndBonnet(int InitX, int InitY, int side);
	virtual ~BusWithRoofAndBonnet();
	void Show();
	void Hide();
};