#pragma once
#include "Button.hpp"
#include <functional>
#include <string>

/**
 * @brief Class for default popup menu buttons.
 *
 */
class PopupMenuButton : public Button {
private:
    sf::RectangleShape m_background;
    const sf::Font& m_font;
    sf::Text m_text;
    std::function<void()> m_onClick;

public:
    /**
     * @brief Construct a new PopupMenuButton object.
     *
     * @param text_to_display Text to display in the button.
     * @param new_font A reference to the font to use on the button. If the font is destroyed before the button, a dangling reference is generated.
     * @param new_on_click Function to run when the button is clicked.
     */
    PopupMenuButton(const std::string& textToDisplay, const sf::Font& newFont, const std::function<void()>& newOnClick);

    /**
     * @brief Draws the object to a RenderTarget.
     *
     * @param target RenderTarget to draw the object.
     * @param states The states in which the object should be drawn.
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    /**
     * @brief Processes an event and changes the PopupMenuButton accordingly.
     *
     * @param event Event to process.
     */
    void processEvent(sf::Event event) override;

    sf::Vector2u getSize() const override;
};