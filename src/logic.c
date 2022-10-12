unsigned int boolean_or(unsigned int leftop, unsigned int rightop) {
    return leftop || rightop;
}

unsigned int boolean_and(unsigned int leftop, unsigned int rightop) {
    return leftop && rightop;
}

unsigned int boolean_not(int op) {
    if (op == 1) {
        return 0;
    }
    return 1;
}
