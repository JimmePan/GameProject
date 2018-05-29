#include "Boss.h"
#include "BossHp.h"
class TataraKogasa :
	public Boss
{
public:
	TataraKogasa(float x, float y, int type, int hp, int movePatternID, int shotPatternID, int itemPatternID);
	~TataraKogasa() = default;
	void draw() const override;

protected:
	void reset() override;
	void changeMove() override;
	void setSize() override;

	mutable int _shotCount;
	int _shotImg[6] = { 6,7,9,10,12,13 };
	void shotImage() const;

private:
	BossHp bossHp;
};
