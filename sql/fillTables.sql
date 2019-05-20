INSERT INTO category(name, percentage, parentCategoryId)
VALUES
(
    'Root',
    100,
    NULL
),
(
    'Category 1',
    50,
    1
),
(
    'Category 2',
    50,
    1
);

INSERT INTO piggybank(name, percentage, balanceInCents, goalInCents, remark, categoryId)
VALUES
(
    'Piggybank 11',
    50,
    0,
    100,
    'remark 11',
    2
),
(
    'Piggybank 12',
    50,
    0,
    100,
    'remark 12',
    2
),
(
    'Piggybank 21',
    50,
    0,
    100,
    'remark 21',
    3 
),
(
    'Piggybank 22',
    50,
    0,
    100,
    'remark 22',
    3
);

