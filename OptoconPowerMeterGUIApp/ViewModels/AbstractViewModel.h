#ifndef ABSTRACT_VIEW_MODEL_H
#define ABSTRACT_VIEW_MODEL_H

//#include "Views\OptoconAbstractView.hpp"
#include "qobject.h"

enum WaveLengthEnum
{
	WAVELENGTH_850,
	WAVELENGTH_1300,
	WAVELENGTH_1310,
	WAVELENGTH_1500,
	WAVELENGTH_OFF
};

class AbstractViewModel : public QObject
{
	Q_OBJECT

public:
	AbstractViewModel();
	virtual ~AbstractViewModel();

	// Testing method
	virtual void ViewAll() = 0;

	virtual void setActiveWaveLength(WaveLengthEnum newWaveLength)
	{
		ActiveWaveLength = newWaveLength;
		emit waveLengthChanged(newWaveLength);
	}



signals:
	void waveLengthChanged(WaveLengthEnum newWL);

	// static void waveLengthChangedStatic(WaveLengthEnum newWL);

	// Internal attributes
protected:
	WaveLengthEnum ActiveWaveLength = WaveLengthEnum::WAVELENGTH_850;

};

#endif
