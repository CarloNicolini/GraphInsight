/****************************************************************************
**
** Copyright (C) 2010 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

#include "Graph.h"
#include "GraphLayout.h"
#include "LNode.h"

#include "Statistic.h"
#include "Matcher.h"
#include "Common.h"

#include "LabelVisualizer.h"

using namespace std;


void randomizeSeed(void)
{  int stime;
   long ltime;
   ltime = time(NULL);
   stime = (unsigned) ltime / 2;
   srand(stime);
}


int main(int argc, char *argv[])
{  if ( argc < 4 )
   {  cerr << "Normalize the IDS of a dimacs valid file." << endl;
      cerr << "Usage: ./normalize [input] [output] [mode]" << endl;
      cerr << "Where:\n\tmode=1 -> output in dimac format (default)\n\tmode=2 -> output in Grapheur format\n\tmode=3 output in DOT format\n";
      exit(0);
   }

   ifstream is;
   is.open(argv[1]);

   ofstream output;
   output.open(argv[2]);
   GraphLayout *g = new GraphLayout();
   GraphLayout *h = new GraphLayout();

   g->loadDimacs(is);
   h = (GraphLayout*) (g->normalizeIds());

   cerr << "(|V|,|E|)=(" << g->nodes.size() << " " << g->getEdgesCount() << " )" << endl;
   switch ( atoi(argv[3]) )
   {  case 1:

         h->writeDimacs(output);
         break;
      case 2:
         h->writeGRAPHEUR(output);
         break;
      case 3:
         h->writeDOT(output);
         break;
      default:
         h->writeDimacs(output);
   }

   is.close();
   output.close();
   delete h;
   delete g;

   return 0;
}
