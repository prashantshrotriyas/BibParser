 # include <iostream>
 # include "publication.h"
 # include <cassert>
 using namespace std;

 void Publication::set_title(string title)
   {
      this->title = title;
   }

   string Publication::get_title()
   {
      return title;
   }

   void Publication::set_venue(string venue)
   {
      this->venue = venue;
   }

   string Publication::get_venue()
   {
      return venue;
   }

   void Publication::set_doi(string doi)
   {
      this->doi = doi;
   }

   string Publication::get_doi()
   {
      return doi;
   }

   void Publication::set_year(int year)
   {
      this->year = year;
   }

   int Publication::get_year()
   {
      return year;
   }

   void Publication::set_author(string author)
   {   
      // check for repeatation of author
      if(affiliation.find(author)!=affiliation.end())
      assert(false && "Invalid Bibfile!! AuthorName is repeated twice");

      affiliation[author] = "";
   }

   void Publication::print_author()
   {
      for (auto athr : affiliation)
         cout << "Author :" << athr.first << " and  Affiliation :" << athr.second << endl;

      cout << endl;
   }

   map<string, string> &Publication::get_affliation()
   {
      return affiliation;
   }

   void Publication::print_publication()
   {
      cout << "Publication detail are :" << endl;
      cout << "The Title is :" << this->get_title() << endl;
      cout << "The Venue is :" << this->get_venue() << endl;
      cout << "The doi is :" << this->get_doi() << endl;
      cout << "The year is :" << this->get_year() << endl;
      cout << "The authors are :" << endl;
      this->print_author();
   }