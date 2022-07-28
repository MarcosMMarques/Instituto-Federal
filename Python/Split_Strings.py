if __name__ == '__main__':
    N = int(raw_input())
    vlist=[]
    while N>0:
        command=(raw_input())
        if command.split()[0]=="insert":
            vlist.insert(int(command.split()[1]),int(command.split()[2]))
        elif command.split()[0]=="print":
            print(vlist)
        elif command.split()[0]=="remove":
             vlist.remove(int(command.split()[1]))
        elif command.split()[0]=="append":
            vlist.append(int(command.split()[1]))
        elif command.split()[0]=="sort":
            vlist.sort()
        elif command.split()[0]=="pop":
            vlist.pop()
        elif command.split()[0]=="reverse":
            vlist.reverse()
        N=N-1
