# include <iostream>
# include "bibparser.h"
using namespace std;

void count_coauthor(string authorname,BibParser bp)
{   
    int total_authors=0;
    int total_pub=0;
     
     for(auto pub:bp.get_mapping()[authorname])
     {  
        total_pub++; 
        for(auto auth:pub->get_affliation())  
         total_authors++;
     }
     
     cout<<"The total number of Publication of "<<authorname<<" is :";
     cout<<total_pub<<endl;
     cout<<"The Average number of Co-Authors of "<<authorname<<" is :";
     cout<<(total_authors-total_pub)/total_pub<<endl;

}


int main(int argv ,char * argc[])
{   

     BibParser bp;
     bp.store_publication();
     bp.store_affliation();
     argv--;
     int i=1;
    
     while(i<=argv)
     {  
        cout<<argc[i];
        bp.print_author_publications(argc[i]);
        count_coauthor(argc[i],bp);
        i++;
     }

}