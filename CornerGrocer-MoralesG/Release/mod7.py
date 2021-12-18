import re
import string
import matplotlib.pyplot as plt



def printsomething():
    items = {}
    dataFile = open("C:\\Users\\gigim\\Desktop\\cornergrocerfile.txt")
    for line in dataFile:
        if line.strip() in items:
            items[line.strip()] += 1
        else:
            items[line.strip()] = 1


    for key, val in items.items():
        print(key, val)

    return 0

def PrintMe(v):
    v = v.title()
    itemCount = 0
    dataFile = open("C:\\Users\\gigim\\Desktop\\cornergrocerfile.txt")
    for line in dataFile:
        if line.strip() == v:
            itemCount += 1

    print(v, ":", itemCount)

    return 0

def SquareValue(v):
    return v * v

