#include "Nmap.hpp"

Scanneur::Scanneur()
{

}


Scanneur::~Scanneur()
{

}


std::string Scanneur::decouverte_hotes(std::string ip)
{
     std::string cmd , result ;

     cmd = "nmap -sn " + ip ;
     result = executeur(cmd.c_str()) ;
     result = format_sn(result) ;

     return result ;
     
}


std::string Scanneur::detection_services(std::string ip)
{
    std::string cmd , result ;

     cmd = "nmap -sV " + ip ;
     result = executeur(cmd.c_str()) ;
     result = format_sv(result) ;

     return result ;
}


std::string Scanneur::detection_os(std::string ip) 
{
     std::string cmd , result ;

     cmd = "nmap -O " + ip ;
     result = executeur(cmd.c_str()) ;
     result = format_os(result) ;

     return result ;
}


std::string Scanneur::scan_syn(std::string ip)
{
     std::string cmd , result ;

     cmd = "nmap -sS " + ip ;
     result = executeur(cmd.c_str()) ;
     result = format_syn(result) ;

     return result ;
}


void Scanneur::set_ip(std::string ip)
{

}


std::string Scanneur::get_ip()
{
   return m_ip ;
}


std::string Scanneur::executeur(const char *cmd)
{
    FILE* pipe = popen(cmd, "r") ;
    
    char buffer[128];
    std::string result = "" ;


    if (!pipe)
      return "Erreur" ;

    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) 
    {
        result += buffer ; 
    }

    pclose(pipe) ;

    return result ;

}


std::string Scanneur::format_sn(const std::string& output) 
{
    std::cout << "\n=== HOST DISCOVERY (-sn) ===\n";

    std::string line , result ;
    std::istringstream stream(output) ;

    result = "" ;

    while (std::getline(stream, line)) 
    {
        if (line.find("Nmap scan report for") != std::string::npos) 
        {
            result += "[HOST] " + line  + "\n";
        }

        if (line.find("Host is up") != std::string::npos) 
        {
            result += "   └─> "  + line + "\n\n";
        }
    }

    if(result.empty())
     {
        result = " Erreur de scan \n" ;
     }

    result += print_separator() ;

    return result ;
}


std::string Scanneur::format_sv(const std::string& output) 
{
    std::cout << "\n=== SERVICE DETECTION (-sV) ===\n";

    std::string line , result ;
    std::istringstream stream(output);

    result = "" ;

    while (std::getline(stream, line)) 
    {

        if (line.find("/tcp") != std::string::npos || line.find("/udp") != std::string::npos) 
        {
            result += "[SERVICE] " + line + "\n";
        }

        if (line.find("Service detection performed") != std::string::npos) 
        {
            result += "\n[INFO] " + line + "\n" ;
        }
    }

    if(result.empty())
     {
        result = " Erreur de scan \n" ;
     }

    result += print_separator() ;

    return result ;
}


std::string Scanneur::format_os(const std::string& output) 
{
    std::cout << "\n=== OS DETECTION (-O) ===\n";

    std::string line , result ;
    std::istringstream stream(output) ;

    result = "" ;

    while (std::getline(stream, line)) 
    {

        if (line.find("Running:") != std::string::npos || line.find("OS details:") != std::string::npos || line.find("Aggressive OS guesses") != std::string::npos)
        {
            result += "[OS] " + line +  "\n" ;
        }
    }

    if(result.empty())
     {
        result = " Erreur de scan \n" ;
     }

    result += print_separator() ;

    return result ;
}


std::string Scanneur::format_syn(const std::string& output) 
{
    std::cout << "\n=== SYN SCAN (-sS) ===\n" ;

    std::string line , result ;
    std::istringstream stream(output) ;

    result = "" ;

    while (std::getline(stream, line)) 
    {

        if (line.find("open") != std::string::npos && line.find("/tcp") != std::string::npos)
        {
            result += "[OPEN PORT] " + line + "\n" ;
        }

        if (line.find("close") != std::string::npos && line.find("/tcp") != std::string::npos)
        {
            result += "[CLOSE PORT] " + line + "\n" ;
        }

        if (line.find("Not shown") != std::string::npos) 
        {
            result += "[INFO] " + line +"\n" ;
        }
    }

    if(result.empty())
     {
        result = " Erreur de scan \n" ;
     }

    result += print_separator() ;
    
    return result ;
}

std::string Scanneur::print_separator() 
{
    return "--------------------------------------\n" ;
}