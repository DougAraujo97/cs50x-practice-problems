CREATE TABLE students (
    id INTEGER NOT NULL,
    student_name TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE houses (
    id INTEGER NOT NULL,
    house_name TEXT UNIQUE,
    house_head TEXT UNIQUE,
    PRIMARY KEY(id)
);

CREATE TABLE house_assignments (
    id INTEGER NOT NULL,
    student_id INTEGER,
    house_id INTEGER,
    PRIMARY KEY(id),
    FOREIGN KEY(student_id) REFERENCES students(id),
    FOREIGN KEY(house_id) REFERENCES houses(id)
);