#ifndef NOTES_H
#define NOTES_H

#include <QDateTime>

using namespace std;

enum TypeMultimedia{video, audio, image};
enum TypeStatut{attente, cours, termine};



/// ----- Notes ----- ///


class Note{
public:

private:
    string identificateur;
    string titre;
    QDateTime date_creation;
    QDateTime date_modif;

    friend class NotesManager;

    // fonctions appellées par NM

    save(); // enregistre avec tous les paramètres
    createMemento(); // enregistre un memento
    restoreMemento(); // restaure un memento
};

class Article : public Note {
    string texte;
};

class Tache : public Note {
    string action;
    unsigned int priorite; // optionnel
    QDateTime date_echeance; //optionnel
    TypeStatut statut;
};

class Mutimedia : public Note {
    string desctiption;
    string fichier; // adresse du fichier
    TypeMultimedia type; //type du fichier
};




/// ----- Notes Manager ----- ///


class NotesManager{
public:
    static NotesManager& donneInstance(){
        if (!instance)
            instance = new NotesManager();
        return *instance;
    }

    static void supprimeInstance(){
        if (instance){
            delete instance;
            instance = nullptr;
        }
    }

    class Iterator {
    public:
        Note* operator *(){
            return *current;
        }
        Note* operator ++(){
            if(last == 0)
                throw "il faut faire une calsse d'exceptions";
            --last;
            return *(++current);
        }
        Note* operator ++(int){
            if(last == 0)
                throw "il faut faire une calsse d'exceptions";
            Note* save = *current;
            ++current;
            --last;
            return save;
        }

    private:
        Note** current;
        unsigned int last;
        friend class NotesManager;
        Iterator(Note** _tab, unsigned int _nb_max)
            : current(_tab), last(_nb_max) {}
    };

    Iterator getIterator() {
        return Iterator(tab, nb_max);
    }

    createNote(const string& id, const string& titre); // crée une note vide avec id / titre / date
    saveNote(const string& id); // enregistre une note avec tout ce qu'il faut / ça fait un memento


private:
    Note** tab;
    unsigned int nb;
    unsigned int nb_max;

    static NotesManager* instance;
    NotesManager();
    NotesManager(const NotesManager&);
    virtual ~NotesManager();
    void operator =(const NotesManager&);

};


#endif // NOTES_H