CREATE TABLE IF 
NOT EXISTS repairs
(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    date TEXT NOT NULL,
    ckient TEXT NOT NULL,
    printer_model TEXT NOT NULL,
    diagnostic TEXT,
    parts TEXT,
    sum INTEGER 
);