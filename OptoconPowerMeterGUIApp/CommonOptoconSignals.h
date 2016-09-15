#ifndef COMMON_OPTOCON_SIGNALS_H
#define COMMON_OPTOCON_SIGNALS_H

#include "qobject.h"
// #include "ViewModels\AbstractViewModel.h" 
#include "CommonDeclarations.h"


class CommonOptoconSignals : public QObject
{
	Q_OBJECT

public:
	CommonOptoconSignals();
	virtual ~CommonOptoconSignals();

signals:
	void waveLengthChanged(WaveLengthEnum newWL);



};

#endif
