#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>


#include "Graph.h"
#include "GraphLayout.h"
#include "LNode.h"

using namespace std;


int main(int argc, char *argv[])
{


    /*
    for (int i=0; i<labels.size(); i++)
        cout << "LABELS " << labels.at(i)->id<< " " << labels.at(i)->labelX  << " " << labels.at(i)->labelY << endl;

    double xmedian=labels.at(labels.size()/2)->labelX;
    vector<LNode*> R1,R2,R12;

    double baseX=labels.front()->labelX;
    int i=0;
    int medianLabel=-1;
    // Mette i rettangoli con x < mediana in R1, quelli con x> mediana in R2
    cerr << "XMEDIANA= " << xmedian << endl;
    while (baseX < (labels.back()->labelX) )
    {
        if ( baseX < xmedian )
        {
            R1.push_back(labels.at(i));
        }
        else
        {
            if (medianLabel!=-1)
                medianLabel=i;
            R2.push_back(labels.at(i));
        }
        baseX=labels.at(i++)->labelX;
    }
    cerr << "medianLabel= " << medianLabel << endl;

    // Ordina i rettangoli per Y crescente
    std::sort(labels.begin(), labels.end(),sortLabelByY);



    for (int i=0; i<R1.size(); i++)
        cout << "R1 " << R1.at(i)->id<< " " << R1.at(i)->labelX  << endl;

    for (int i=0; i<R12.size(); i++)
        cout << "R12 " << R12.at(i)->id<< " " << R12.at(i)->labelX << endl;

    for (int i=0; i<R2.size(); i++)
        cout << "R2 " << R2.at(i)->id<< " " << R2.at(i)->labelX << endl;
        */
return 0;
}
