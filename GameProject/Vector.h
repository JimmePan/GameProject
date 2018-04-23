#pragma once
class Vector
{
public:
	Vector();
	~Vector();
	float x;
	float y;

	float getX() { return x; }
	float getY() { return y; }

	// �û����캯��
	Vector(float posX, float posY);
	void absV();
	//ʸ���ӷ�
	Vector operator+(Vector v);
	//ʸ������
	Vector operator-(Vector v);
	//����
	Vector operator*(float n);
	//����
	Vector operator/(float n);
	//�������
	float dotMul(Vector v2);
	//�������
	float crossMul(Vector v2);
	//��ȡʸ������
	float getLength();
	//������λ��
	void Normalize();
};

