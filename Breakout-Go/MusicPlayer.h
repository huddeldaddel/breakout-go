#ifndef _MUSIC_PLAYER_
#define _MUSIC_PLAYER_

#include "Device.h"

class MusicPlayer {
private:
	Device* device;
public:	
	MusicPlayer(Device* device);
	~MusicPlayer();

	void playGameOver() const;
	void playGameStart() const;
};

#endif
