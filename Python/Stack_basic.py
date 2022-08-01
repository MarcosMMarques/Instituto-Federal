from copy import deepcopy


class Stack:
    def __init__(self) -> None:
        self.datas=[]

    def push(self, item) -> None:
        self.datas.append(item)

    def pop(self) -> None:
        try:
            return self.datas.pop()
        except IndexError:
            print('Empty list, pop blocked')

    def peek(self):
        if not self.datas:
            return []

        print(self.datas[-1])
        return self.datas[-1]   

    def __repr__(self) -> None:
        return f'{self.datas}'

    def __iter__(self) -> None:
        self.index = len(self.datas)
        return self
    
    def __next__(self) -> None:
        if self.index == 0:
            raise StopIteration

        self.index -= 1
        return self.datas[self.index]
      

if __name__ == "__main__":
    stack = Stack()
    stack.push('A')
    stack.push(2)
    stack.push('Z')

    print('Peek: ', end="")
    stack.peek()

    copy_stack= deepcopy(stack)
    copy_stack.pop()
    copy_stack.pop()
    copy_stack.pop()
    print('\nPop exception because copy_stack is clean: ', end="");
    
    copy_stack.pop()
    print('\nElements in original Stack:')
    for element in stack:
        print (f'[ {element} ]')
