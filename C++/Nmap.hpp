#ifndef NMAP_HPP
#define NMAP_HPP

#include <iostream>
#include <memory>
#include <cstdio>
#include <string>
#include <sstream>


class Scanneur
{
    public :
            Scanneur() ;
            ~Scanneur() ;

            std::string decouverte_hotes(std::string ip) ;
            std::string detection_services( std::string ip) ;
            std::string detection_os(std::string ip) ;
            std::string scan_syn(std::string ip) ;
            std::string executeur(const char *cmd) ;

            std::string format_sn(const std::string& output) ;
            std::string format_sv(const std::string& output)  ;
            std::string format_os(const std::string& output)  ;
            std::string format_syn(const std::string& output) ;

            std::string print_separator() ;


            void set_ip(std::string ip) ;
            std::string get_ip() ;
            
    private :
            std::string m_ip ;


} ;

#endif