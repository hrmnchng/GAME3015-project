#include "AudioEmitterComponent.h"

AudioEmitterComponent::AudioEmitterComponent(const char * audioName, bool loop, bool isSfx, bool autoPlay)
{
	assetName = audioName;

	if (isSfx)
	{
		if (buffer.loadFromFile(audioName))
		{
			sound.setBuffer(buffer);
			sound.setLoop(loop);
			if (autoPlay) sound.play();
		}
	}
	else
	{
		if (music.openFromFile(audioName))
		{
			music.setLoop(loop);
			if (autoPlay) music.play();
		}
	}
}

AudioEmitterComponent::~AudioEmitterComponent()
{
}

void AudioEmitterComponent::Update(float)
{
}

void AudioEmitterComponent::Draw(sf::RenderTarget &)
{
}
