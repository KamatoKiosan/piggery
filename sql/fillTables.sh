#!/bin/sh
cat fillTables.sql | sqlite3 database.db
