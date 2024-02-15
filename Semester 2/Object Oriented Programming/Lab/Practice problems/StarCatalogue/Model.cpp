#include "Model.h"

int Model::rowCount(const QModelIndex& parent) const
{
	return this->serv.getStars().size();
}

int Model::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant Model::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int col = index.column();
	
	Star star = this->serv.getStars()[row];
	if (role == Qt::DisplayRole)
	{
		switch (col)
		{
		case 0:
			return QString::fromStdString(star.getName());
		case 1:
			return QString::fromStdString(star.getConstellation());
		case 2:
			return QString::fromStdString(to_string(star.getRA()));
		case 3:
			return QString::fromStdString(to_string(star.getDec()));
		case 4:
			return QString::fromStdString(to_string(star.getDiameter()));
		default:
			break;
		}
	}
	return QVariant();
}

void Model::add_star(string name, string constellation, int RA, int Dec, int diameter)
{
	beginInsertRows(QModelIndex(), 0, 0);
	this->serv.add_star(name, constellation, RA, Dec, diameter);
	endInsertRows();
}