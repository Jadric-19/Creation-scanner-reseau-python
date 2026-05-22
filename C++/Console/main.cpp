#include <iostream>
#include <memory>
#include <cstdio>
#include <string>

std::string exec(const char* cmd) 
{
    char buffer[128];
    std::string result = "";

    FILE* pipe = popen(cmd, "r");
    if (!pipe)
       return "Erreur";

    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) 
    {
        result += buffer;
    }

    pclose(pipe);
    return result;
}

int main() 
{
    std::string ip = "192.168.1.10";

    std::string command = "nmap -sV " + ip;

    std::string output = exec(command.c_str());

    std::cout << "=== RESULTAT NMAP ===\n";
    std::cout << output << std::endl;

    return 0;
}