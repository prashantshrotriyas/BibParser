#include "bibparser.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>
using namespace std;

string bibfilepath = "publist.bib";
string csvfilepath = "Faculty_Affiliations.csv";

void BibParser::store_publication_helper(string eachline, ifstream &bibfile)
{

  Publication *temp = new Publication;

  while (getline(bibfile, eachline))
  {
      // check for formatting mistakes

    if (eachline[0] == '}' || eachline[0] == '{')
      assert(false && "Invalid BibFile !! Unbalanced Parenthesis");

    if (eachline.empty())
      break;

    int i = 0;
    while (isspace(eachline[i++]))
      continue;
    i--;

    eachline.erase(0, i);

    if (eachline.find("title") != string::npos)
    {

      int start = eachline.find('{');
      int end = eachline.find('}');
      temp->set_title(eachline.substr(start + 1, end - start - 1));
    }
    else if (eachline.find("doi") != string::npos)
    {

      int start = eachline.find('{');
      int end = eachline.find('}');
      temp->set_doi(eachline.substr(start + 1, end - start - 1));
    }
    else if (eachline.find("venue") != string::npos)
    {

      int start = eachline.find('{');
      int end = eachline.find('}');
      temp->set_venue(eachline.substr(start + 1, end - start - 1));
    }
    else if (eachline.find("year") != string::npos)
    {

      int start = eachline.find('{');
      int end = eachline.find('}');
      temp->set_year(stoi(eachline.substr(start + 1, end - start - 1)));
    }
    else if (eachline.find("author") != string::npos)
    {
      int start = eachline.find('{') + 1;
      int end = eachline.find('}');
      string author_list = eachline.substr(start, end - start);

      int pos = 0;
      while ((pos = author_list.find(" and ")) != string::npos)
      {
        string author = author_list.substr(0, pos);

        int last = author.find(' ');
        string lastname = author.substr(0, last - 1);
        string firstname = author.substr(last + 1, -1);
        author = firstname + " " + lastname;
        mapping[author].push_back(temp);

        temp->set_author(author);
        author_list.erase(0, pos + 5);
      }

      int last = author_list.find(' ');
      string lastname = author_list.substr(0, last - 1);
      string firstname = author_list.substr(last + 1, -1);
      author_list = firstname + " " + lastname;
      mapping[author_list].push_back(temp);
      temp->set_author(author_list);
    }
  }

  pubs.push_back(temp);
}

void BibParser::store_affliation()
{
  ifstream csvfile(csvfilepath);

  stringstream allcontentstream;
  allcontentstream << csvfile.rdbuf();

  string allcontent = allcontentstream.str();

  for (auto &pb : pubs)
  {
    for (auto &aff : pb->get_affliation())
    {

      if (allcontent.find(aff.first) != string::npos)
      {
        pb->get_affliation()[aff.first] = "IIIT-Delhi";
      }
    }
  }
}

void BibParser::print_author_publications(string authorname)
{
  cout << endl;
  for (auto pb : mapping[authorname])
  {
    pb->print_publication();
  }
}


void BibParser::store_publication()
{
  ifstream bibfile(bibfilepath);

  string eachline;
  while (getline(bibfile, eachline))
  {
    if (eachline[0] == '}' || eachline[0] == '{')
      cout << "Invalid BibFile !! Unbalanced Paranthesis";

    if (eachline[0] == '@')
    {
      store_publication_helper(eachline, bibfile);
    }
  }
}

map<string, vector<Publication *>> &BibParser::get_mapping()
{
  return mapping;
}

vector<Publication*>& BibParser::get_publications()
{
    return pubs;
}

void BibParser::print_Publications()
{
  for(auto pb:pubs)
  {
    pb->print_publication();
  }
}