#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    // Fenêtre de rendu
    RenderWindow window(VideoMode(1920, 1080, 32), "R-Pint", Style::Fullscreen);

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
            if (event.type == Event::KeyPressed)
            {
              if (Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
            }
        }





    }

    return EXIT_SUCCESS;
}
