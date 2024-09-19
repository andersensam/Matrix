/*  ________   ___   __    ______   ______   ______    ______   ______   ___   __    ______   ________   ___ __ __     
 * /_______/\ /__/\ /__/\ /_____/\ /_____/\ /_____/\  /_____/\ /_____/\ /__/\ /__/\ /_____/\ /_______/\ /__//_//_/\    
 * \::: _  \ \\::\_\\  \ \\:::_ \ \\::::_\/_\:::_ \ \ \::::_\/_\::::_\/_\::\_\\  \ \\::::_\/_\::: _  \ \\::\| \| \ \   
 *  \::(_)  \ \\:. `-\  \ \\:\ \ \ \\:\/___/\\:(_) ) )_\:\/___/\\:\/___/\\:. `-\  \ \\:\/___/\\::(_)  \ \\:.      \ \  
 *   \:: __  \ \\:. _    \ \\:\ \ \ \\::___\/_\: __ `\ \\_::._\:\\::___\/_\:. _    \ \\_::._\:\\:: __  \ \\:.\-/\  \ \ 
 *    \:.\ \  \ \\. \`-\  \ \\:\/.:| |\:\____/\\ \ `\ \ \ /____\:\\:\____/\\. \`-\  \ \ /____\:\\:.\ \  \ \\. \  \  \ \
 *     \__\/\__\/ \__\/ \__\/ \____/_/ \_____\/ \_\/ \_\/ \_____\/ \_____\/ \__\/ \__\/ \_____\/ \__\/\__\/ \__\/ \__\/    
 *                                                                                                               
 * Project: Matrix Library in C
 * @author : Samuel Andersen
 * @version: 2024-09-18
 *
 */

#include "tests.h"

#define MATRIX_TYPE_NAME intMatrix
#define MATRIX_TYPE int
#define MATRIX_STRING "%i"
#include "Matrix.c"

#define MATRIX_TYPE_NAME floatMatrix
#define MATRIX_TYPE float
#define MATRIX_STRING "%f"
#include "Matrix.c"

/**
 * Function for testing methods on int Matrix
 */
void test_intMatrix(void) {

    intMatrix* target = intMatrix_allocate(30, 15);

    for (size_t i = 0; i < target->num_rows; ++i) {

        for (size_t j = 0; j < target->num_cols; ++j) {

            target->set(target, i, j, rand());
        }
    }

    printf("Printing int Matrix:\n\n");

    target->print(target);

    printf("Printing row 15 from Matrix:\n\n");

    intMatrix* row = target->get_row(target, 15);
    row->print(row);

    printf("Printing column 10 from Matrix:\n\n");

    intMatrix* col = target->get_col(target, 10);
    col->print(col);

    printf("Printing min and max for the Matrix: %i / %i\n", target->min(target), target->max(target));
    printf("Printing the min and max for the row: %i / %i\n", row->min(row), row->max(row));
    printf("Printing the min and max for the column: %i / %i\n", col->min(col), col->max(col));

    target->clear(target);
    row->clear(row);
    col->clear(col);

    printf("\nStarting dot product test... 3 x 3 (dot) 3 x 2\n");

    intMatrix* first = intMatrix_allocate(3, 3);

    /*
     * Create the following Matrix:
     * 2 3 4
     * 3 4 5
     * 4 5 6 
     */
    for (size_t i = 1; i <= 3; ++i) {

        for (size_t j = 1; j <= 3; ++j) {

            first->set(first, i - 1, j - 1, i + j);
        }
    }

    first->print(first);
    printf("\n");

    intMatrix* second = intMatrix_allocate(3, 2);

    /*
     * Create the following Matrix:
     * 3 4
     * 5 6
     * 7 8 
     */
    for (size_t i = 1; i <= 3; ++i) {

        for (size_t j = 1; j <= 2; ++j) {

            second->set(second, i - 1, j - 1, (i * 2) + j);
        }
    }

    second->print(second);
    printf("\n");

    intMatrix* dot = first->dot(first, second);

    /*
     * We expect the following output:
     * 49 58
     * 64 76
     * 79 94
     */
    dot->print(dot);

    first->clear(first);
    second->clear(second);
    dot->clear(dot);

    printf("\nContinuing dot product test... 1 x 3 (dot) 3 x 1\n");

    intMatrix* third = intMatrix_allocate(1, 3);

    /*
     * Create the following Matrix:
     * 1 2 3
     */
    for (size_t i = 0; i < 3; ++i) {

        third->set(third, 0, i, i + 1);
    }

    third->print(third);
    printf("\n");

    intMatrix* fourth = intMatrix_allocate(3, 1);

    /*
     * Create the following Matrix:
     * 1
     * 2
     * 3
     */

    for (size_t i = 0; i < 3; ++i) {

        fourth->set(fourth, i, 0, i + 1);
    }

    fourth->print(fourth);
    printf("\n");

    dot = third->dot(third, fourth);

    /*
     * We expect the following output:
     * 14
     */
    dot->print(dot);

    third->clear(third);
    fourth->clear(fourth);
    dot->clear(dot);

    printf("\nFinishing dot product test... 2 x 2 (dot) 2 x 2\n");

    intMatrix* fifth = intMatrix_allocate(2, 2);
    intMatrix* sixth = intMatrix_allocate(2, 2);

    for (size_t i = 0; i < 2; ++i) {

        for (size_t j = 0; j < 2; ++j) {

            fifth->set(fifth, i, j, i + j + 1);
            sixth->set(sixth, i, j, (i + j) * 2);
        }
    }

    /*
     * 1 2
     * 2 3
     */
    fifth->print(fifth);
    printf("\n");

    /**
     * 0 2
     * 2 4
     */
    sixth->print(sixth);
    printf("\n");

    dot = fifth->dot(fifth, sixth);
    dot->print(dot);

    fifth->clear(fifth);
    sixth->clear(sixth);
    dot->clear(dot);
}

/**
 * Function for testing methods on float Matrix
 */
void test_floatMatrix(void) {

    floatMatrix* target = floatMatrix_allocate(30, 15);

    float test_val = 0.003145;

    for (size_t i = 0; i < target->num_rows; ++i) {

        for (size_t j = 0; j < target->num_cols; ++j) {

            target->set(target, i, j, ((float)rand()/(float)(RAND_MAX)) * test_val);
        }
    }

    printf("Printing float Matrix:\n\n");

    target->print(target);

    printf("Printing row 15 from Matrix:\n\n");

    floatMatrix* row = target->get_row(target, 15);
    row->print(row);

    printf("Printing column 10 from Matrix:\n\n");

    floatMatrix* col = target->get_col(target, 10);
    col->print(col);

    printf("Printing min and max for the Matrix: %f / %f\n", target->min(target), target->max(target));
    printf("Printing the min and max for the row: %f / %f\n", row->min(row), row->max(row));
    printf("Printing the min and max for the column: %f / %f\n", col->min(col), col->max(col));

    target->clear(target);
    row->clear(row);
    col->clear(col);

    printf("\nStarting dot product test... 3 x 3 (dot) 3 x 2\n");

    floatMatrix* first = floatMatrix_allocate(3, 3);

    /*
     * Create the following Matrix:
     * 2 3 4
     * 3 4 5
     * 4 5 6 
     */
    for (size_t i = 1; i <= 3; ++i) {

        for (size_t j = 1; j <= 3; ++j) {

            first->set(first, i - 1, j - 1, i + j);
        }
    }

    first->print(first);
    printf("\n");

    floatMatrix* second = floatMatrix_allocate(3, 2);

    /*
     * Create the following Matrix:
     * 3 4
     * 5 6
     * 7 8 
     */
    for (size_t i = 1; i <= 3; ++i) {

        for (size_t j = 1; j <= 2; ++j) {

            second->set(second, i - 1, j - 1, (i * 2) + j);
        }
    }

    second->print(second);
    printf("\n");

    floatMatrix* dot = first->dot(first, second);

    /*
     * We expect the following output:
     * 49 58
     * 64 76
     * 79 94
     */
    dot->print(dot);

    first->clear(first);
    second->clear(second);
    dot->clear(dot);

    printf("\nContinuing dot product test... 1 x 3 (dot) 3 x 1\n");

    floatMatrix* third = floatMatrix_allocate(1, 3);

    /*
     * Create the following Matrix:
     * 1 2 3
     */
    for (size_t i = 0; i < 3; ++i) {

        third->set(third, 0, i, i + 1);
    }

    third->print(third);
    printf("\n");

    floatMatrix* fourth = floatMatrix_allocate(3, 1);

    /*
     * Create the following Matrix:
     * 1
     * 2
     * 3
     */

    for (size_t i = 0; i < 3; ++i) {

        fourth->set(fourth, i, 0, i + 1);
    }

    fourth->print(fourth);
    printf("\n");

    dot = third->dot(third, fourth);

    /*
     * We expect the following output:
     * 14
     */
    dot->print(dot);

    third->clear(third);
    fourth->clear(fourth);
    dot->clear(dot);

    printf("\nFinishing dot product test... 2 x 2 (dot) 2 x 2\n");

    floatMatrix* fifth = floatMatrix_allocate(2, 2);
    floatMatrix* sixth = floatMatrix_allocate(2, 2);

    for (size_t i = 0; i < 2; ++i) {

        for (size_t j = 0; j < 2; ++j) {

            fifth->set(fifth, i, j, i + j + 1);
            sixth->set(sixth, i, j, (i + j) * 2);
        }
    }

    /*
     * 1 2
     * 2 3
     */
    fifth->print(fifth);
    printf("\n");

    /**
     * 0 2
     * 2 4
     */
    sixth->print(sixth);
    printf("\n");

    dot = fifth->dot(fifth, sixth);
    dot->print(dot);

    fifth->clear(fifth);
    sixth->clear(sixth);
    dot->clear(dot);
}

int main(void) {

    // Set the random seed used for rand() later on
    srand(time(NULL));

    test_intMatrix();
    test_floatMatrix();

    return 0;
}
