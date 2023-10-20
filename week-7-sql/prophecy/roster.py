from cs50 import SQL

from csv import DictReader

db = SQL("sqlite:///roster.db")
students = []
houses = {}
relationships = {}

with open("students.csv", "r") as file:
    reader = DictReader(file)

    for row in reader:
        student = row["student_name"]
        house = row["house"]
        head = row["head"]

        students.append(student)
        houses[house] = head
        relationships[student] = house

for student in students:
    db.execute("INSERT INTO students(student_name) VALUES(?)", student)

for house in houses:
    db.execute("INSERT INTO houses(house_name, house_head) VALUES(?, ?)", house, houses[house])

for relationship in relationships:
    student = db.execute("SELECT id FROM students WHERE student_name = ?", relationship)
    house = db.execute("SELECT id FROM houses WHERE house_name = ?", relationships[relationship])
    db.execute("INSERT INTO house_assignments(student_id, house_id) VALUES(?, ?)", student[0]["id"], house[0]["id"])

# since db.execute returns a list of dictionaries, you have to select the first item in the list, and then the "id" in the dictionary to just get the id number
