#ifndef PUBLICATION_H
#define PUBLICATION_H
# include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
class Publication
{
private:
    string title;
    string venue;
    vector<string> authors;
    map<string, string> affiliation;
    string doi;
    int year;

public:
    void set_title(string title);
    string get_title();
    void set_venue(string venue);
    string get_venue();
    void set_doi(string doi);
    string get_doi();
    void set_year(int year);
    int get_year();
    void set_author(string author);
    void print_author();
    map<string, string> &get_affliation();
    void print_publication();
};

#endif