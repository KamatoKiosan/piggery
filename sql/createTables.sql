CREATE TABLE IF NOT EXISTS category(rowid INTEGER PRIMARY KEY, name TEXT, percentage INTEGER NOT NULL, parentCategoryId INTEGER);
CREATE TABLE IF NOT EXISTS piggybank(rowid INTEGER PRIMARY KEY, name TEXT, percentage INTEGER NOT NULL, balanceInCents INTEGER NOT NULL, goalInCents INTEGER NOT NULL, remark TEXT, categoryId INTEGER);
CREATE INDEX IF NOT EXISTS idx_piggybank_categoryId ON piggybank (categoryId);
