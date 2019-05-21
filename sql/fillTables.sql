INSERT INTO category(name, percentage, parentCategoryId)
VALUES
(
    'Root',
    1000,
    NULL
),
(
    'Category 1',
    500,
    1
),
(
    'Category 2',
    500,
    1
);

INSERT INTO piggybank(name, percentage, balanceInCents, goalInCents, remark, categoryId)
VALUES
(
    'Piggybank 11',
    500,
    0,
    100,
    'remark 11',
    2
),
(
    'Piggybank 12',
    500,
    0,
    100,
    'remark 12',
    2
),
(
    'Piggybank 21',
    500,
    0,
    100,
    'remark 21',
    3 
),
(
    'Piggybank 22',
    500,
    0,
    100,
    'remark 22',
    3
);

