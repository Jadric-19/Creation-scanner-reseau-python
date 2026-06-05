from tkinter import *
from tkinter import ttk

import Scanneur

def valider() :
    if(choixCombo.get() == "Host discovery") :
        ip = ipEntry.get()
        message = " Resultat : \n" + str(scan.decouverte_hostes(ip))
        resultLabel.config(text=message, justify="left", anchor="w")
    
    elif(choixCombo.get() == "Service scan") :
        ip = ipEntry.get()
        message = " Resultat : \n" + str(scan.detection_services(ip))
        #resultLabel.config(text=message)
        resultLabel.config(text=message, justify="left", anchor="w")

    
    elif(choixCombo.get() == "OS detection") :
        ip = ipEntry.get()
        message = " Resultat : \n" + str(scan.detection_os(ip))
        resultLabel.config(text=message, justify="left", anchor="nw", wraplength=740)
    
    
    elif(choixCombo.get() == "SYN scan") :
        ip = ipEntry.get()
        message = " Resultat : \n" + str(scan.scan_syn(ip))
        resultLabel.config(text=message, justify="left", anchor="w")
    
    else :
        message = " Resultat : Choix invalide \n"
        resultLabel.config(text=message, justify="left", anchor="w")


def reinit() :
    ipEntry.delete(0,END)
    choixCombo.delete(0,END)


mainwindow = Tk()
mainwindow.title("Nmap")
mainwindow.geometry("800x800+500+200")

scan = Scanneur.Scanneur("")

# Creation de l'input
ipLabel = Label(mainwindow , text="Entrer l'ip : " , font=("Arial" , 15 , 'bold') )
ipLabel.grid(row=1 , column=1 , sticky="E" , padx=15 , pady=15)

ipEntry = Entry(mainwindow, width=30)
ipEntry.grid(row=1 , column=2 , pady=15 )

choixLabel = Label(mainwindow , text="Option de Scan : " , font=("Arial" , 15 , 'bold'))
choixLabel.grid(row=3 , column=2 , columnspan=1 , sticky="E" , pady=15)

choixCombo = ttk.Combobox(mainwindow , value=[ "Host discovery" , "Service scan" , "OS detection" , "SYN scan"])
choixCombo.grid(row=3 , column=3 , pady=15)

# Creation Button
btnResult = Button(mainwindow , text="Scan" , command=valider , width=4 , height=2)
btnResult.grid(row=5 , column=1)

btnReinit = Button(mainwindow , text="Reinit" , command=reinit , width=4 , height=2)
btnReinit.grid(row=5 , column=2)

btnQuit = Button(mainwindow , text="Quit" , command=mainwindow.quit , width=4 , height=2)
btnQuit.grid(row=5 , column=3)

# Creation de Frame


resultFrame = Frame(mainwindow , bg="#1a8cff")
resultFrame.place(x=20 , y=200 , width=760 , height=580)

resultLabel = Label(resultFrame , text="" , bg="#1a8cff")
resultLabel.grid(row=1 , column=1 , padx=10 , pady=10)



mainwindow.mainloop()