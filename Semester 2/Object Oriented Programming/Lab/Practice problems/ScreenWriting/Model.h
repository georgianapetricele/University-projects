#pragma once
#include <QAbstractTableModel>
#include "Service.h"
#include "ScreenWriter.h"


class Model: public QAbstractTableModel
{
private:
	Service& service;
	ScreenWriter writer;
public:
	Model(Service& service) :service{ service } {}
	~Model() {}
	void setWriter(ScreenWriter& writer)
	{
		this->writer = writer;
	}
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	//header
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	//set data
	bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
	//flags
	Qt::ItemFlags flags(const QModelIndex& index) const override;
	void add_idea(string description, string creator,string act);
};

