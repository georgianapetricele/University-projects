#pragma once
#include "Repo.h"

class CSVRepository : public Repository
{
public:
	CSVRepository();
	~CSVRepository();
	void write_to_file() override;
	void open_in_given_app() override;
};