#ifndef AUDIO_EMITTER_H
#define AUDIO_EMITTER_H

#include "Component.h"
#include <SFML/Audio.hpp>
class AudioEmitterComponent : public Component {

public:
	sf::Music music;
	sf::Sound sound;
	sf::SoundBuffer buffer;
	const char* assetName;

	AudioEmitterComponent(const char * audioName, bool loop, bool isSfx, bool autoPlay);
	~AudioEmitterComponent();

	void Update(float);
	void Draw(sf::RenderTarget&);

};
#endif