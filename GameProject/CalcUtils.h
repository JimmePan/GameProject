#pragma once
class CalcUtils
{
public:
	CalcUtils() = delete;

	static float roundPoint(float val, int point);
	static float roundSize(float max, float min, int count);

	template<typename T1, typename T2>
	static bool out_judge_shot(T1 i, T2 s);
};

template<typename T1, typename T2>
inline bool CalcUtils::out_judge_shot(T1 i, T2 s)
{
	{
		int j;
		if ((*i)->getCount() > 0) { //�ӵ��Ѿ���������Ѿ������켣
			float x = (*i)->getX() - (*s)->getX();		//���˺��Ի��ӵ�����
			float y = (*i)->getY() - (*s)->getY();

			float r = (*i)->getRange() + (*s)->getRange();	//���˵���ײ�ж����Ի�������ӵ�����ײ�ж��ĺϼƷ�Χ

			if ((*i)->getSpeed() > r) {		//�뾶С���ٶȣ�����켣
											//1֡ǰ��λ��
				float pre_x = (*i)->getX() + cos((*i)->getAngle() + Define::PI)*(*i)->getSpeed();
				float pre_y = (*i)->getY() + sin((*i)->getAngle() + Define::PI)*(*i)->getSpeed();
				float px, py;
				for (j = 0; j < (*i)->getSpeed() / r; j++) {			//ǰ���ķ���/��ײ�ж�������ѭ��
					px = pre_x - (*s)->getX();
					py = pre_y - (*s)->getY();
					if (px*px + py * py < r*r)
						return true;
					pre_x += cos((*i)->getAngle())*r;
					pre_y += sin((*i)->getAngle())*r;
				}
			}
			if (x*x + y * y < r*r)//�������ײ�ж���Χ��
				return true;//��ײ
		}
		return false;
	}
}
