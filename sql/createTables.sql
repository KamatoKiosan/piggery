CREATE TABLE IF NOT EXISTS category(name TEXT, percentage INTEGER NOT NULL, INTEGER parentId NOT NULL);
CREATE TABLE IF NOT EXISTS piggybank(name TEXT, percentage INTEGER NOT NULL, balanceInCents INTEGER NOT NULL, goalInCents INTEGER NOT NULL, remark TEXT, categoryId INTEGER);
CREATE INDEX IF NOT EXISTS idx_piggybank_categoryId ON piggybank (categoryId);
