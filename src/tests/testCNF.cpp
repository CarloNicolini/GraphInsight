#include <iostream>
#include "Graph.h"
#include "Cnf.h"
#include "Timer.h"

int main(int argc, char *argv[])
{
    Timer timer;
    timer.start();
    Cnf cnf;
    ifstream file(argv[1]);
    timer.start();
    cnf.loadFromFile(file);
    cerr << timer.getElapsedTimeInMilliSec() << "[ms]" << endl;
    file.close();
    file.open(argv[1]);

    cerr << "====" << endl;

    Cnf cnf2;
    timer.start();
    cnf2.loadFromFile2(file);
    cerr << timer.getElapsedTimeInMilliSec() << "[ms]" << endl;

    //cnf2.buildVariableInteractionGraph(new Graph());
    return 0;
}
