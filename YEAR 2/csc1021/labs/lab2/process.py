from multiprocessing import *

def Hi(n):
    print("Hi", n, "from process", current_process().name,current_process().pid)
    



def greetings():
    name = input("plese insert a name: ")
    num_proc = int(input("how many process d you want to create?: "))

    for i in range(num_proc):
        p = Process(target=Hi, args=(name,),name=str(i)).start()



greetings()
