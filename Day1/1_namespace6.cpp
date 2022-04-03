// 1_namespace6
#include <stdio.h>

// namespace 
// Audio.h
namespace Audio
{
	void init();
}

// Audio.cpp
#include "Audio.h"
namespace Audio
{
	void init()
	{
		printf("init Audio Module\n");
	}
}
//------------------------
// AudioMixer.h
namespace Audio
{
	void initMixer();
}
// AudioMuxer.cpp
namespace Audio
{
	void initMixer()
	{
	}
}
