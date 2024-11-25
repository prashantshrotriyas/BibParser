# ifndef BIBPARSER_H
# define  BIBPARSER_H

# include <iostream>
# include <vector>
# include <map>
# include <string>
# include "publication.h"

class BibParser
{
  private:
  vector<Publication*> pubs;
  map<string, vector<Publication *>> mapping;
  public:
  void store_publication_helper(string eachline, ifstream &bibfile);
  void store_affliation();
  void print_author_publications(string authorname);
  void store_publication();
  map<string, vector<Publication *>> & get_mapping();

  vector<Publication*>& get_publications();
  void print_Publications();
 

};

#endif