void creerMapRandom(Jeu jeu[33][33], Objet robots[4], Parametres *ParametresDuJeu);

void placeMursRandoms(Jeu jeu[33][33], int nombreDeMurs);

void placeObjetsRandoms(Jeu jeu[33][33], Objet robots[4]);

int testMap(Jeu jeu[33][33], Objet robots[4], Parametres *ParametresDuJeu);

void deplacementDroiteRand(Jeu jeu[33][33], Objet *robot, Parametres *ParametresDuJeu);

void deplacementGaucheRand(Jeu jeu[33][33], Objet *robot, Parametres *ParametresDuJeu);

void deplacementHautRand(Jeu jeu[33][33], Objet *robot, Parametres *ParametresDuJeu);

void deplacementBasRand(Jeu jeu[33][33], Objet *robot, Parametres *ParametresDuJeu);
