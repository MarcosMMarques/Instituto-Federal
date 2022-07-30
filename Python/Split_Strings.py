if __name__ == '__main__':
    number = int(raw_input())
    values_list = []
    while number > 0:
        command = (raw_input())
        if command.split()[0] == "insert":
            values_list.insert(int(command.split()[1]), int(command.split()[2]))
        elif command.split()[0] == "print":
            print(value_list)
        elif command.split()[0] == "remove":
             value_list.remove(int(command.split()[1]))
        elif command.split()[0] == "append":
            value_list.append(int(command.split()[1]))
        elif command.split()[0] == "sort":
            value_list.sort()
        elif command.split()[0] == "pop":
            value_list.pop()
        elif command.split()[0] == "reverse":
            value_list.reverse()
        number = number - 1
