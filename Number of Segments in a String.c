int countSegments(char* s) {
    int res = 0;
    char* p = strtok(s, " ");
    while (p) {
        res++;
        p = strtok(NULL, " ");
    }
    return res;
}