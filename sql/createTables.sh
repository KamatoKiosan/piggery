#!/bin/sh
cat createTables.sql | sqlite3 database.db
