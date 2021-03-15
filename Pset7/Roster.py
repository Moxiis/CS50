# TODO
import sys
from cs50 import SQL

if len(sys.argv) != 2:
    print("wrong number of arguments")
    quit(1)

db = SQL("sqlite:///students.db")
database = db.execute("SELECT first,middle,last,house,birth FROM students WHERE house = ? ORDER BY last, first;", sys.argv[1])

for i in database:
    print(i["first"], end = " ")
    if i["middle"] != None:
        print(i["middle"], end = " ")
    print(i["last"] + ", born " + str(i["birth"]))
