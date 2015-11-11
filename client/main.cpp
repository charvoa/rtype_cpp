#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    // Fenêtre de rendu
    RenderWindow app(VideoMode(600, 600, 32), "Mon superbe polygone SFML !");

    // Shape carre;
    // carre.addPoint(200, 200, Color(255, 255, 0), Color(255,255,255));
    // carre.addPoint(400, 200, Color(255, 255, 0), Color(255,0,0));
    // carre.addPoint(400, 400, Color(0, 255, 255), Color(0,255,0));
    // carre.addPoint(200, 400, Color(0, 255, 255), Color(0,0,255));
    // carre.enableFill(true); // Remplissage activé
    // carre.enableOutline(true); // Bordures activées
    // carre.setOutlineWidth(20); // Bordures de taille 20 pixels

    // Boucle principale
    while (app.isOpen())
    {
        Event event;
        while (app.waitEvent(event))
        {
            // Fenêtre fermée : on quitte
            if (event.type == Event::Closed)
                app.close();
        }

        // Efface l'écran (remplissage avec du noir)
        app.clear();

        // Affichage de notre carre dans la fenêtre

        // Affichage du contenu de la fenêtre à l'écran
        app.display();

    }

    return EXIT_SUCCESS;
}
