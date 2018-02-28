#pragma once

#include <list>
#include <memory>
#include <array>
#include "Surface.h"
#include "AbstractBackground.h"

class Background01 final : public AbstractBackground
{

public:
    Background01();
    ~Background01() = default;
    bool update() override;
    void draw() const override;

	mutable float a = 0.f;
	mutable float b = 0.f;
	mutable float c = 0.f;


private:
    void draw(VECTOR offset) const;

    std::list<std::shared_ptr<Surface>> _list;
    std::array<int, Surface::DATANUM> _handle;

};

