#include "Bibliotheque.h"

#include "iostream"
#include <fstream>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <vector>
using namespace std;


//*********************************Cressource*********************************//


//Constructeurs

Cressource::Cressource(ifstream& Lfichier, string Lbuff){
    from_file(Lfichier,Lbuff);
}

Cressource::Cressource(string titre,string auteur,date date_de_sortie,int ID){
    _titre = titre;
    _auteur = auteur;
    _date_de_sortie.jour = date_de_sortie.jour;
    _date_de_sortie.mois = date_de_sortie.mois;
    _date_de_sortie.annee = date_de_sortie.annee;
    _type = RESSOURCE;
    _ID = ID;
    _locataire = "";
    _periode_emprunt.debut.jour  = 0;
    _periode_emprunt.debut.mois  = 0;
    _periode_emprunt.debut.annee = 0;
    _periode_emprunt.fin.jour  = 0;
    _periode_emprunt.fin.mois  = 0;
    _periode_emprunt.fin.annee = 0;
}

Cressource::Cressource(){
}

//Destructeurs
Cressource::~Cressource(){
};

//METHODES
void Cressource::affichage() {
    cout << "Titre : " << _titre << endl;
    cout << "Auteur : " << _auteur << endl;
    cout << "Date De Sortie : " << _date_de_sortie.jour << "/" << _date_de_sortie.mois << "/" <<_date_de_sortie.annee << endl;
    switch ( _type )
    {
        case LIVRE:
            cout << "Type : Livre" << endl;
            break;
        case REVUE:
            cout << "Type : Revue" << endl;
            break;
        case CD:
            cout << "Type : CD" << endl;
            break;
        case VHS:
            cout << "Type : VHS" << endl;
            break;
        case DVD:
            cout << "Type : DVD" << endl;
            break;
        case RESSOURCE:
            cout << "Type : RESSOURCE" << endl;
            break;
    }
    cout << "Identifiant : " << _ID << endl;
    cout << "Locataire : " << _locataire << endl;
    if (_locataire.compare("") == 0){
        cout << "Ressource disponible" << endl;
    }
    else{
        cout << "Periode d'emprunt : " << _periode_emprunt.debut.jour << "/" << _periode_emprunt.debut.mois << "/" << _periode_emprunt.debut.annee << " - " << _periode_emprunt.fin.jour << "/" << _periode_emprunt.fin.mois << "/" << _periode_emprunt.fin.annee << endl;
    }
}

string Cressource::get_titre(){
    return _titre;
}

string Cressource::get_auteur(){
    return _auteur;
}

date Cressource::get_date_de_sortie(){
    return _date_de_sortie;
}

TYPE Cressource::get_type(){
    return _type;
}

int Cressource::get_ID(){
    return _ID;
}

string Cressource::get_locataire(){
    return _locataire;
}

periode Cressource::get_periode_emprunt(){
    return _periode_emprunt;
}

void  Cressource::emprunt(string locataire, periode periode_emprunt){
    _locataire = locataire;
    _periode_emprunt.debut.jour  = periode_emprunt.debut.jour;
    _periode_emprunt.debut.mois  = periode_emprunt.debut.mois;
    _periode_emprunt.debut.annee = periode_emprunt.debut.annee;
    _periode_emprunt.fin.jour    = periode_emprunt.fin.jour;
    _periode_emprunt.fin.mois    = periode_emprunt.fin.mois;
    _periode_emprunt.fin.annee   = periode_emprunt.fin.annee;
}

void Cressource::remise() {
    _locataire = "";
    _periode_emprunt.debut.jour  = 0;
    _periode_emprunt.debut.mois  = 0;
    _periode_emprunt.debut.annee = 0;
    _periode_emprunt.fin.jour    = 0;
    _periode_emprunt.fin.mois    = 0;
    _periode_emprunt.fin.annee   = 0;
}

void Cressource::from_file(ifstream& Lfichier, string Lbuff){
    //cout << "entree dans la fonction from file de Cressource" << endl;
    getline(Lfichier, Lbuff);
    _titre = Lbuff;
    getline(Lfichier, Lbuff);
    //cout << _titre << endl;
    _auteur = Lbuff;

    //récupération de la date de sortie
    getline(Lfichier, Lbuff);
    _date_de_sortie.jour = stoi(Lbuff);
    getline(Lfichier, Lbuff);
    _date_de_sortie.mois = stoi(Lbuff);
    getline(Lfichier, Lbuff);
    _date_de_sortie.annee = stoi(Lbuff);

    getline(Lfichier, Lbuff);
    _ID = stoi(Lbuff);
    //cout << _ID << endl;
    getline(Lfichier, Lbuff);
    _locataire = Lbuff;
    //cout << _locataire << endl;

    //récupération de la période d'emprunt
    getline(Lfichier, Lbuff);
    _periode_emprunt.debut.jour = stoi(Lbuff);
    getline(Lfichier, Lbuff);
    _periode_emprunt.debut.mois = stoi(Lbuff);
    getline(Lfichier, Lbuff);
    _periode_emprunt.debut.annee = stoi(Lbuff);
    getline(Lfichier, Lbuff);
    _periode_emprunt.fin.jour = stoi(Lbuff);
    getline(Lfichier, Lbuff);
    _periode_emprunt.fin.mois = stoi(Lbuff);
    getline(Lfichier, Lbuff);
    _periode_emprunt.fin.annee = stoi(Lbuff);
    //cout << _periode_emprunt.debut.annee << endl;
}

//*********************************Clivre*********************************//

//Constructeur
Clivre::Clivre(ifstream& Lfichier, string Lbuff){
    from_file(Lfichier,Lbuff);
}

Clivre::Clivre(){
}

Clivre::Clivre(string titre, string auteur, date date_de_sortie,int ID,
               int nbr_page, string collection, string resume){

    _titre = titre;
    _auteur = auteur;
    _date_de_sortie.jour = date_de_sortie.jour;
    _date_de_sortie.mois = date_de_sortie.mois;
    _date_de_sortie.annee = date_de_sortie.annee;
    _type = LIVRE;
    _ID = ID;
    _locataire = "";
    _periode_emprunt.debut.jour  = 0;
    _periode_emprunt.debut.mois  = 0;
    _periode_emprunt.debut.annee = 0;
    _periode_emprunt.fin.jour  = 0;
    _periode_emprunt.fin.mois  = 0;
    _periode_emprunt.fin.annee = 0;
    _nbr_pages  = nbr_page;
    _collection = collection;
    _resume     = resume;
}

//Destructeurs

Clivre::~Clivre(){
};

//Methodes

void Clivre::affichage(){
    //cout << "entree dans affichage ressource" << endl;
    Cressource::affichage();
    cout << "Nombre de pages : " << _nbr_pages << endl;
    cout << "Collection : " << _collection << endl;
    cout << "Résumé : " << _resume << endl;

}

int Clivre::get_nbr_pages(){
    return _nbr_pages;
}

string Clivre::get_collection(){
    return _collection;
}

string Clivre::get_resume(){
    return _resume;
}

void Clivre::from_file(ifstream& Lfichier, string Lbuff) {
    Cressource::from_file(Lfichier, Lbuff);
    //infos livre
    _type = LIVRE;
    getline(Lfichier, Lbuff);
    _nbr_pages = stoi(Lbuff);
    //cout << _nbr_pages << endl;
    getline(Lfichier, Lbuff);
    _collection = Lbuff;
    //cout << _collection << endl;
    getline(Lfichier, Lbuff);
    _resume = Lbuff;
    //cout << _resume << endl;
}

//*********************************Crevue*********************************//

//Constructeur
Crevue::Crevue(){

}

Crevue::Crevue(ifstream& Lfichier, string Lbuff){
    from_file(Lfichier, Lbuff);
}

Crevue::Crevue(string titre,string auteur,date date_de_sortie,int ID,int nbr_page,
               string collection, string resume, string editeur, int nbr_articles, string nom_articles){

    _titre                = titre;
    _auteur               = auteur;
    _date_de_sortie.jour  = date_de_sortie.jour;
    _date_de_sortie.mois  = date_de_sortie.mois;
    _date_de_sortie.annee = date_de_sortie.annee;
    _type                 = LIVRE;
    _ID                   = ID;
    _locataire = "";
    _periode_emprunt.debut.jour  = 0;
    _periode_emprunt.debut.mois  = 0;
    _periode_emprunt.debut.annee = 0;
    _periode_emprunt.fin.jour  = 0;
    _periode_emprunt.fin.mois  = 0;
    _periode_emprunt.fin.annee = 0;
    _nbr_pages            = nbr_page;
    _collection           = collection;
    _resume               = resume;
    _editeur              = editeur;
    _nbr_articles         = nbr_articles;
    _nom_articles         = nom_articles;
}

//Destructeurs

Crevue::~Crevue(){
};

//Methodes

void Crevue::affichage(){
    Cressource::affichage();
    cout << "Editeur : " << _editeur << endl;
    cout << "Nombre d'articles : " << _editeur << endl;
    cout << "Titres des articles : " << _nom_articles << endl;

}

string Crevue::get_editeur(){
    return _editeur;
}

int Crevue::get_nbr_articles(){
    return _nbr_articles;
}

string Crevue::get_nom_articles(){
    return _nom_articles;
}

void Crevue::from_file(ifstream& Lfichier, string Lbuff) {
    Clivre::from_file(Lfichier, Lbuff);
    //infos revue
    _type = REVUE;
    getline(Lfichier, Lbuff);
    _editeur = Lbuff;
    getline(Lfichier, Lbuff);
    _nbr_articles = stoi(Lbuff);
    getline(Lfichier, Lbuff);
    _nom_articles = Lbuff;
}

//*********************************Ccd***************************************//

//Constructeurs
Ccd::Ccd(){

}

Ccd::Ccd(ifstream& Lfichier, string Lbuff){
    from_file(Lfichier, Lbuff);
}

Ccd::Ccd(string titre, string auteur, date date_de_sortie, int ID, int duree, int nbr_pistes,
         string maison_de_production){
    _titre                = titre;
    _auteur               = auteur;
    _date_de_sortie.jour  = date_de_sortie.jour;
    _date_de_sortie.mois  = date_de_sortie.mois;
    _date_de_sortie.annee = date_de_sortie.annee;
    _type                 = LIVRE;
    _ID                   = ID;
    _locataire = "";
    _periode_emprunt.debut.jour  = 0;
    _periode_emprunt.debut.mois  = 0;
    _periode_emprunt.debut.annee = 0;
    _periode_emprunt.fin.jour  = 0;
    _periode_emprunt.fin.mois  = 0;
    _periode_emprunt.fin.annee = 0;
    _duree                = duree;
    _nbr_pistes           = nbr_pistes;
    _maison_de_production = maison_de_production;
}

//Destructeurs
Ccd::~Ccd(){
};

//Methodes

void Ccd::affichage() {
    Cressource::affichage();
    cout << "Durée : " << _duree << endl;
    cout << "Nombre de pistes : " << _nbr_pistes << endl;
    cout << "Maison de production : " << _maison_de_production << endl;
}

int Ccd::get_duree() {
    return _duree;
}

string Ccd::get_maison_de_producton(){
    return _maison_de_production;
}

int Ccd::get_nbr_pistes(){
    return _nbr_pistes;
}

void Ccd::from_file(ifstream& Lfichier, string Lbuff) {
    Cressource::from_file(Lfichier, Lbuff);

    //infos CD
    _type = CD;
    getline(Lfichier, Lbuff);
    _duree = stoi(Lbuff);
    getline(Lfichier, Lbuff);
    _nbr_pistes = stoi(Lbuff);
    getline(Lfichier, Lbuff);
    _maison_de_production = Lbuff;
}

void Ccd::save_to_file(const char *Lnomfichier) {

}

//*********************************Cvhs*********************************//

//Constructeurs
Cvhs::Cvhs(){

}

Cvhs::Cvhs(ifstream& Lfichier, string Lbuff){
    from_file(Lfichier, Lbuff);
}

Cvhs::Cvhs(string titre,string auteur,date date_de_sortie,int ID, int duree, string maison_de_production){
    _titre = titre;
    _auteur = auteur;
    _date_de_sortie.jour = date_de_sortie.jour;
    _date_de_sortie.mois = date_de_sortie.mois;
    _date_de_sortie.annee = date_de_sortie.annee;
    _type = RESSOURCE;
    _ID = ID;
    _locataire = "";
    _periode_emprunt.debut.jour  = 0;
    _periode_emprunt.debut.mois  = 0;
    _periode_emprunt.debut.annee = 0;
    _periode_emprunt.fin.jour  = 0;
    _periode_emprunt.fin.mois  = 0;
    _periode_emprunt.fin.annee = 0;
    _duree = duree;
    _maison_de_production = maison_de_production;
}

//Destructeurs
Cvhs::~Cvhs(){
};

//Methodes

void Cvhs::affichage(){
    Cressource::affichage();
    cout << "Durée : " << _duree << endl;
    cout << "Maison de Production : " << _maison_de_production << endl;
}

int Cvhs::get_duree() {
    return _duree;
}

string Cvhs::get_maison_de_producton(){
    return _maison_de_production;
}

void Cvhs::from_file(ifstream& Lfichier, string Lbuff) {
    Cressource::from_file(Lfichier, Lbuff);
    //infos VHS
    _type = VHS;
    getline(Lfichier, Lbuff);
    _duree = stoi(Lbuff);
    getline(Lfichier, Lbuff);
    _maison_de_production = Lbuff;

}

//*********************************Cdvd*********************************//

//Constructeurs
Cdvd::Cdvd(){

}

Cdvd::Cdvd(ifstream& Lfichier, string Lbuff){
    from_file(Lfichier, Lbuff);
}

Cdvd::Cdvd(string titre,string auteur,date date_de_sortie,int ID, int duree, string maison_de_production,
           int nbr_chapitres){
    _titre = titre;
    _auteur = auteur;
    _date_de_sortie.jour = date_de_sortie.jour;
    _date_de_sortie.mois = date_de_sortie.mois;
    _date_de_sortie.annee = date_de_sortie.annee;
    _type = RESSOURCE;
    _ID = ID;
    _locataire = "";
    _periode_emprunt.debut.jour  = 0;
    _periode_emprunt.debut.mois  = 0;
    _periode_emprunt.debut.annee = 0;
    _periode_emprunt.fin.jour  = 0;
    _periode_emprunt.fin.mois  = 0;
    _periode_emprunt.fin.annee = 0;
    _duree = duree;
    _maison_de_production = maison_de_production;
    _nbr_chapitres = nbr_chapitres;
}

//Destructeurs

Cdvd::~Cdvd(){
};

//Methodes

void Cdvd::affichage(){
    Cressource::affichage();
    cout << "Durée : " << _duree << endl;
    cout << "Maison de Production : " << _maison_de_production << endl;
    cout << "Nombre de Chapitres : " << _nbr_chapitres << endl;
}

int Cdvd::get_duree() {
    return _duree;
}

string Cdvd::get_maison_de_producton(){
    return _maison_de_production;
}

int Cdvd::get_nbr_chapitres(){
    return _nbr_chapitres;
}

void Cdvd::from_file(ifstream& Lfichier, string Lbuff) {
    Cressource::from_file(Lfichier,Lbuff);
    //infos DVD
    _type = DVD;
    getline(Lfichier, Lbuff);
    _duree = stoi(Lbuff);
    getline(Lfichier, Lbuff);
    _maison_de_production = Lbuff;
    getline(Lfichier, Lbuff);
    _nbr_chapitres = stoi(Lbuff);
}

//*********************************Cressource_numerique*********************************//

//Constructeurs
Cressource_numerique::Cressource_numerique(){

}

Cressource_numerique::Cressource_numerique(ifstream& Lfichier, string Lbuff){
    from_file(Lfichier, Lbuff);
}

Cressource_numerique::Cressource_numerique(string titre,string auteur,date date_de_sortie,int ID, int taille, string chemin_acces, string format){
    _titre = titre;
    _auteur = auteur;
    _date_de_sortie.jour = date_de_sortie.jour;
    _date_de_sortie.mois = date_de_sortie.mois;
    _date_de_sortie.annee = date_de_sortie.annee;
    _type = RESSOURCE_NUMERIQUE;
    _ID = ID;
    _locataire = "";
    _periode_emprunt.debut.jour  = 0;
    _periode_emprunt.debut.mois  = 0;
    _periode_emprunt.debut.annee = 0;
    _periode_emprunt.fin.jour  = 0;
    _periode_emprunt.fin.mois  = 0;
    _periode_emprunt.fin.annee = 0;
    _taille = taille;
    _chemin_acces = chemin_acces;
    _format = format;
}

//Destructeurs

Cressource_numerique::~Cressource_numerique(){
};

//Methodes

void Cressource_numerique::affichage(){
    Cressource::affichage();
    cout << "Taille : " << _taille << endl;
    cout << "Chemin d'acces : " << _chemin_acces << endl;
    cout << "Format : " << _format << endl;
}

int Cressource_numerique::get_taille(){
    return _taille;
}

string Cressource_numerique::get_chemin_acces(){
    return _chemin_acces;
}

string Cressource_numerique::get_format(){
    return _format;
}

void Cressource_numerique::from_file(ifstream& Lfichier, string Lbuff) {
    Cressource::from_file(Lfichier,Lbuff);

    //Infos ressource num
    _type = RESSOURCE_NUMERIQUE;
    getline(Lfichier, Lbuff);
    _taille = stoi(Lbuff);
    getline(Lfichier, Lbuff);
    _chemin_acces = Lbuff;
    getline(Lfichier, Lbuff);
    _format = Lbuff;
}


//AUTRES FONCTIONS

void LOAD(const char* Lnomfichier, Cmediatheque &Lmediatheque,vector<int> &Lids_dispo){
    string buff;
    ifstream fichier(Lnomfichier, ios::in);
    if (fichier){
        cout<<"fichier ouvert"<<endl;
        while(!fichier.eof()){
            getline(fichier,buff);
            if (buff.compare("LIVRE") == 0){
                //cout<<"ajout d'un livre"<<endl;
                Clivre *livretmp = new Clivre(fichier,buff);
                Lmediatheque.livres.push_back(livretmp);
                //livretmp->affichage();
            }
            if (buff.compare("REVUE") == 0){
                //cout<<"ajout d'une revue"<<endl;
                Crevue *revuetmp = new Crevue(fichier,buff);
                Lmediatheque.revues.push_back(revuetmp);
            }
            if (buff.compare("VHS")   == 0){
                //cout<<"ajout d'une vhs"<<endl;
                Cvhs *vhstmp = new Cvhs(fichier,buff);
                Lmediatheque.vhs.push_back(vhstmp);
            }
            if (buff.compare("DVD")   == 0){
                //cout<<"ajout d'un DVD"<<endl;
                Cdvd *dvdtmp = new Cdvd(fichier,buff);
                Lmediatheque.dvds.push_back(dvdtmp);
            }
            if (buff.compare("CD")    == 0){
                //cout<<"ajout d'un CD"<<endl;
                Ccd *cdtmp = new Ccd(fichier,buff);
                Lmediatheque.cds.push_back(cdtmp);
            }
            if (buff.compare("RESSOURCE_NUMERIQUE") == 0){
                //cout<<"ajout d'une ressource numerique"<<endl;
                Cressource_numerique *numtmp = new Cressource_numerique(fichier,buff);
                Lmediatheque.ressources_numeriques.push_back(numtmp);
            }
            if (buff.compare("ID_DISPO") == 0){
                int Buff;
                while(!fichier.eof()){
                    getline(fichier,buff);
                    Buff = stoi(buff);
                    Lids_dispo.push_back(Buff);
                }
            }
        }
        fichier.close();
        cout<<"chargement termine"<<endl;
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

void SAVE(const char* Lnomfichier, Cmediatheque &Lmediatheque, vector<int> &Lids_dispo){
    ofstream fichier(Lnomfichier, ios::out | ios::trunc);
    if(fichier){
        for(vector<Clivre*>::iterator it = Lmediatheque.livres.begin(); it!=Lmediatheque.livres.end(); ++it){
            fichier << "LIVRE" << "\n";
            fichier << (*it)->get_titre() << "\n";
            fichier << (*it)->get_auteur()<< "\n";
            fichier << (*it)->get_titre() << "\n";
            fichier << (*it)->get_date_de_sortie().jour << "\n";
            fichier << (*it)->get_date_de_sortie().mois << "\n";
            fichier << (*it)->get_date_de_sortie().annee << "\n";
            fichier << (*it)->get_ID() << "\n";
            fichier << (*it)->get_locataire() << "\n";
            fichier << (*it)->get_periode_emprunt().debut.jour << "\n";
            fichier << (*it)->get_periode_emprunt().debut.mois << "\n";
            fichier << (*it)->get_periode_emprunt().debut.annee << "\n";
            fichier << (*it)->get_periode_emprunt().fin.jour << "\n";
            fichier << (*it)->get_periode_emprunt().fin.mois << "\n";
            fichier << (*it)->get_periode_emprunt().fin.annee << "\n";
            fichier << (*it)->get_nbr_pages() << "\n";
            fichier << (*it)->get_collection() << "\n";
            fichier << (*it)->get_resume() << "\n";
            fichier << "\n";
        }
        for(vector<Crevue*>::iterator it = Lmediatheque.revues.begin(); it!=Lmediatheque.revues.end(); ++it){
            fichier << "Revue" << "\n";
            fichier << (*it)->get_titre() << "\n";
            fichier << (*it)->get_auteur() << "\n";
            fichier << (*it)->get_titre() << "\n";
            fichier << (*it)->get_date_de_sortie().jour << "\n";
            fichier << (*it)->get_date_de_sortie().mois << "\n";
            fichier << (*it)->get_date_de_sortie().annee << "\n";
            fichier << (*it)->get_ID() << "\n";
            fichier << (*it)->get_locataire() << "\n";
            fichier << (*it)->get_periode_emprunt().debut.jour << "\n";
            fichier << (*it)->get_periode_emprunt().debut.mois << "\n";
            fichier << (*it)->get_periode_emprunt().debut.annee << "\n";
            fichier << (*it)->get_periode_emprunt().fin.jour << "\n";
            fichier << (*it)->get_periode_emprunt().fin.mois << "\n";
            fichier << (*it)->get_periode_emprunt().fin.annee << "\n";
            fichier << (*it)->get_nbr_pages() << "\n";
            fichier << (*it)->get_collection() << "\n";
            fichier << (*it)->get_resume() << "\n";
            fichier << (*it)->get_editeur() << "\n";
            fichier << (*it)->get_nbr_articles() << "\n";
            fichier << (*it)->get_nom_articles() << "\n";
            fichier << "\n";
        }
        for(vector<Ccd*>::iterator it = Lmediatheque.cds.begin(); it!=Lmediatheque.cds.end(); ++it){
            fichier << "CD" << "\n";
            fichier << (*it)->get_titre() << "\n";
            fichier << (*it)->get_auteur() << "\n";
            fichier << (*it)->get_titre() << "\n";
            fichier << (*it)->get_date_de_sortie().jour << "\n";
            fichier << (*it)->get_date_de_sortie().mois << "\n";
            fichier << (*it)->get_date_de_sortie().annee << "\n";
            fichier << (*it)->get_ID() << "\n";
            fichier << (*it)->get_locataire();
            fichier << (*it)->get_periode_emprunt().debut.jour << "\n";
            fichier << (*it)->get_periode_emprunt().debut.mois << "\n";
            fichier << (*it)->get_periode_emprunt().debut.annee << "\n";
            fichier << (*it)->get_periode_emprunt().fin.jour << "\n";
            fichier << (*it)->get_periode_emprunt().fin.mois << "\n";
            fichier << (*it)->get_periode_emprunt().fin.annee << "\n";
            fichier << (*it)->get_duree() << "\n";
            fichier << (*it)->get_nbr_pistes() << "\n";
            fichier << (*it)->get_maison_de_producton() << "\n";
            fichier << "\n";

        }
        for(vector<Cdvd*>::iterator it = Lmediatheque.dvds.begin(); it!=Lmediatheque.dvds.end(); ++it){
            fichier << "DVD" << "\n";
            fichier << (*it)->get_titre() << "\n";
            fichier << (*it)->get_auteur() << "\n";
            fichier << (*it)->get_titre() << "\n";
            fichier << (*it)->get_date_de_sortie().jour << "\n";
            fichier << (*it)->get_date_de_sortie().mois << "\n";
            fichier << (*it)->get_date_de_sortie().annee << "\n";
            fichier << (*it)->get_ID() << "\n";
            fichier << (*it)->get_locataire() << "\n";
            fichier << (*it)->get_periode_emprunt().debut.jour << "\n";
            fichier << (*it)->get_periode_emprunt().debut.mois << "\n";
            fichier << (*it)->get_periode_emprunt().debut.annee << "\n";
            fichier << (*it)->get_periode_emprunt().fin.jour << "\n";
            fichier << (*it)->get_periode_emprunt().fin.mois << "\n";
            fichier << (*it)->get_periode_emprunt().fin.annee << "\n";
            fichier << (*it)->get_duree() << "\n";
            fichier << (*it)->get_maison_de_producton() << "\n";
            fichier << (*it)->get_nbr_chapitres() << "\n";
            fichier << "\n";
        }
        for(vector<Cvhs*>::iterator it = Lmediatheque.vhs.begin(); it!=Lmediatheque.vhs.end(); ++it){
            fichier << "VHS" << "\n";
            fichier << (*it)->get_titre() << "\n";
            fichier << (*it)->get_auteur() << "\n";
            fichier << (*it)->get_titre() << "\n";
            fichier << (*it)->get_date_de_sortie().jour << "\n";
            fichier << (*it)->get_date_de_sortie().mois << "\n";
            fichier << (*it)->get_date_de_sortie().annee << "\n";
            fichier << (*it)->get_ID() << "\n";
            fichier << (*it)->get_locataire() << "\n";
            fichier << (*it)->get_periode_emprunt().debut.jour << "\n";
            fichier << (*it)->get_periode_emprunt().debut.mois << "\n";
            fichier << (*it)->get_periode_emprunt().debut.annee << "\n";
            fichier << (*it)->get_periode_emprunt().fin.jour << "\n";
            fichier << (*it)->get_periode_emprunt().fin.mois << "\n";
            fichier << (*it)->get_periode_emprunt().fin.annee << "\n";
            fichier << (*it)->get_duree() << "\n";
            fichier << (*it)->get_maison_de_producton() << "\n";
            fichier << "\n";
        }
        for(vector<Cressource_numerique*>::iterator it = Lmediatheque.ressources_numeriques.begin(); it!=Lmediatheque.ressources_numeriques.end(); ++it){
            fichier << "RESSOURCE_NUMERIQUE" << "\n";
            fichier << (*it)->get_titre() << "\n";
            fichier << (*it)->get_auteur() << "\n";
            fichier << (*it)->get_titre() << "\n";
            fichier << (*it)->get_date_de_sortie().jour << "\n";
            fichier << (*it)->get_date_de_sortie().mois << "\n";
            fichier << (*it)->get_date_de_sortie().annee << "\n";
            fichier << (*it)->get_ID() << "\n";
            fichier << (*it)->get_locataire() << "\n";
            fichier << (*it)->get_periode_emprunt().debut.jour << "\n";
            fichier << (*it)->get_periode_emprunt().debut.mois << "\n";
            fichier << (*it)->get_periode_emprunt().debut.annee << "\n";
            fichier << (*it)->get_periode_emprunt().fin.jour << "\n";
            fichier << (*it)->get_periode_emprunt().fin.mois << "\n";
            fichier << (*it)->get_periode_emprunt().fin.annee << "\n";
            fichier << (*it)->get_taille() << "\n";
            fichier << (*it)->get_chemin_acces() << "\n";
            fichier << (*it)->get_format() << "\n";
            fichier << "\n";
        }
        fichier << "ID_DISPO \n";
        for(vector<int>::iterator it = Lids_dispo.begin(); it!=Lids_dispo.end(); ++it) {
            fichier << *it << "\n";
        }
    }
        else
        cerr << "Impossible d'ouvrir le fichier de sauvegarde!" << endl;
}

void ADD(Cmediatheque &Lmediatheque, vector<int> &Lids_dispo){
    string titre;
    string auteur;
    date   date_de_sortie;
    int    ID;
    string type;
    string locataire;
    cout << "Quel type de ressource voulez vous ajouter ? : " << endl;
    cin >> type;
    cout << "Titre ? :" << endl;
    fflush(stdin);
    getline(cin,titre);
    cout << "("<<titre<<")" <<endl;
    cout << "Auteur ? : " << endl;
    fflush(stdin);
    getline(cin,auteur);
    cout << "Jour de sortie ? : \n" << endl;
    cin >> date_de_sortie.jour;
    cout << "Mois de sortie ? : \n" << endl;
    cin >> date_de_sortie.mois;
    cout << "Annee de sortie ? : \n" << endl;
    cin >> date_de_sortie.annee;
    cout << "Locataire ? : \n" << endl;
    fflush(stdin);
    getline(cin,locataire);
    /*cout << "Jour d'emprunt ? : \n" << endl;
    cin >> periode_emprunt.debut.jour;
    cout << "Mois d'emprunt ? : \n" << endl;
    cin >> periode_emprunt.debut.mois;
    cout << "Annee d'emprunt ? : \n" << endl;
    cin >> periode_emprunt.debut.annee;
    cout << "Jour de remise ? : \n" << endl;
    cin >> periode_emprunt.fin.jour;
    cout << "Mois de remise ? : \n" << endl;
    cin >> periode_emprunt.fin.mois;
    cout << "Annee de remise ? : \n" << endl;
    cin >> periode_emprunt.fin.annee;*/

    if(Lids_dispo.size()>1){
        vector<int>::iterator it = Lids_dispo.end();
        ID = (*it);
        Lids_dispo.pop_back();
    }
    else{
        Lids_dispo.push_back(Lids_dispo[0]+1);
        ID = Lids_dispo[0];
        Lids_dispo.erase(Lids_dispo.begin());
    }

    if (type == "LIVRE"){
        int    nbr_pages;
        string collection;
        string resume;
        cout << "Nombre de pages ? : \n" << endl;
        cin >> nbr_pages;
        cout << "Collection ? : \n" << endl;
        fflush(stdin);
        getline(cin,collection);
        cout << "Resume ? : \n" << endl;
        fflush(stdin);
        getline(cin,resume);
        Clivre *livretmp = new Clivre(titre,auteur,date_de_sortie,ID,nbr_pages,collection,resume);
        Lmediatheque.livres.push_back(livretmp);
    }
    if (type == "REVUE") {
        int nbr_pages;
        string collection;
        string resume;
        string editeur;
        int nbr_articles;
        string nom_articles;
        cout << "Nombre de pages ? : \n" << endl;
        cin >> nbr_pages;
        cout << "Collection ? : \n" << endl;
        fflush(stdin);
        getline(cin,collection);
        cout << "Resume ? : \n" << endl;
        fflush(stdin);
        getline(cin,resume);
        cout << "Editeur ? : \n" << endl;
        fflush(stdin);
        getline(cin,editeur);
        cout << "Nombre d'articles ? : \n" << endl;
        cin >> nbr_articles;
        cout << "Noms des articles ? ? : \n" << endl;
        fflush(stdin);
        getline(cin,nom_articles);
        Crevue *revuetmp = new Crevue(titre, auteur, date_de_sortie, ID, nbr_pages, collection, resume, editeur,
                                      nbr_articles, nom_articles);
        Lmediatheque.revues.push_back(revuetmp);
    }
    if (type == "CD") {
        int duree;
        int nbr_pistes;
        string maison_de_production;
        cout << "Duree ? : \n" << endl;
        cin >> duree;
        cout << "Nombre de pistes ? : \n" << endl;
        cin >> nbr_pistes;
        cout << "Maison de production ? : \n" << endl;
        fflush(stdin);
        getline(cin,maison_de_production);
        Ccd *cdtmp = new Ccd(titre, auteur, date_de_sortie, ID,duree,nbr_pistes,maison_de_production);
        Lmediatheque.cds.push_back(cdtmp);
    }
    if (type == "DVD") {
        int duree;
        string maison_de_production;
        int nbr_chapitre;
        cout << "Duree ? : \n" << endl;
        cin >> duree;
        cout << "Maison de production ? : \n" << endl;
        fflush(stdin);
        getline(cin,maison_de_production);
        cout << "Nombre de chapitres ? : \n" << endl;
        cin >> nbr_chapitre;
        Cdvd *dvdtmp = new Cdvd(titre, auteur, date_de_sortie, ID,duree,maison_de_production,nbr_chapitre);
        Lmediatheque.dvds.push_back(dvdtmp);
    }
    if (type == "VHS") {
        int duree;
        string maison_de_production;
        cout << "Duree ? : \n" << endl;
        cin >> duree;
        cout << "Maison de production ? : \n" << endl;
        fflush(stdin);
        getline(cin,maison_de_production);
        Cvhs *vhstmp = new Cvhs(titre, auteur, date_de_sortie, ID,duree,maison_de_production);
        Lmediatheque.vhs.push_back(vhstmp);
    }
    if (type == "RESSOURCE_NUMERIQUE") {
        int taille;
        string chemin_acces;
        string format;
        cout << "Taille ? : \n" << endl;
        cin >> taille;
        cout << "Chemin d'acces ? : \n" << endl;
        fflush(stdin);
        getline(cin,chemin_acces);
        cout << "Format ? : \n" << endl;
        fflush(stdin);
        getline(cin,format);
        Cressource_numerique *vhstmp = new Cressource_numerique(titre, auteur, date_de_sortie, ID,taille,chemin_acces,format);
        Lmediatheque.ressources_numeriques.push_back(vhstmp);
    }
}

void DELETE(int ID, Cmediatheque &Lmediatheque, vector<int> &Lids_dispo) {

    int id_trouve = 0;
    //test sur les livres
    vector<Clivre*>::iterator it_livre = Lmediatheque.livres.begin();
    cout << "vecteur it-livre créé" << endl;
    while ((id_trouve == 0)) {
        cout <<"on est dans le while de livre" << endl;
        if ((*it_livre)->get_ID() == ID) {
            cout << "on est dans le if de livre" << endl;
            id_trouve++;
            Lmediatheque.livres.erase(it_livre);
            cout << "livre suppr" << endl;
        }
        else {
            if (it_livre < Lmediatheque.livres.end()) {
                cout << "on est dans le else fi de livre" << endl;
                it_livre++;
            }
            else{
                break;
            }
        }

    }
    cout << "coucou c'est brussy" << endl;
    //test sur les revues
    vector<Crevue*>::iterator it_revue = Lmediatheque.revues.begin();
    cout << "vecteur it_revue cree" << endl;
    while (it_revue <= Lmediatheque.revues.end() && (id_trouve == 0)) {
        if ((*it_revue)->get_ID() == ID) {
            id_trouve++;
            Lmediatheque.revues.erase(it_revue);
            //printf("supp revue\n");
        }
        else if (it_revue <  Lmediatheque.revues.end())
            it_revue++;
    }
    //test sur les CDs
    vector<Ccd*>::iterator it_cd = Lmediatheque.cds.begin();
    while (it_cd <= Lmediatheque.cds.end() && (id_trouve == 0)) {
        if ((*it_cd)->get_ID() == ID) {
            id_trouve++;
            Lmediatheque.cds.erase(it_cd);
            //printf("supp cd\n");
        }
        else if (it_cd <  Lmediatheque.cds.end())
            it_cd++;
    }
    //test sur les DVDs
    vector<Cdvd*>::iterator it_dvd = Lmediatheque.dvds.begin();
    while (it_dvd <= Lmediatheque.dvds.end() && (id_trouve == 0)) {
        if ((*it_dvd)->get_ID() == ID) {
            id_trouve++;
            Lmediatheque.dvds.erase(it_dvd);
            //printf("supp dvd\n");
        }
        else if (it_dvd <  Lmediatheque.dvds.end())
            it_dvd++;
    }
    //test sur les vhs
    vector<Cvhs*>::iterator it_vhs = Lmediatheque.vhs.begin();
    while (it_vhs <= Lmediatheque.vhs.end() && (id_trouve == 0)) {
        if ((*it_vhs)->get_ID() == ID) {
            id_trouve++;
            Lmediatheque.vhs.erase(it_vhs);
            //printf("supp vhs\n");
        }
        else if (it_vhs <  Lmediatheque.vhs.end())
            it_vhs++;
    }
    //test sur les ressources numériques
    vector<Cressource_numerique*>::iterator it_rs = Lmediatheque.ressources_numeriques.begin();
    while (it_rs <= Lmediatheque.ressources_numeriques.end() && (id_trouve == 0)) {
        if ((*it_rs)->get_ID() == ID) {
            id_trouve++;
            Lmediatheque.ressources_numeriques.erase(it_rs);
            //printf("supp ressource num\n");
        }
        else if (it_rs <  Lmediatheque.ressources_numeriques.end())
            it_rs++;
    }

    if (id_trouve == 0)
        cout << "cet identifiant n'est pas attribué" << endl;

}

