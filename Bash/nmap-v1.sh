#!/bin/bash

# Verification de Nmap

if ! command -v nmap &>/dev/null
then
    echo "Erreur : Nmap n'est pas installe."
    exit 1
fi


verifier_cible()
{
    if [ -z "$1" ]
    then
        echo "Erreur : aucune IP ou domaine saisi."
        return 1
    fi

    return 0
}

# Fonction  Decouverte


decouverte_hotes()
{
    clear
    echo "===== DISCOVERY (HOSTS UP) ====="

    read -p "Reseau (ex: 192.168.1.0/24) : " cible

    if [ -z "$cible" ]; then
        echo "Erreur : reseau vide"
        return
    fi

    echo -e "\n[SCAN EN COURS...]\n"

    nmap -sn "$cible" | awk '
    /Nmap scan report/ {print "[+] Host detecte :", $5}
    /Host is up/ {print "    └─> Statut :", $0}
    '

    echo -e "\n[FIN DISCOVERY]"
}

# Fonction  Services

detection_services()
{
    clear
    echo "===== SERVICES DETECTION ====="

    read -p "IP ou domaine : " cible

    if [ -z "$cible" ]; then
        echo "Erreur : cible vide"
        return
    fi

    echo -e "\n[SCAN EN COURS...]\n"

    nmap -sV "$cible" | awk '
    /Nmap scan report/ {print "\n=== HOST :", $5, "==="}
    /Host is up/ {print "[+] Status :", $0}
    /^[0-9]+\/tcp/ {
        printf "PORT: %-8s | STATE: %-7s | SERVICE: %-15s | VERSION: %s\n",
        $1, $2, $3, $4
    }
    /Service Info/ {print "\n[INFO] " $0}
    '

    echo -e "\n[FIN SERVICES]"
}

# Fonction  OS

detection_os()
{
    clear
    echo "===== OS DETECTION ====="

    read -p "IP ou domaine : " cible

    if [ -z "$cible" ]; then
        echo "Erreur : cible vide"
        return
    fi

    echo -e "\n[SCAN EN COURS...]\n"

    sudo nmap -O "$cible" | awk '
    /Nmap scan report/ {print "\n=== HOST :", $5, "==="}
    /Running:/ {print "[+] OS probable :", $0}
    /OS details/ {print "[+] Details OS :", $0}
    /Aggressive OS guesses/ {print "[+] Guess :", $0}
    /Network Distance/ {print "[+] Distance reseau :", $0}
    '

    echo -e "\n[FIN OS DETECTION]"
}

# Fonction  SYN Scan


scan_syn()
{
    clear
    echo "===== SYN SCAN (PORTS) ====="

    read -p "IP ou domaine : " cible

    if [ -z "$cible" ]; then
        echo "Erreur : cible vide"
        return
    fi

    echo -e "\n[SCAN EN COURS...]\n"

    sudo nmap -sS "$cible" | awk '
    /Nmap scan report/ {print "\n=== HOST :", $5, "==="}
    /Host is up/ {print "[+] Status :", $0}
    /^[0-9]+\/tcp/ {
        print "[OPEN PORT] " $1 " | " $2 " | " $3
    }
    '

    echo -e "\n[FIN SYN SCAN]"
}


# Fonction : Menu

menu()
{
    echo "==================================="
    echo "         MENU NMAP"
    echo "==================================="
    echo "1. Decouverte des hotes"
    echo "2. Detection des services"
    echo "3. Detection du systeme"
    echo "4. Scan TCP SYN"
    echo "5. Quitter"
    echo "==================================="
}


# Programme principal

while true
do
    clear
    menu

    read -p "Choix : " choix

    case $choix in

        1)
            decouverte_hotes
            ;;

        2)
            detection_services
            ;;

        3)
            detection_os
            ;;

        4)
            scan_syn
            ;;

        5)
            echo "Fermeture du programme..."
            exit 0
            ;;

        *)
            echo "Erreur : choix invalide."
            ;;
    esac

    echo
    read -p "Appuyer sur Entrée pour continuer..."
done