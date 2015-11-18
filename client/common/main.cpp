#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "RenderWindow.hh"


int main()
{
    // Fenêtre de rendu
  RenderWindow window(sf::VideoMode(1920, 1080, 32), "R-Pint", sf::Style::Fullscreen);

  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  // Efface l'écran (remplissage avec du noir)
  window.clear();

  window.draw(shape);

  // Affichage du contenu de la fenêtre à l'écran
  window.display();
  // Boucle principale
  while (window.isOpen())
    {
      sf::Event event;
        while (window.waitEvent(event))
	  {
            // Fenêtre fermée : on quitte
            if (event.type == sf::Event::Closed)
              window.close();
            if (event.type == sf::Event::KeyPressed)
	      {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		  window.close();
	      }
            if (sf::Joystick::isButtonPressed(0,1))
              std::cout << "Button on XBOX controller is pressed" << std::endl;
	  }
    }
    return EXIT_SUCCESS;
}
