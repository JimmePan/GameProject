#pragma once

#include "Task.h"
#include "Global.h"

class Board final : public Task
{
public:
	Board() = default;
	~Board() = default;
	bool update() override;
	void draw() const override;
private:
	void drawFrame() const;
	void drawHighScore() const;
	void drawScore() const;
	void drawPlayer() const;
	void drawPower() const;
	void drawGraze() const;
};

