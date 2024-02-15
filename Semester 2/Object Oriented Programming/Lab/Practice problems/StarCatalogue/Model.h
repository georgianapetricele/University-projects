#pragma once
#include "Service.h"
#include <QAbstractTableModel>

class Model: public QAbstractTableModel
{
private:
	Service& serv;
	
public:
	bool checked = false;
	string constellation;
	Model(Service& serv) :serv{ serv } {}
	~Model() {}
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	void add_star(string name, string constellation, int RA, int Dec, int diameter);
	vector<Star> getStars() { return serv.getStars(); }
	string get_astronomer_constellation(string name) { return serv.get_astronomer_constellation(name); }


};

