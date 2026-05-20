#include <iostream>
#include "Nmap.hpp"

using namespace std ;


void clear_screen() ;

int main()
{
    Scanneur *scan = new Scanneur() ;
    std::string ip , result ;
    int choix = 0 ;
    
    ip = "" ;
    result = "" ;

    while (true)
    {
         
         cout << "\n========== MENU ===========\n";
         cout << "1. Host discovery\n";
         cout << "2. Service scan\n";
         cout << "3. OS detection\n";
         cout << "4. SYN scan\n";
         cout << "0. Quitter\n";
         cout << "Choix : ";
         cin >> choix ;

         clear_screen() ; 

        switch(choix)
        {
             case 1 :
                 cout << endl << endl ;
                 cout << "Entrer l'IP : " ;
                 cin >> ip ;

                 cout << " Traitement en cours..." << endl << flush ; 
                 result = scan->decouverte_hotes(ip) ;
                 cout << endl << result << endl ;
                 break ;

             case 2 :
                 cout << endl << endl ;
                 cout << "Entrer l'IP : " ;
                 cin >> ip ;

                 cout << " Traitement en cours..."<< endl  << flush ; 
                 result = scan->detection_services(ip) ;
                 cout << endl << result << endl ;
                 break ;

             case 3 :
                 cout << endl << endl ;
                 cout << "Entrer l'IP : " ;
                 cin >> ip ;

                 cout << " Traitement en cours..." << endl << flush ; 
                 result = scan->detection_os(ip) ;
                 cout << endl << result << endl ;

                 break ;

             case 4 :
                 cout << endl << endl ;
                 cout << "Entrer l'IP : " ;
                 cin >> ip ;


                 cout << " Traitement en cours..." << endl << flush ; 
                 result = scan->scan_syn(ip) ;
                 cout << endl << result << endl ;

                 break ;

             case 0 :
                 cout << endl << endl ;
                 cout << endl << "Merci pour votre utilsation" << endl ;
                 exit(0) ;

             default :
                 cout << endl << endl ;
                 cout << " Choix invalide " << endl ;

                 break ;

        }
    }

    return 0 ;
}


void clear_screen()
{
    std::cout << "\033[2J\033[1;1H";
}