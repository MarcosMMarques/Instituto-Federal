import os
import math
import random
import re
import sys


if __name__ == '__main__':
    number = int(input().strip())
    if number%2 != 0:
        print("Weird")
    elif number>=2 and number<=5:
        print("Not Weird")
    elif number>=6 and number<=20:
        print("Weird")
    else:
        print("Not Weird")
