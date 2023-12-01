#pragma once
#include "Repo.h"

class HTMLRepository : public Repository
{
public:
	HTMLRepository();
	~HTMLRepository();
	void write_to_file() override;

	void open_in_given_app() override;
};