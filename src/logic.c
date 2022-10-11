unsigned int boolean_or(int leftop, int rightop, unsigned int* values) {
    return values[leftop] || values[rightop];
}

unsigned int boolean_and(int leftop, int rightop, unsigned int* values) {
    return values[leftop] && values[rightop];
}

unsigned int boolean_not(int op, unsigned int* values) {
    switch (values[leftop]) {
        case 0:
            return 1;
        case 1:
            return 0;
    }
}

unsigned int boolean_xor(int leftop, int rightop, unsigned int* value) {
    return boolean_and(boolean_or(leftop, rightop, values) 
