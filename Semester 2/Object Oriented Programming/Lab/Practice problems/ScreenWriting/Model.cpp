#include "Model.h"

int Model::rowCount(const QModelIndex& parent) const
{
	return this->service.getIdeas().size();
}

int Model::columnCount(const QModelIndex& parent) const
{
	return 4;
}

QVariant Model::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int column = index.column();
	Idea idea = this->service.getIdeas()[row];
	if (role == Qt::DisplayRole)
	{
		switch (column)
		{
		case 0:
			return QString::fromStdString(idea.getDescription());
		case 1:
			return QString::fromStdString(idea.getCreator());
		case 2:
			return QString::fromStdString(idea.getAct());
		case 3:
			return QString::fromStdString(idea.getStatus());
		default:
			break;
		}
	}
	return QVariant();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		switch (section)
		{
		case 0:
			return QString("Description");
		case 1:
			return QString("Creator");
		case 2:
			return QString("Act");
		case 3:
			return QString("Status");
		default:
			break;
		}
	}
	return QVariant();
}

bool Model::setData(const QModelIndex& index, const QVariant& value, int role)
{ 
	if (role == Qt::EditRole)
	{
		//set data
		int row = index.row();
		int column = index.column();
		Idea idea = this->service.getIdeas()[row];
		switch (column)
		{
		case 0:
			idea.setDescription(value.toString().toStdString());
			break;
		case 1:
			idea.setCreator(value.toString().toStdString());
			break;
		case 2:
			idea.setAct(value.toString().toStdString());
			break;
		case 3:
			idea.setStatus(value.toString().toStdString());
			break;
		default:
			break;
		}
	
	
			this->service.update_idea_status(idea);
			emit dataChanged(index, index);
			return true;
		
	
	

	}
	return false;
}

Qt::ItemFlags Model::flags(const QModelIndex& index) const
{
	return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void Model::add_idea(string description, string creator, string act)
{
	beginInsertRows(QModelIndex(), this->rowCount(), this->rowCount());
	this->service.addIdea(description, creator, act);
	endInsertRows();
}