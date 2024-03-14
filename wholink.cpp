#include <iostream>
#include <Windows.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <source_file> <target_file>" << std::endl;
        return 1;
    }

    LPCSTR source = argv[1];
    LPCSTR target = argv[2];
    LPCWSTR symlink = L"my_symlink";

    if (CreateSymbolicLinkA(symlink, source, SYMBOLIC_LINK_FLAG_FILE) != 0) {
        std::wcout << L"Symbolic link created successfully." << std::endl;
    }
    else {
        std::wcerr << L"Failed to create symbolic link. Error code: " << GetLastError() << std::endl;
        return 1;
    }

    return 0;
}
