#include "LevelFactory.h"

LevelFactory::LevelFactory(Device* d) :device{ d } {
}

LevelFactory::~LevelFactory() {
}

Level* LevelFactory::buildLevel(const int number) const {
	Level* result = new Level(device, number);
	for (int i = 0; i < 15; i++) {
		Block block{ 10 + i * 20, 30, 20, 10, 0xFFE0, 1, 10 };
		result->addBlock(block);
	}
	return result;
}
