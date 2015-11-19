#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    // Fenêtre de rendu
    RenderWindow app(VideoMode(900, 900, 32), "Mon superbe polygone SFML !");
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    // Boucle principale
    while (app.isOpen())
    {
      // Efface l'écran (remplissage avec du noir)
      app.clear();

      // Affichage de notre carre dans la fenêtre
      app.draw(shape);

      // Affichage du contenu de la fenêtre à l'écran
      app.display();

        Event event;
        while (app.waitEvent(event))
        {
            // Fenêtre fermée : on quitte
            if (event.type == Event::Closed)
                app.close();
        }



    }

    return EXIT_SUCCESS;
}
