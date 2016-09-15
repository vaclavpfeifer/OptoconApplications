#ifndef ABSTRACT_VIEW_MODEL_H
#define ABSTRACT_VIEW_MODEL_H

//#include "Views\OptoconAbstractView.hpp"
#include "qobject.h"
// #include "CommonOptoconSignals.h"
#include "CommonDeclarations.h"

// TODO: this enum should be moved to some specific classes consts/enums??
//enum WaveLengthEnum
//{
//	WAVELENGTH_850,
//	WAVELENGTH_1300,
//	WAVELENGTH_1310,
//	WAVELENGTH_1500,
//	WAVELENGTH_OFF
//};

class AbstractViewModel : public QObject
{
	Q_OBJECT

public:
	AbstractViewModel();
	virtual ~AbstractViewModel();

	// Testing method
	virtual void ViewAll() = 0;

	virtual void setActiveWaveLength(WaveLengthEnum newWaveLength, bool shouldEmit = true)
	{
		ActiveWaveLength = newWaveLength;
		if(shouldEmit)
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
