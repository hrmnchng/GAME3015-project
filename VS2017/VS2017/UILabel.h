#ifndef UI_OBJECT_H
#define UI_OBJECT_H

#include "CombustionEngine.h"
#include "GameObject.h"

class UILabel : public GameObject{

public:

	sf::Text label;

	UILabel(const char*);
	~UILabel();

	void Draw(sf::RenderTarget& target) const;
};
#endif