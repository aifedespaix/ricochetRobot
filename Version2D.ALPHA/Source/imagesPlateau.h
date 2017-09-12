void placeRobot(Objet *image, SDL_Surface *screen, Composantes *composantes, int x, int y);

void placeImage(Objet *image, SDL_Surface *screen);

void releaseImage(Objet image);

void placeMurs(SDL_Surface *screen, Jeu jeu[33][33]);

void afficherJeu(SDL_Surface *screen, Composantes *composantes, Jeu jeu[33][33]);

void afficherEdition(SDL_Surface *screen, Composantes *composantes, Jeu jeu[33][33]);

void remplaceRobot(Objet *robot, SDL_Surface *screen, Jeu jeu[33][33]);
