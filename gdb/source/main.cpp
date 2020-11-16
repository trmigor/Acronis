// "Copyright [2020] <Taraymovich Igor>"
void func_1(char* pointer) {
    *pointer = 2;
}

void func_2() {
    char* pointer = nullptr;
    func_1(pointer);
}

int main(void) {
    func_2();
    return 0;
}
