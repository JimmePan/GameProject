#include "Board.h"
#include "Define.h"
#include <DxLib.h>
#include "Image.h"
#include "Number.h"

bool Board::update()
{
	return true;
}

void Board::draw() const
{
	drawFrame();
	drawHighScore();
	drawScore();
	drawPlayer();
	drawPower();
	drawGraze();
}

void Board::drawFrame() const
{
	int color = GetColor(0, 64, 128);
	const int x = Define::IN_X;
	const int y = Define::IN_Y;
	const int w = Define::IN_W;
	const int h = Define::IN_H;
	/*功臣深退的四条线*/
	//DrawLine(x, y, x + w, y, color, 0.5f);
	//DrawLine(x, y, x, y + h, color, 0.5f);
	//DrawLine(x + w, y, x + w, y + h, color, 0.5f);
	//DrawLine(x, y + h, x + w, y + h, color, 0.5f);
	DrawExtendGraph(0, 0, x, Define::WIN_H, Image::getIns()->getFront01(), TRUE);
	DrawExtendGraph(x, y + h + 3, x + w, Define::WIN_H + 3, Image::getIns()->getFront02(), TRUE);		//美观需求+3
	DrawExtendGraph(x, 0, x + w, y, Image::getIns()->getFront03(), TRUE);
	DrawExtendGraph(x + w, 0, Define::WIN_W, Define::WIN_H, Image::getIns()->getFront00(), TRUE);
}

void Board::drawHighScore() const
{
	Number((float)Global::getIns()->getHighScore(), 1024, 96, 9, 0).draw();
}

void Board::drawScore() const
{
	Number((float)Global::SCORE, 1024, 144, 9, 0).draw();
}

void Board::drawPlayer() const
{
	//Number(Global::PLAYER, 1030, 212, 2, 2).draw();
	int pl = (int)Global::PLAYER;
	float pl_piece = Global::PLAYER - pl;
	for (int i = 0; i < pl; i++) {
		DrawGraph(1024 + i * 28, 212, Image::getIns()->getPlayerHp()[5], TRUE);
	}
	if (pl_piece > 0.1)
		DrawGraph(1024 + pl * 28, 212, Image::getIns()->getPlayerHp()[(int)(pl_piece / 0.2f)], TRUE);

}

void Board::drawPower() const
{
	Number(Global::POWER+0.001f, 1024, 262, 1, 2).draw();
	DrawGraph(1104, 262, Image::getIns()->getBigNumber()[10], TRUE);
	Number(4.00f, 1130, 262, 1, 2).draw();
}

void Board::drawGraze() const
{
	Number((float)Global::GRAZE, 1024, 312, (int)log10(Global::GRAZE > 0 ? Global::GRAZE : 1) + 1, 0).draw();
}
