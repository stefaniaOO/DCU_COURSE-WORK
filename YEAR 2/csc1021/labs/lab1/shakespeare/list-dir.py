import os, sys

path = '.' #current working directory

if len(sys.argv) == 2: #check if argv has dir 
    path = sys.argv[1] #change current path to argv 1

files = os.listdir(path) #list con tutti file presenti in file 

for n in files:
    full_path = os.path.join(path, n) #function gives string that is path to file
    #print(full_path) print path of every file


#An inode is a file data structure that stores information about any Linux file except its name and data. 


    inode = os.stat(full_path) #os.stat returns info about file

    if os.path.isdir(full_path): #function that returns bool, check if parameter in brackets is dir
      print('name:',n,'type: directory\n')
    elif os.path.isfile(full_path): #function check if parameter is file
      size = str(os.path.getsize(full_path)) #get size of file
      print('name: ',n,' type: file  file size:',size,'\n')
    else:
      print('Not a file or directory - what else could it be?')