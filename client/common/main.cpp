//
// main.cpp for rtype in /home/nicolas/rendu/rtype_cpp/client
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Dec  1 11:41:24 2015 Nicolas Girardot
// Last update Wed Dec  2 06:05:39 2015 Serge Heitzler
//

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "RenderWindow.hh"
#include "Texture.hh"
#include "Sprite.hh"

int main()
{
    // Fenêtre de rendu
	RenderWindow *window = RenderWindow::getInstance();
	window->setWindow(sf::VideoMode(1920, 1080, 32), "R-Pint");

  Texture backgroundSpaceTexture;
  backgroundSpaceTexture.loadFromFile("../../common/res/sprites/background.jpg");

  Sprite backgroundSpace;

  // Efface l'écran (remplissage avec du noir)
  window->clear();

  window->draw(backgroundSpace.getSprite());

  // Affichage du contenu de la fenêtre à l'écran
  window->display();
  // Boucle principale
  while (window->isOpen())
    {
      sf::Event event;
        while (window->waitEvent(event))
	  {
	  }
    }
    return EXIT_SUCCESS;
}



/*
            // Fenêtre fermée : on quitte
            if (event.type == sf::Event::Closed)
              window.close();
            if (event.type == sf::Event::KeyPressed) // KEYBOARD PRESSED
	      {
		std::cout << event.key.code << std::endl;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		  window.close();
	      }
	    if (event.type == sf::Event::JoystickButtonPressed) // JOYSTICK BUTTON PRESSED
	      {
		std::cout << "joystick button pressed!" << std::endl;
		std::cout << "button: " << event.joystickButton.button << std::endl;
	      }
	    if (event.type == sf::Event::MouseButtonPressed)
	      {
		if (event.mouseButton.button == sf::Mouse::Left) // CLIQUE SOURIS GAUCHE
		  {
		    std::cout << "the left button was pressed" << std::endl;
		    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
		    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
		  }
	      }
	    if (event.type == sf::Event::MouseMoved) // MOUVEMENT DE LA SOURIS
	      {
		std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
		std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
	      }
	    if (event.type == sf::Event::JoystickMoved) // JOYSTICK MOVED
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
            if (event.type == sf::Event::KeyPressed)
	      {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		  window.close();
	      }

 */
