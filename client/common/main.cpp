#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    // Fenêtre de rendu
  RenderWindow window(VideoMode(1920, 1080, 32), "R-Pint");//, Style::Fullscreen);
  
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
      Event event;
        while (window.waitEvent(event))
	  {
            // Fenêtre fermée : on quitte
            if (event.type == Event::Closed)
              window.close();
            if (event.type == Event::KeyPressed) /* KEYBOARD PRESSED */
	      {
		std::cout << event.key.code << std::endl;
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		  window.close();
	      }
	    if (event.type == sf::Event::JoystickButtonPressed) /* JOYSTICK BUTTON PRESSED */
	      {
		std::cout << "joystick button pressed!" << std::endl;
		std::cout << "button: " << event.joystickButton.button << std::endl;
	      }
	    if (event.type == sf::Event::MouseButtonPressed)
	      {
		if (event.mouseButton.button == sf::Mouse::Left) /* CLIQUE SOURIS GAUCHE */
		  {
		    std::cout << "the left button was pressed" << std::endl;
		    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
		    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
		  }
	      }
	    if (event.type == sf::Event::MouseMoved) /* MOUVEMENT DE LA SOURIS */
	      {
		std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
		std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
	      }
	    if (event.type == sf::Event::JoystickMoved) /* JOYSTICK MOVED */
	      {
		if (event.joystickMove.axis == sf::Joystick::X)
		  {
		    std::cout << "X axis moved!" << std::endl;
		    std::cout << "new position: " << event.joystickMove.position << std::endl;
		  }
		if (event.joystickMove.axis == sf::Joystick::Y)
		  {
		    std::cout << "Y axis moved!" << std::endl;
		    std::cout << "new position: " << event.joystickMove.position << std::endl;
		  }
		if (event.joystickMove.axis == sf::Joystick::Z)
		  {
		    std::cout << "Z axis moved!" << std::endl;
		    std::cout << "new position: " << event.joystickMove.position << std::endl;
		  }
		if (event.joystickMove.axis == sf::Joystick::R)
		  {
		    std::cout << "R axis moved!" << std::endl;
		    std::cout << "new position: " << event.joystickMove.position << std::endl;
		  }
	      }
	  }
    }
    return EXIT_SUCCESS;
}
