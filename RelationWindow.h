#ifndef CREARELAWINDOW_H
#define CREARELAWINDOW_H

#include"relations.h"

#include <QWidget>
#include <QList>

#include <QListWidget>
#include <QLineEdit>
#include <QTextEdit>

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QLabel>

#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>


class CreationRelationWindow : public QWidget{

    Q_OBJECT

public:
    CreationRelationWindow(QWidget *parent = 0);
    CreationRelationWindow(Relation* rela, QWidget *parent = 0);

    QPushButton* getButtonCreate() {return button_create;}
    QPushButton* getButtonClose() {return button_close;}
    QLineEdit* getTitre() {return titre; }

private:

    QList<QString> tab_id_x;
    QList<QString> tab_id_y;

    QVBoxLayout *fenetre_vbox;

    QHBoxLayout *titre_hbox;
    QLabel *titre_label;
    QLineEdit *titre;
    QString titre_ancien;

    QHBoxLayout * description_hbox;
    QLabel *description_label;
    QTextEdit *description;

    QCheckBox *non_oriente;

    QHBoxLayout *button_layout;
    QPushButton *button_create;
    QPushButton *button_close;
    QPushButton *button_save;

public slots:
    void create();
    void save();

};


class ExplorateurRelationWindow : public QWidget{

    Q_OBJECT

public:
    ExplorateurRelationWindow(QWidget *parent = 0);

    QPushButton* getButtonSuprime() {return button_supprimer;}
    QListWidget* getListe() {return liste; }

private:

    QVBoxLayout *fenetre_vbox;

    QLabel *titre;

    QListWidget *liste;

    QHBoxLayout *button_layout;
    QPushButton *button_supprimer;
    QPushButton *button_close;

};


class CoupleWindow : public QWidget{

    Q_OBJECT

public:
    CoupleWindow(Relation* rela, QWidget *parent = 0);

    QPushButton* getButtonCreate() {return button_create;}

private:

    QList<QString> tab_id_x;
    QList<QString> tab_id_y;

    QVBoxLayout *fenetre_vbox;

    QLabel *titre_rela;

    QHBoxLayout * couple_hbox;
    QLabel *couple_label;
    QLineEdit *couple;

    QListWidget *liste_x;
    QListWidget *liste_y;

    QHBoxLayout *button_layout;
    QPushButton *button_create;
    QPushButton *button_close;

public slots:
    void save();

};



class RelationVizingWindow : public QWidget{

    Q_OBJECT

public:
    RelationVizingWindow(QWidget *parent = 0);

    QPushButton* getButtonSuprime() {return button_supprimer;}
    QListWidget* getListeCouple() {return liste_couples; }

private:

    QVBoxLayout *fenetre_vbox;

    QComboBox *relation;

    QListWidget *liste_couples;

    QHBoxLayout *button_layout;
    QPushButton *button_supprimer;
    QPushButton *button_close;

    QHBoxLayout *label_hbox;
    QLabel *label_label;
    QLineEdit *label;
    QPushButton * label_save;

public slots:
    void afficherCouples();
    void editer_couple();
    void saveLabel();
    void deleteCouple();

};


#endif // CREARELAWINDOW_H
