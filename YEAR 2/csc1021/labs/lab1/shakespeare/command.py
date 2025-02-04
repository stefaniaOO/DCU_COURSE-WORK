from cmd import Cmd #line oriented command line interpreters
import os, sys

class MyPrompt(Cmd): #nuova classe my prop che acetta cmd objects/instances cmd 

    def do_hello(self, name): #function that prints hello + name


        
        """Says hello. If you provide a name, it will greet you with it."""     #python docstrings, for documentation purpose get printed when function is called 
        if len(name) == 0:
            name = 'stranger'
    
        print ("Hello, %s" % name)



    def do_quit(self, args): #do_ is a not just a convenction (tells python that this is command)
        """Quits the program."""
        print("Quitting.")
        raise SystemExit

    def do_list(self,path):

        """List content of current directory. give name if dir or file and file size"""
        if len(path) == 0:
            path = "."
        files = os.listdir(path)

        for n in files:
            full_path = os.path.join(path, n) 
            inode = os.stat(full_path) 
            if os.path.isdir(full_path): 
                print('name:',n,'type: directory\n')
            elif os.path.isfile(full_path): 
                size = str(os.path.getsize(full_path)) #get size of file
                print('name: ',n,' type: file  file size:',size,'\n')
            else:
                print('Not a file or directory - what else could it be?')




if __name__ == '__main__':  #execute this only when u type fromcmd line or python3 or ecc 
    prompt = MyPrompt()
    prompt.prompt = '> '
    prompt.cmdloop('Starting prompt...')






#Documented commands (type help <topic>):
#========================================
#hello (una delle funzioni che abbiamo creato)  help(give list of function created and how to use them)  quit(altra funzione creata)

#hello -> hello, stranger;  hello stefania -> hello, stefania
#quit -> quitting
#help hello -> prints docstrings

#All subclasses of Cmd inherit a predefined do_help()
#An interpreter instance will recognize a command name quit if and only if it has a method do_quit()

