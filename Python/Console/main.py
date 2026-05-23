import Scanneur 
import os

def menu() : 
     print("\n\n================  MENU =================\n\n")
     print("1. Host discovery\n")
     print("2. Service scan\n")
     print("3. OS detection\n")
     print("4. SYN scan\n")
     print("0. Quitter\n")

def clear() :
     os.system("clear")

if __name__ == "__main__" :

     scan = Scanneur.Scanneur("") 

     while(True) :
         menu()
         choix = input("Choix : ")

         if choix == "1":

             print("\n\n---------------  HOST DISCOVERY  ----------------------\n\n")
             ip = input("Entrer l'ip : ")
             print("Traitement...")
             result = scan.decouverte_hostes(ip)
             print("\n",result)
             print("\n---------------------------------------\n\n")
             input("Entrer....")
             clear()
         
         elif choix == "2" :

             print("\n\n----------------  SERVICE SCAN  ----------------------\n\n")
             ip = input("Entrer l'ip : ")
             print("Traitement...")
             result = scan.detection_services(ip)
             print("\n",result)  
             
             print("\n-------------------    ---------------------\n\n")

             input("Entrer....")
             clear()

         elif choix == "3" :

             print("\n\n------------------  OS DETECTION   ---------------------\n\n")
             ip = input("Entrer l'ip : ")
             print("Traitement...")
             result = scan.detection_os(ip)
             print("\n",result)
             
             print("\n-----------------  ----------------------\n")

             input("Entrer....")
             clear()

         elif choix == "4" :
             print("\n\n----------------  SYN SCAN  --------------------\n\n")
             ip = input("Entrer l'ip : ")
             print("Traitement...")
             result = scan.scan_syn(ip)
             
             
             print("\n",result)
             print("\n----------------   -----------------------\n\n")
            
             input("Entrer....")
             clear()

         elif choix == "0" :
             print("\n--- Merci Pour votre utilisation ---\n")
             exit()

         else :
             print("\n\n----------------  ERREUR DE CHOIX   -----------------------\n\n")
             print("\nChoix invalide\n")
             print("\n---------------------------------------\n\n")
             input("Entrer....")
             clear()

            
