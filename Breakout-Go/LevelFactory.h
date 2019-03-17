#ifndef _LEVEL_FACTORY_
#define _LEVEL_FACTORY_

#include "Block.h"
#include "Device.h"
#include "Level.h"

class LevelFactory {
private:
	Device* device;
public:
	LevelFactory(Device* d);
	~LevelFactory();

	Level* buildLevel(const int number) const;
};

#endif
