#include "UILabel.h"

UILabel::UILabel(const char* text)
{
	// Default font
	label.setFont(CombustionEngine::CENGINE().m_engineFonts.at("pricedown"));
	label.setString(text);
	label.setFillColor(sf::Color::Yellow);
	label.setPosition(0.0f, 0.0f);
	label.setCharacterSize(42);
}

UILabel::~UILabel()
{
}

void UILabel::Draw(sf::RenderTarget & target) const
{
	GameObject::Draw(target);
	target.draw(label);
}
