#include "Number.h"
#include <DxLib.h>
#include "Image.h"

const int D = 10;
const int d = 5;

Number::Number()
{
}

Number::Number(float number, int x, int y, int digit, int decimal) :
	_number(number),
	_x(x),
	_y(y),
	_digit(digit),
	_decimal(decimal)
{
}

Number::~Number()
{
}

void Number::draw()
{
	int digit, decimal = 0;
	digit = (int)_number;
	if (_decimal > 0) {
		decimal = (int)((_number - digit)*pow(10, _decimal));
	}

	for (int i = _digit; i > 0; i--) {
		DrawGraph(_x + (i - 1) * 26, _y, Image::getIns()->getBigNumber()[digit % 10], true);
		digit /= 10;
	}
	if (_decimal > 0) {
		DrawGraph(_x + (_digit) * 28 - 6, _y, Image::getIns()->getBigNumber()[11], true);
		for (int i = _decimal; i > 0; i--) {
			DrawRotaGraph(_x + (_digit) * 26 + i * 20 + 5, _y + 20, 0.75, 0.0, Image::getIns()->getBigNumber()[decimal % 10], true);
			decimal /= 10;
		}
	}
}
