#include "mymodel.h"

MyModel::MyModel(QObject *parent) : QStandardItemModel(parent)
{
	this->setItem(0, new QStandardItem("Items1"));
	this->setItem(1, new QStandardItem("Items2"));
	this->setItem(2, new QStandardItem("Items3"));
}

MyModel::~MyModel()
{

}
