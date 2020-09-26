#pragma once

#include "AbstractGO.h";

class Shot : public AbstractGO
{
public:
	Shot();
	void update(float s) override;
	virtual void hit(const GameObject& other);
	bool finished() const override;
};

