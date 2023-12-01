#include "Model.h"

Model::~Model()
{
}


int Model::rowCount(const QModelIndex& parent) const
{
	return this->service.get_ideas().size();
}

int Model::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant Model::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int column = index.column();
	Idea idea = this->service.get_ideas()[row];
	if (role == Qt::DisplayRole)
	{
		switch (column)
		{
		case 0:
			return QString::fromStdString(idea.get_title());
		case 1:
			return QString::fromStdString(idea.get_description());
		case 2: 
			return QString::fromStdString(idea.get_status());
		case 3:
			return QString::fromStdString(idea.get_creator());
		case 4:
			return QString::fromStdString(to_string(idea.get_duration()));
		}
	}
	return QVariant();
}

bool Model::setData(const QModelIndex& index, const QVariant& value, int role)
{
	if (role == Qt::EditRole)
	{
		int row = index.row();
		int column = index.column();
		Idea idea = this->service.get_ideas()[row];
		switch (column)
		{
		case 0:
			idea.set_title(value.toString().toStdString());
			break;
		case 1:
			idea.set_description(value.toString().toStdString());
			break;
		case 2:
			idea.set_status(value.toString().toStdString());
			break;
		case 3:
			idea.set_creator(value.toString().toStdString());
			break;
		case 4:
			idea.set_duration(value.toInt());
			break;
		}
		this->service.update_idea(idea);
		emit dataChanged(index, index);
		return true;
	}
	return false;
}

Qt::ItemFlags Model::flags(const QModelIndex& index) const
{
	return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		switch (section)
		{
			case 0:
			return QString("Title");
			case 1:
				return QString("Description");
				case 2:
					return QString("Status");
					case 3:
						return QString("Creator");
						case 4:
							return QString("Duration");
		}
	}
	return QVariant();
}

void Model::add_idea(string title, string description, string status, string creator, int duration)
{
	beginInsertRows(QModelIndex(), this->rowCount(), this->rowCount());
	this->service.add_idea(title, description, status, creator, duration);
	endInsertRows();
}