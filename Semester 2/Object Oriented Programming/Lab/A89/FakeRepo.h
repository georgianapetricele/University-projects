#pragma once
#include "Repo.h"

class FakeRepo: public Repository
{
private:
	int index;
public:
	FakeRepo(int index);
	int add_tutorial(const Tutorial& current_tutorial) override;
	int find_tutorial(Tutorial given_tutorial) override;
};