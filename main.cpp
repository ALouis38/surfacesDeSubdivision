#include "face.h"
#include "point.h"
#include "filemanager.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<Point>> listePoints;
vector<vector<Point>> listePointsFinaux;
vector<Face> listeFaces;
int nbLigne = 3;
int nbColonne = 5;

void commeTuVeux()
{
    float x,y,z;

    vector<vector<Point>> listeTmp = listePoints;
    vector<vector<Point>> listeTmp2;

    for (int k = 0; k < 4; ++k) {

        size_t nbLigne = listeTmp.size();
        size_t nbColonne = listeTmp[0].size();

        listeTmp2 = vector<vector<Point>>(2*(nbLigne-1));
        for (size_t k = 0; k < listeTmp2.size(); ++k) {
            listeTmp2[k] = vector<Point>(2*(nbColonne-1));
        }

        for (size_t j = 0; j < nbLigne-1; ++j) {
            for (size_t i = 0; i < nbColonne-1; ++i) {
                // Point 1
                x = (9.0*listeTmp[j][i].getX() + 3.0*listeTmp[j][i+1].getX() + 3.0*listeTmp[j+1][i].getX() + listeTmp[j+1][i+1].getX())/16.0;
                y = (9.0*listeTmp[j][i].getY() + 3.0*listeTmp[j][i+1].getY() + 3.0*listeTmp[j+1][i].getY() + listeTmp[j+1][i+1].getY())/16.0;
                z = (9.0*listeTmp[j][i].getZ() + 3.0*listeTmp[j][i+1].getZ() + 3.0*listeTmp[j+1][i].getZ() + listeTmp[j+1][i+1].getZ())/16.0;
                Point t1(x, y, z);

                // Point 2
                x = (3.0*listeTmp[j][i].getX() + 9.0*listeTmp[j][i+1].getX() + listeTmp[j+1][i].getX() + 3.0*listeTmp[j+1][i+1].getX())/16.0;
                y = (3.0*listeTmp[j][i].getY() + 9.0*listeTmp[j][i+1].getY() + listeTmp[j+1][i].getY() + 3.0*listeTmp[j+1][i+1].getY())/16.0;
                z = (3.0*listeTmp[j][i].getZ() + 9.0*listeTmp[j][i+1].getZ() + listeTmp[j+1][i].getZ() + 3.0*listeTmp[j+1][i+1].getZ())/16.0;
                Point t2(x, y, z);

                // Point 3
                x = (listeTmp[j][i].getX() + 3.0*listeTmp[j][i+1].getX() + 3.0*listeTmp[j+1][i].getX() + 9.0*listeTmp[j+1][i+1].getX())/16.0;
                y = (listeTmp[j][i].getY() + 3.0*listeTmp[j][i+1].getY() + 3.0*listeTmp[j+1][i].getY() + 9.0*listeTmp[j+1][i+1].getY())/16.0;
                z = (listeTmp[j][i].getZ() + 3.0*listeTmp[j][i+1].getZ() + 3.0*listeTmp[j+1][i].getZ() + 9.0*listeTmp[j+1][i+1].getZ())/16.0;
                Point t3(x, y, z);

                // Point 4
                x = (3.0*listeTmp[j][i].getX() + listeTmp[j][i+1].getX() + 9.0*listeTmp[j+1][i].getX() + 3.0*listeTmp[j+1][i+1].getX())/16.0;
                y = (3.0*listeTmp[j][i].getY() + listeTmp[j][i+1].getY() + 9.0*listeTmp[j+1][i].getY() + 3.0*listeTmp[j+1][i+1].getY())/16.0;
                z = (3.0*listeTmp[j][i].getZ() + listeTmp[j][i+1].getZ() + 9.0*listeTmp[j+1][i].getZ() + 3.0*listeTmp[j+1][i+1].getZ())/16.0;
                Point t4(x, y, z);

                listeTmp2[2*j][2*i] = t1;
                listeTmp2[2*j][2*i+1] = t2;
                listeTmp2[2*j+1][2*i+1] = t3;
                listeTmp2[2*j+1][2*i] = t4;
            }
        }

        listeTmp = listeTmp2;
        listeTmp2.clear();
    }

    listePointsFinaux = listeTmp;
}

void commeTuVeuxFerme()
{
    float x,y,z;

    vector<vector<Point>> listeTmp = listePoints;
    vector<vector<Point>> listeTmp2;

    for (int k = 0; k < 4; ++k) {

        size_t nbLigne = listeTmp.size();
        size_t nbColonne = listeTmp[0].size();

        listeTmp2 = vector<vector<Point>>(2*(nbLigne-1));
        for (size_t k = 0; k < listeTmp2.size(); ++k) {
            listeTmp2[k] = vector<Point>(2*(nbColonne-1));
        }

        int l = nbColonne-1;
        int m = nbLigne-1;

        for (size_t j = 0; j < nbLigne-1; ++j) {
            for (size_t i = 0; i < nbColonne-1; ++i) {
                // Point 1
                x = (9.0*listeTmp[j][i].getX() + 3.0*listeTmp[j][i+1].getX() + 3.0*listeTmp[j+1][i].getX() + listeTmp[j+1][i+1].getX())/16.0;
                y = (9.0*listeTmp[j][i].getY() + 3.0*listeTmp[j][i+1].getY() + 3.0*listeTmp[j+1][i].getY() + listeTmp[j+1][i+1].getY())/16.0;
                z = (9.0*listeTmp[j][i].getZ() + 3.0*listeTmp[j][i+1].getZ() + 3.0*listeTmp[j+1][i].getZ() + listeTmp[j+1][i+1].getZ())/16.0;
                Point t1(x, y, z);

                // Point 2
                x = (3.0*listeTmp[j][i].getX() + 9.0*listeTmp[j][i+1].getX() + listeTmp[j+1][i].getX() + 3.0*listeTmp[j+1][i+1].getX())/16.0;
                y = (3.0*listeTmp[j][i].getY() + 9.0*listeTmp[j][i+1].getY() + listeTmp[j+1][i].getY() + 3.0*listeTmp[j+1][i+1].getY())/16.0;
                z = (3.0*listeTmp[j][i].getZ() + 9.0*listeTmp[j][i+1].getZ() + listeTmp[j+1][i].getZ() + 3.0*listeTmp[j+1][i+1].getZ())/16.0;
                Point t2(x, y, z);

                // Point 3
                x = (listeTmp[j][i].getX() + 3.0*listeTmp[j][i+1].getX() + 3.0*listeTmp[j+1][i].getX() + 9.0*listeTmp[j+1][i+1].getX())/16.0;
                y = (listeTmp[j][i].getY() + 3.0*listeTmp[j][i+1].getY() + 3.0*listeTmp[j+1][i].getY() + 9.0*listeTmp[j+1][i+1].getY())/16.0;
                z = (listeTmp[j][i].getZ() + 3.0*listeTmp[j][i+1].getZ() + 3.0*listeTmp[j+1][i].getZ() + 9.0*listeTmp[j+1][i+1].getZ())/16.0;
                Point t3(x, y, z);

                // Point 4
                x = (3.0*listeTmp[j][i].getX() + listeTmp[j][i+1].getX() + 9.0*listeTmp[j+1][i].getX() + 3.0*listeTmp[j+1][i+1].getX())/16.0;
                y = (3.0*listeTmp[j][i].getY() + listeTmp[j][i+1].getY() + 9.0*listeTmp[j+1][i].getY() + 3.0*listeTmp[j+1][i+1].getY())/16.0;
                z = (3.0*listeTmp[j][i].getZ() + listeTmp[j][i+1].getZ() + 9.0*listeTmp[j+1][i].getZ() + 3.0*listeTmp[j+1][i+1].getZ())/16.0;
                Point t4(x, y, z);

                listeTmp2[2*j][2*i] = t1;
                listeTmp2[2*j][2*i+1] = t2;
                listeTmp2[2*j+1][2*i+1] = t3;
                listeTmp2[2*j+1][2*i] = t4;
            }
        }

        listeTmp = listeTmp2;
        listeTmp2.clear();
    }

    listePointsFinaux = listeTmp;

}

int main()
{
    vector<Point> tmp;

    for (int j = 0; j < nbLigne; ++j) {
        tmp.clear();
        for (int i = 0; i < nbColonne; ++i) {
            tmp.push_back(Point(i*10,j*10,((i+j)%2)*10));
        }
        listePoints.push_back(tmp);
    }

    commeTuVeux();
    size_t nbLigne = listePointsFinaux.size();
    size_t nbColonne = listePointsFinaux[0].size();

    FileManager fm(QString("test_final.obj"));

    for (size_t j = 0; j < nbLigne; ++j) {
        for (size_t i = 0; i < nbColonne; ++i) {
            fm.addPoint(listePointsFinaux[j][i]);
        }
    }

    Face f;
    for (size_t k = 0; k < (nbLigne-1)*(nbColonne-1); ++k) {
        f.clear();
        int i = k%(nbColonne-1);
        int j = k/(nbColonne-1);
        f.ajouterIndice(j*nbColonne + i +1);
        f.ajouterIndice(j*nbColonne + i+1 +1);
        f.ajouterIndice((j+1)*nbColonne + i+1 +1);
        f.ajouterIndice((j+1)*nbColonne + i +1);
        fm.addFace(f);
    }

    fm.generate();

    return 0;
}


