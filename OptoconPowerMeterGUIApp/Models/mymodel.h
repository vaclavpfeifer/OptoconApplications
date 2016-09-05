#ifndef MYMODEL_H
#define MYMODEL_H

#include <QStandardItemModel>

class MyModel : public QStandardItemModel
{
	Q_OBJECT

public:
	MyModel(QObject *parent);
	~MyModel();

private:
	
};

#endif // MYMODEL_H
