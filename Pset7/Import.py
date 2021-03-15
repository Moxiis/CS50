# TODO
import sys
import csv
from cs50 import SQL

if len(sys.argv) != 2:
    print("incorrect number of arguments")
    quit (1)
    
db = SQL("sqlite:///students.db")
with open(sys.argv[1]) as file:
    data = csv.DictReader(file)
    for row in data:
        if row["name"]:
            if len(row['name'].split()) == 3:
                for count, i in enumerate (row["name"].split()):
                    if count == 0:
                        db.execute("INSERT INTO students(first) VALUES(?);", i)
                        first_name = i
                    if count == 1:
                        db.execute("UPDATE students SET middle = ? WHERE students.first = ?;", i, first_name)
                    if count == 2:
                        db.execute("UPDATE students SET last = ? WHERE students.first = ?;", i, first_name)
            else:
                for count, i in enumerate (row["name"].split()):
                    if count == 0:
                        db.execute("INSERT INTO students(first) VALUES(?);", i)
                        first_name = i
                    if count == 1:
                        db.execute("UPDATE students SET last = ? WHERE students.first = ?;", i, first_name)
                db.execute("UPDATE students SET middle = NULL WHERE students.first = ?;", first_name)
        if row["house"]:
            db.execute("UPDATE students SET house = ? WHERE students.first = ?;", row['house'], first_name)
        if row["birth"]:
            db.execute("UPDATE students SET birth = ? WHERE students.first = ?;", row['birth'], first_name)


