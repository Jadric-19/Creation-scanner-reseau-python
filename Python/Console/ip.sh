import subprocess
import io

class Scanneur :
     def __init__(self , ip) :
        self.ip = ip 
    
     def executeur(self , cmd) :
         result = subprocess.Popen(cmd , stdout=subprocess.PIPE , stderr=subprocess.PIPE  , text=True)
         return result.communicate()
     
     def decouverte_hostes(self , ip) :
         cmd = ["nmap" , "-sn" , ip]
         
         stdout , stderr = self.executeur(cmd)
         
         result = self.format_sn(stdout)

         return result
    
     def detection_os(self , ip) :
         cmd  = ["nmap" , "-O" , ip]
         
         stdout , stderr = self.executeur(cmd)
         result = self.format_os(stdout)

         return result

     def detection_services(self , ip) :
         cmd = ["nmap" , "-sV" , ip]

         stdout , stderr = self.executeur(cmd)
         result = self.format_sv(stdout)

         return result

     def scan_syn(self , ip) :
         cmd = ["nmap" , "-sS" , ip]
         
         stdout , stderr = self.executeur(cmd)
         result = self.format_syn(stdout)

         return result
     
     def format_sn(self, tokene) :

         result = ""

         for line in tokene.splitlines() :

             if "Nmap scan report for" in line:
                 result += "[HOST]  " + line + "\n"

             elif "Host is up" in line:
                 result += "     └─> " + line + "\n\n"

         return result

     def format_sv(self,tokene) :
         format = io.StringIO(tokene)
         
         result = ""
         
         for line in format :
             if "/tcp" in line or "/udp" in line :
                 result += "[SERVICE]" + line + "\n"
             
             if "Service detection performed" in line :
                 result += "\n[Info] " + line + "\n"
         
         return result
    
     def format_os(self , tokene) :
         format = io.StringIO(tokene)
        
         result = "" 

         for line in format :
             if "Aggressive OS guesses" in line  or "Running" in line or "OS details" in line : 
                 result += "[OS] " + line + "\n"
        
         return result

     def format_syn(self , tokene) :
         format = io.StringIO(tokene)

         result  = " "

         for line in format :
             if ("open" in line and "/tcp" in line) :
                 result += "[OPEN PORT]" + line + "\n"
             if("close" in line and "/tcp" in line) :
                 result += "[CLOSE PORT]" + line + "\n"
             if("Not shown" in line) :
                 result += "[INFO]" + line + "\n"

         return result 

    



         

if __name__ ==  "__main__"  :
   
     scan = Scanneur("")
     ip = input(" Entrer l'ip : ")
     
     print("1---------------------------------------------------\n\n\n")

     result = ""
     result = scan.decouverte_hostes(ip)

     print(result)

     print("2---------------------------------------------------\n\n\n")
     result = ""
     result = scan.detection_os(ip)

     print("\n",result)

     print("3---------------------------------------------------\n\n\n")

     result = ""
     result = scan.detection_services(ip)

     print("\n" ,result)

     print("4---------------------------------------------------\n\n\n")
     
     result = ""
     result = scan.scan_syn(ip)

     print("\n" ,result)
      