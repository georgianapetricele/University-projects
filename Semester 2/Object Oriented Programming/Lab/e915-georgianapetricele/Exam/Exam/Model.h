#pragma once
#include <QAbstractTableModel>
#include "Service.h"


class Model: public QAbstractTableModel
{
private:
	Service& service;
public:
	Model (Service& service) : service{ service } {}
	~Model();
	vector<Researcher> get_researchers()
	{
		return service.get_researchers();
	}
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

	bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
	Qt::ItemFlags flags(const QModelIndex& index) const override;

	void add_idea(string title, string description, string status, string creator, int duration);
	vector<Idea> get_ideas()
	{
		return service.get_ideas();
	}

	void load_ideas_to_file()
	{
		service.load_ideas_to_file();
	}

	bool has_accepted_idea(Researcher researcher)
	{
		return service.has_accepted_ideas(researcher);
	}

	vector<Idea> get_ideas_for_researcher(string name)
	{
		return service.get_ideas_for_researcher(name);
	}

	void update_ideas_description(string title, string description)
	{
		service.update_ideas_description(title, description);
	}
};

