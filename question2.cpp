#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>
#include "bibparser.h"
using namespace std;

void check_affilation(vector<Publication*>& pubs)
{
    for(auto pb:pubs)
    {
      for(auto aff: pb->get_affliation())
      if(aff.second=="IIIT-Delhi")
      return;
    }

    assert(false&&"No auhtor has Institute Affliation");

}

int main()
{
 BibParser bp;
 bp.store_publication();
 bp.store_affliation();

 bp.print_Publications();

 check_affilation(bp.get_publications());

}
